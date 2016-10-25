#ifndef PYDASH__ARRAY_H_INCLUDED
#ifndef PYDASH__ARRAY_H_INCLUDED

#include <dash/GlobMem.h>
#include <dash/GlobRef.h>
#include <dash/GlobAsyncRef.h>
#include <dash/Types.h>
#include <dash/Team.h>
#include <dash/Pattern.h>
#include <dash/HView.h>
#include <dash/Shared.h>
#include <dash/Exception.h>
#include <dash/Cartesian.h>
#include <dash/Dimensional.h>

#include <dash/iterator/GlobIter.h>

#include <iterator>
#include <initializer_list>
#include <type_traits>

/*
 * LocalArrayRef (declared inside Array.h)
 *
 */
CLocalArrayRef cdash__array__LocalArrayRef_init(CArray array);
CLocalArrayRef cdash__array__LocalArrayRef_delete(CArray array);

const_pointer cdash__array__LocalArrayRef_begin(CLocalArrayRef larray);
pointer       cdash__array__LocalArrayRef_begin(CLocalArrayRef larray);

const_pointer cdash__array__LocalArrayRef_end(CLocalArrayRef larray);
pointer       cdash__array__LocalArrayRef_end(CLocalArrayRef larray);

size_type     cdash__array__LocalArrayRef_size(CLocalArrayRef larray);

value_type    cdash__array__LocalArrayRef_random_access(size_t n);
reference     cdash__array__LocalArrayRef_random_access(size_t n);

bool          cdash__array__LocalArrayRef_is_local(index_type global_index);

self_t        cdash__array__LocalArrayRef_block(index_type block_lindex);
PatternType & cdash__array__LocalArrayRef_pattern();


/*
 * AsyncArrayRef (declared inside Array.h)
 *
 */
CAsyncArrayRef        cdash__array__AsyncArrayRef_init(CArray array);
void                  cdash__array__AsyncArrayRef_delete();

const_pointer         cdash__array__AsyncArrayRef_begin(CLocalArrayRef larray);
pointer               cdash__array__AsyncArrayRef_begin(CLocalArrayRef larray);

const_pointer         cdash__array__AsyncArrayRef_end(CLocalArrayRef larray);
pointer               cdash__array__AsyncArrayRef_end(CLocalArrayRef larray);

size_type             cdash__array__AsyncArrayRef_size(CLocalArrayRef larray);

const_async_reference cdash__array__AsyncArrayRef_random_access(size_t n);
async_reference       cdash__array__AsyncArrayRef_random_access(size_t n);

void                  cdash__array__AsyncArrayRef_flush();
void                  cdash__array__AsyncArrayRef_flush_local();
void                  cdash__array__AsyncArrayRef_flush_all();
void                  cdash__array__AsyncArrayRef_flush_local_all();
void                  cdash__array__AsyncArrayRef_push();
void                  cdash__array__AsyncArrayRef_fetch();

/*
 * ArrayRef (declared inside Array.h)
 *
 */
CArrayRef            cdash__array__ArrayRef_init(CArray array);
void                 cdash__array__ArrayRef_delete();
Team              &  cdash__array__ArrayRef_team();
size_type            cdash__array__ArrayRef_size();
size_type            cdash__array__ArrayRef_local_size();
size_type            cdash__array__ArrayRef_local_capacity();
size_type            cdash__array__ArrayRef_extent(dim_t dim);
Extents_t            cdash__array__ArrayRef_extents();
bool                 cdash__array__ArrayRef_empty();
void                 cdash__array__ArrayRef_barrier();
const_pointer        cdash__array__ArrayRef_data();
iterator             cdash__array__ArrayRef_begin();
const_iterator       cdash__array__ArrayRef_begin();
iterator             cdash__array__ArrayRef_end();
const_iterator       cdash__array__ArrayRef_end();
local_type           cdash__array__ArrayRef_sub_local();
ElementType       *  cdash__array__ArrayRef_lbegin();
ElementType       *  cdash__array__ArrayRef_lend();
reference            cdash__array__ArrayRef_random_access(size_type global_index);
const_reference      cdash__array__ArrayRef_random_access(size_type global_index);
reference            cdash__array__ArrayRef_at();
const_reference      cdash__array__ArrayRef_at();
PatternType &        cdash__array__ArrayRef_pattern();
          
          
/*
 * A distributed array.
 */

local_type  cdash__array_local;
async_type  cdash__array_async;

CArray cdash__array__new(/*param list*/);
void   cdash__array__delete(CArray _this);

/* TO BE CLEANT @JosefSchaeffer
  ~Array()
  {
    DASH_LOG_TRACE_VAR("Array.~Array()", this);
    deallocate();
    DASH_LOG_TRACE_VAR("Array.~Array >", this);
  }

  /**
   * View at block at given global block offset.
   */
  View block(index_type block_gindex)
  {
    DASH_LOG_TRACE("Array.block()", block_gindex);
    ViewSpec<1> block_view = pattern().block(block_gindex);
    DASH_LOG_TRACE("Array.block >", block_view);
    return View(this, block_view);
  }

  /**
   * Global const pointer to the beginning of the array.
   */
  const_pointer data() const noexcept
  {
    return m_begin;
  }

  /**
   * Global pointer to the beginning of the array.
   */
  iterator begin() noexcept
  {
    return m_begin;
  }

  /**
   * Global pointer to the beginning of the array.
   */
  const_iterator begin() const noexcept
  {
    return m_begin;
  }

  /**
   * Global pointer to the end of the array.
   */
  iterator end() noexcept
  {
    return m_end;
  }

  /**
   * Global pointer to the end of the array.
   */
  const_iterator end() const noexcept
  {
    return m_end;
  }

  /**
   * Native pointer to the first local element in the array.
   */
  ElementType * lbegin() const noexcept
  {
    return m_lbegin;
  }

  /**
   * Native pointer to the end of the array.
   */
  ElementType * lend() const noexcept
  {
    return m_lend;
  }

  /**
   * Subscript assignment operator, not range-checked.
   *
   * \return  A global reference to the element in the array at the given
   *          index.
   */
  reference operator[](
    /// The position of the element to return
    size_type global_index)
  {
    DASH_LOG_TRACE_VAR("Array.[]=()", global_index);
    auto global_ref = m_begin[global_index];
    DASH_LOG_TRACE_VAR("Array.[]= >", global_ref);
    return global_ref;
  }

  /**
   * Subscript operator, not range-checked.
   *
   * \return  A global reference to the element in the array at the given
   *          index.
   */
  const_reference operator[](
    /// The position of the element to return
    size_type global_index) const
  {
    DASH_LOG_TRACE_VAR("Array.[]()", global_index);
    auto global_ref = m_begin[global_index];
    DASH_LOG_TRACE_VAR("Array.[] >", global_ref);
    return global_ref;
  }

  /**
   * Random access assignment operator, range-checked.
   *
   * \see operator[]
   *
   * \return  A global reference to the element in the array at the given
   *          index.
   */
  reference at(
    /// The position of the element to return
    size_type global_pos)
  {
    if (global_pos >= size())  {
      DASH_THROW(
          dash::exception::OutOfRange,
          "Position " << global_pos
          << " is out of range " << size()
          << " in Array.at()" );
    }
    return m_begin[global_pos];
  }

  /**
   * Random access operator, range-checked.
   *
   * \see operator[]
   *
   * \return  A global reference to the element in the array at the given
   *          index.
   */
  const_reference at(
    /// The position of the element to return
    size_type global_pos) const
  {
    if (global_pos >= size())  {
      DASH_THROW(
          dash::exception::OutOfRange,
          "Position " << global_pos
          << " is out of range " << size()
          << " in Array.at()" );
    }
    return m_begin[global_pos];
  }

  /**
   * The size of the array.
   *
   * \return  The number of elements in the array.
   */
  inline size_type size() const noexcept
  {
    return m_size;
  }

  /**
   * The number of elements that can be held in currently allocated storage
   * of the array.
   *
   * \return  The number of elements in the array.
   */
  inline size_type capacity() const noexcept
  {
    return m_size;
  }

  /**
   * The team containing all units accessing this array.
   *
   * \return  The instance of Team that this array has been instantiated
   *          with
   */
  inline const Team & team() const noexcept
  {
    return *m_team;
  }

  /**
   * The number of elements in the local part of the array.
   *
   * \return  The number of elements in the array that are local to the
   *          calling unit.
   */
  inline size_type lsize() const noexcept
  {
    return m_lsize;
  }

  /**
   * The capacity of the local part of the array.
   *
   * \return  The number of allocated elements in the array that are local
   *          to the calling unit.
   */
  inline size_type lcapacity() const noexcept
  {
    return m_lcapacity;
  }

  /**
   * Checks whether the array is empty.
   *
   * \return  True if \c size() is 0, otherwise false
   */
  inline bool empty() const noexcept
  {
    return size() == 0;
  }

  inline View local_in(dash::util::Locality::Scope scope)
  {
    return View(); // TODO
  }

  /**
   * Checks whether the given global index is local to the calling unit.
   *
   * \return  True if the array element referenced by the index is held
   *          in the calling unit's local memory
   */
  bool is_local(
    /// A global array index
    index_type global_index) const
  {
    return m_pattern.is_local(global_index, m_myid);
  }

  /**
   * Establish a barrier for all units operating on the array, publishing all
   * changes to all units.
   */
  void barrier() const
  {
    DASH_LOG_TRACE_VAR("Array.barrier()", m_team);
    m_team->barrier();
    DASH_LOG_TRACE("Array.barrier >", "passed barrier");
  }

  /**
   * The pattern used to distribute array elements to units.
   */
  inline const PatternType & pattern() const
  {
    return m_pattern;
  }

  template<int level>
  dash::HView<self_t, level> hview()
  {
    return dash::HView<self_t, level>(*this);
  }

  bool allocate(
    size_type                   nelem,
    dash::DistributionSpec<1>   distribution,
    dash::Team                & team = dash::Team::All())
  {
    DASH_LOG_TRACE_VAR("Array.allocate(nlocal,ds,team)", nelem);
    DASH_LOG_TRACE_VAR("Array.allocate", m_team->dart_id());
    DASH_LOG_TRACE_VAR("Array.allocate", team.dart_id());
    // Check requested capacity:
    if (nelem == 0) {
      DASH_THROW(
        dash::exception::InvalidArgument,
        "Tried to allocate dash::Array with size 0");
    }
    if (m_team == nullptr || *m_team == dash::Team::Null()) {
      DASH_LOG_TRACE("Array.allocate",
                     "initializing with specified team -",
                     "team size:", team.size());
      m_team    = &team;
      m_pattern = PatternType(nelem, distribution, team);
      DASH_LOG_TRACE_VAR("Array.allocate", team.dart_id());
      DASH_LOG_TRACE_VAR("Array.allocate", m_pattern.team().dart_id());
    } else {
      DASH_LOG_TRACE("Array.allocate",
                     "initializing pattern with initial team");
      m_pattern = PatternType(nelem, distribution, *m_team);
    }
    bool ret = allocate(m_pattern);
    DASH_LOG_TRACE("Array.allocate(nlocal,ds,team) >");
    return ret;
  }

  bool allocate(
    size_type                           nelem,
    std::initializer_list<value_type>   local_elements,
    dash::DistributionSpec<1>           distribution,
    dash::Team                        & team = dash::Team::All())
  {
    DASH_LOG_TRACE_VAR("Array.allocate(lvals,ds,team)",
                       local_elements.size());
    DASH_LOG_TRACE_VAR("Array.allocate", m_team->dart_id());
    DASH_LOG_TRACE_VAR("Array.allocate", team.dart_id());
    // Check requested capacity:
    if (nelem == 0) {
      DASH_THROW(
        dash::exception::InvalidArgument,
        "Tried to allocate dash::Array with size 0");
    }
    if (m_team == nullptr || *m_team == dash::Team::Null()) {
      DASH_LOG_TRACE("Array.allocate",
                     "initializing pattern with Team::All()");
      m_team    = &team;
      m_pattern = PatternType(nelem, distribution, team);
      DASH_LOG_TRACE_VAR("Array.allocate", team.dart_id());
      DASH_LOG_TRACE_VAR("Array.allocate", m_pattern.team().dart_id());
    } else {
      DASH_LOG_TRACE("Array.allocate",
                     "initializing pattern with initial team");
      m_pattern = PatternType(nelem, distribution, *m_team);
    }
    bool ret = allocate(m_pattern, local_elements);
    DASH_LOG_TRACE("Array.allocate(lvals,ds,team) >");
    return ret;
  }

  void deallocate()
  {
    DASH_LOG_TRACE_VAR("Array.deallocate()", this);
    DASH_LOG_TRACE_VAR("Array.deallocate()", m_size);
    // Assure all units are synchronized before deallocation, otherwise
    // other units might still be working on the array:
    if (dash::is_initialized()) {
      barrier();
    }
    // Remove this function from team deallocator list to avoid
    // double-free:
    m_pattern.team().unregister_deallocator(
      this, std::bind(&Array::deallocate, this));
    // Actual destruction of the array instance:
    DASH_LOG_TRACE_VAR("Array.deallocate()", m_globmem);
    if (m_globmem != nullptr) {
      delete m_globmem;
      m_globmem = nullptr;
    }
    m_size = 0;
    DASH_LOG_TRACE_VAR("Array.deallocate >", this);
  }

  bool allocate(const PatternType & pattern)
  {
		DASH_LOG_TRACE("Array._allocate()", "pattern",
                   pattern.memory_layout().extents());
    if (&m_pattern != &pattern) {
      DASH_LOG_TRACE("Array.allocate()", "using specified pattern");
      m_pattern = pattern;
    }
    // Check requested capacity:
    m_size      = m_pattern.capacity();
    m_team      = &(m_pattern.team());
    if (m_size == 0) {
      DASH_THROW(
        dash::exception::InvalidArgument,
        "Tried to allocate dash::Array with size 0");
    }
    // Initialize members:
    m_lsize     = m_pattern.local_size();
    m_lcapacity = m_pattern.local_capacity();
    m_myid      = m_team->myid();
    // Allocate local memory of identical size on every unit:
    DASH_LOG_TRACE_VAR("Array._allocate", m_lcapacity);
    DASH_LOG_TRACE_VAR("Array._allocate", m_lsize);
    m_globmem   = new glob_mem_type(m_lcapacity, m_pattern.team());
    // Global iterators:
    m_begin     = iterator(m_globmem, m_pattern);
    m_end       = iterator(m_begin) + m_size;
    // Local iterators:
    m_lbegin    = m_globmem->lbegin(m_myid);
    // More efficient than using m_globmem->lend as this a second mapping
    // of the local memory segment:
    m_lend      = m_lbegin + m_lsize;
    DASH_LOG_TRACE_VAR("Array._allocate", m_myid);
    DASH_LOG_TRACE_VAR("Array._allocate", m_size);
    DASH_LOG_TRACE_VAR("Array._allocate", m_lsize);
    // Register deallocator of this array instance at the team
    // instance that has been used to initialized it:
    m_team->register_deallocator(
      this, std::bind(&Array::deallocate, this));
    // Assure all units are synchronized after allocation, otherwise
    // other units might start working on the array before allocation
    // completed at all units:
    if (dash::is_initialized()) {
      DASH_LOG_TRACE("Array._allocate",
                     "waiting for allocation of all units");
      m_team->barrier();
    }
    DASH_LOG_TRACE("Array._allocate >", "finished");
    return true;
  }

private:

#if 0
  typename std::enable_if<
    std::is_move_constructible<value_type>::value &&
    std::is_move_assignable<value_type>::value,
    bool
  >::type
#else
  bool
#endif
  allocate(
    const PatternType                 & pattern,
    std::initializer_list<value_type>   local_elements)
  {
    DASH_LOG_TRACE("Array._allocate()", "pattern",
                   pattern.memory_layout().extents());
    // Check requested capacity:
    m_size      = pattern.capacity();
    m_team      = &pattern.team();
    if (m_size == 0) {
      DASH_THROW(
        dash::exception::InvalidArgument,
        "Tried to allocate dash::Array with size 0");
    }
    // Initialize members:
    m_lsize     = pattern.local_size();
    m_lcapacity = pattern.local_capacity();
    m_myid      = pattern.team().myid();
    // Allocate local memory of identical size on every unit:
    DASH_LOG_TRACE_VAR("Array._allocate", m_lcapacity);
    DASH_LOG_TRACE_VAR("Array._allocate", m_lsize);
    m_globmem   = new glob_mem_type(local_elements, pattern.team());
    // Global iterators:
    m_begin     = iterator(m_globmem, pattern);
    m_end       = iterator(m_begin) + m_size;
    // Local iterators:
    m_lbegin    = m_globmem->lbegin(m_myid);
    // More efficient than using m_globmem->lend as this a second mapping
    // of the local memory segment:
    m_lend      = m_lbegin + pattern.local_size();
    DASH_LOG_TRACE_VAR("Array._allocate", m_myid);
    DASH_LOG_TRACE_VAR("Array._allocate", m_size);
    DASH_LOG_TRACE_VAR("Array._allocate", m_lsize);
    // Register deallocator of this array instance at the team
    // instance that has been used to initialized it:
    pattern.team().register_deallocator(
      this, std::bind(&Array::deallocate, this));
    // Assure all units are synchronized after allocation, otherwise
    // other units might start working on the array before allocation
    // completed at all units:
    if (dash::is_initialized()) {
      DASH_LOG_TRACE("Array._allocate",
                     "waiting for allocation of all units");
      m_team->barrier();
    }
    DASH_LOG_TRACE("Array._allocate >", "finished");
    return true;
  }

*/

#endif /* PYDASH__ARRAY_H_INCLUDED */
