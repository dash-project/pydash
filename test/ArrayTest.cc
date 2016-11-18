#include <libdash.h>
#include <gtest/gtest.h>
#include "TestBase.h"
#include "ArrayTest.h"

// global var
CArray<int> array_global = cdash__array__new(/**/);

TEST_F(ArrayTest, Allocation)
{
  CArray<int> array_local = cdash__array__new(/**/);

  DASH_LOG_DEBUG("Delayed allocate");
  array_global.allocate(19 * cdash__team__size(), dash::BLOCKED);
  array_local.allocate(19 * cdash__team__size(), dash::BLOCKED);
}

TEST_F(ArrayTest, SingleWriteMultipleRead)
{
  typedef int                                         value_t;
  typedef typename dash::Array<value_t>::pattern_type pattern_t;

  size_t array_size = _num_elem * _dash_size;
  // Create array instances using varying constructor options
  LOG_MESSAGE("Array size: %d", array_size);
  try {
    // Initialize arrays
    LOG_MESSAGE("Initialize arr1");

    CArray<value_t> arr1 = cdash__array__new(array_size);
    LOG_MESSAGE("Initialize arr2");
    CArray<value_t> arr2 = cdash__array__new(array_size,
                                             dash::BLOCKED);
    LOG_MESSAGE("Initialize arr3");
    CArray<value_t> arr3 = cdash__array__new(array_size,
                                             cdash__team_All());
    LOG_MESSAGE("Initialize arr4");
    CArray<value_t> arr4 = cdash__array__new(array_size,
                                             dash::CYCLIC,
                                             cdash__team__All());
    LOG_MESSAGE("Initialize arr5");
    CArray<value_t> arr5 = cdash__array__new(array_size,
                                             dash::BLOCKCYCLIC(12));
    LOG_MESSAGE("Initialize arr6");
    pattern_t pat(array_size);
    CArray<value_t> arr6 = cdash__array__new(pat);

    // Check array sizes
    ASSERT_EQ(array_size, cdash__array__size(arr1));
    ASSERT_EQ(array_size, cdash__array__size(arr2));
    ASSERT_EQ(array_size, cdash__array__size(arr3));
    ASSERT_EQ(array_size, cdash__array__size(arr4));
    ASSERT_EQ(array_size, cdash__array__size(arr5));
    ASSERT_EQ(array_size, cdash__array__size(arr6));
    // Fill arrays with incrementing values
    if(_dash_id == 0) {
      LOG_MESSAGE("Assigning array values");
      for(size_t i = 0; i < array_size; ++i) {
        cdash__array__random_access(arr1, i) = i;
        cdash__array__random_access(arr2, i) = i;
        cdash__array__random_access(arr3, i) = i;
        cdash__array__random_access(arr4, i) = i;
        cdash__array__random_access(arr5, i) = i;
        cdash__array__random_access(arr6, i) = i;
      }
    }
    // Units waiting for value initialization
    cdash__team__barrier();
    // Read and assert values in arrays
    for(size_t i = 0; i < array_size; ++i) {
      ASSERT_EQ_U(i, static_cast<value_t>cdash__array__random_access(arr1,i));
      ASSERT_EQ_U(i, static_cast<value_t>cdash__array__random_access(arr2,i));
      ASSERT_EQ_U(i, static_cast<value_t>cdash__array__random_access(arr3,i));
      ASSERT_EQ_U(i, static_cast<value_t>cdash__array__random_access(arr4,i));
      ASSERT_EQ_U(i, static_cast<value_t>cdash__array__random_access(arr5,i));
      ASSERT_EQ_U(i, static_cast<value_t>cdash__array__random_access(arr6,i));
    }
  } catch (dash::exception::InvalidArgument & ia) {
    LOG_MESSAGE("ERROR: %s", ia.what());
    ASSERT_FAIL();
  }
}

TEST_F(ArrayTest, TileSize)
{
  typedef int                                            value_t;
  typedef long long                                      index_t;
  typedef dash::TilePattern<1, dash::ROW_MAJOR, index_t> pattern_t;
  typedef dash::Array<value_t, index_t, pattern_t>       array_t;

  size_t nunits          = dash::Team::All().size();
  size_t tilesize        = 1024;
  size_t blocks_per_unit = 3;
  size_t size            = nunits * tilesize * blocks_per_unit;

  array_t arr(size, dash::TILE(tilesize));

  ASSERT_EQ_U(arr.pattern().blocksize(0),
              arr.pattern().block(0).extent(0));

  auto block_0         = arr.pattern().local_block(0);
  auto block_1         = arr.pattern().local_block(1);

  auto block_0_gend    = block_0.offset(0) + block_0.extent(0);
  auto block_1_gbegin  = block_1.offset(0);

  auto block_glob_dist = block_1_gbegin - block_0_gend;

  // Blocked distribution, expect (nunits-1) blocks between to local blocks.
  EXPECT_EQ_U(tilesize * (nunits - 1),
              block_glob_dist);
}

TEST_F(ArrayTest, PatternAllocate)
{
  typedef dash::default_index_t                        index_t;
  typedef dash::Pattern<1, dash::ROW_MAJOR, index_t> pattern_t;
  const size_t size     = 115;
  const size_t tilesize = 10;
  dash::Array<int, index_t, pattern_t> array;

  // Fill
  std::function< void(const int &, index_t)>
  fill = [&array](int el, index_t i) {
    auto coords = array.pattern().coords(i);
    array[i] = coords[0];
  };

  // Verify
  std::function< void(const int &, index_t)>
    verify = [&array](int el, index_t i) {
      auto coords  = array.pattern().coords(i);
      auto desired = coords[0];
      ASSERT_EQ_U(
        desired,
        el);
    };

  {
    const pattern_t pattern(
       dash::SizeSpec<1>(size),
       dash::DistributionSpec<1>(dash::TILE(tilesize)),
       dash::TeamSpec<1>(),
       dash::Team::All());

    array.allocate(pattern);
  }

  // Fill
  dash::for_each_with_index(
    array.begin(),
    array.end(),
    fill);

  dash::for_each_with_index(
    array.begin(),
    array.end(),
    verify);
}

TEST_F(ArrayTest, ConstructorNelemInitializer_list)
{
  DASH_LOG_TRACE("AralllArray(nglobal,lvals,team) >",
		 "TESTTESTTESTfinished delegating constructor");
  dash::Array<int> target (4, {0,1,2,3});
  
  if(dash::myid() == 0) {
    ASSERT_EQ_U(target[0], 0);
    ASSERT_EQ_U(target[1], 1);
    ASSERT_EQ_U(target[2], 2);    
    ASSERT_EQ_U(target[3], 3);   
  }  
}

