#ifndef DASH__TEST__ARRAY_TEST_H_
#define DASH__TEST__ARRAY_TEST_H_

#include <gtest/gtest.h>
#include <libdash.h>

#include "TestBase.h"

/**
 *  This class tests the C wrappings  of dash::array's member functions and
 *  methods which can may be found in pydash/cdash/src/Array.cc
 *
 */

class ArrayTest : public ::testing::Test {
protected:
  size_t _dash_id;
  size_t _dash_size;
  int    _num_elem;

  ArrayTest()
  : _dash_id(0),
    _dash_size(0),
    _num_elem(0)
  {
    LOG_MESSAGE(">>> Test suite: C-Wrappings of dash::array");
  }

  virtual ~ArrayTest()
  {
    LOG_MESSAGE("<<< Closing test suite: ArrayTest");
  }

  virtual void SetUp()
  {
    _dash_id   = dash::myid();
    _dash_size = dash::size();
    _num_elem  = 100;
    LOG_MESSAGE("===> Running test case with %d units ...",
                _dash_size);
  }

  virtual void TearDown()
  {
    dash::Team::All().barrier();
    LOG_MESSAGE("<=== Finished test case with %d units",
                _dash_size);
  }
};

#endif // DASH__TEST__ARRAY_TEST_H_
