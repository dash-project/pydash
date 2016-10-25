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

typedef int bool;

/*
 * LocalArrayRef (declared inside Array.h)
 *
 */
CLocalArrayRef cdash__array__LocalArrayRef_init(        CArray         array);
CLocalArrayRef cdash__array__LocalArrayRef_delete(      CLocalArrayRef array);

const_pointer cdash__array__LocalArrayRef_begin(        CLocalArrayRef larray);
pointer       cdash__array__LocalArrayRef_begin(        CLocalArrayRef larray);

const_pointer cdash__array__LocalArrayRef_end(          CLocalArrayRef larray);
pointer       cdash__array__LocalArrayRef_end(          CLocalArrayRef larray);

size_type     cdash__array__LocalArrayRef_size(         CLocalArrayRef larray);

value_type    cdash__array__LocalArrayRef_random_access(CLocalArrayRef larray,
                                                        size_t         n);

reference     cdash__array__LocalArrayRef_random_access(CLocalArrayRef larray,
                                                        size_t         n);

bool          cdash__array__LocalArrayRef_is_local(CLocalArrayRef larray, 
                                                   index_type     g_index);

self_t        cdash__array__LocalArrayRef_block(CLocalArrayRef larray, 
                                                index_type block_lindex);

PatternType & cdash__array__LocalArrayRef_pattern(/*param*/);


/*
 * AsyncArrayRef (declared inside Array.h)
 *
 */
CAsyncArrayRef        cdash__array__AsyncArrayRef_init( CArray array);
void                  cdash__array__AsyncArrayRef_delete();

const_pointer         cdash__array__AsyncArrayRef_begin(CLocalArrayRef larray);
pointer               cdash__array__AsyncArrayRef_begin(CLocalArrayRef larray);

const_pointer         cdash__array__AsyncArrayRef_end(  CLocalArrayRef larray);
pointer               cdash__array__AsyncArrayRef_end(  CLocalArrayRef larray);

size_type             cdash__array__AsyncArrayRef_size( CLocalArrayRef larray);

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
CArrayRef            cdash__array__ArrayRef_init(          CArray    array);
void                 cdash__array__ArrayRef_delete(        CArrayRef _this);
Team              &  cdash__array__ArrayRef_team(          CArrayRef _this);
size_type            cdash__array__ArrayRef_size(          CArrayRef _this);
size_type            cdash__array__ArrayRef_local_size(    CArrayRef _this);
size_type            cdash__array__ArrayRef_local_capacity(CArrayRef _this);
size_type            cdash__array__ArrayRef_extent(        dim_t     dim);
Extents_t            cdash__array__ArrayRef_extents(       CArrayRef _this);
bool                 cdash__array__ArrayRef_empty(         CArrayRef _this);
void                 cdash__array__ArrayRef_barrier(       CArrayRef _this);
const_pointer        cdash__array__ArrayRef_data(          CArrayRef _this);
iterator             cdash__array__ArrayRef_begin(         CArrayRef _this);
const_iterator       cdash__array__ArrayRef_begin(         CArrayRef _this);
iterator             cdash__array__ArrayRef_end(           CArrayRef _this);
const_iterator       cdash__array__ArrayRef_end(           CArrayRef _this);
local_type           cdash__array__ArrayRef_sub_local(     CArrayRef _this);
ElementType       *  cdash__array__ArrayRef_lbegin(        CArrayRef _this);
ElementType       *  cdash__array__ArrayRef_lend(          CArrayRef _this);
reference            cdash__array__ArrayRef_random_access( size_type global_index);
const_reference      cdash__array__ArrayRef_random_access( size_type global_index);
reference            cdash__array__ArrayRef_at(            CArrayRef _this, 
                                                           size_t    n);
const_reference      cdash__array__ArrayRef_at(            CArrayRef _this, 
                                                           size_t    n);
PatternType &        cdash__array__ArrayRef_pattern(       CArrayRef _this);
          
          
/*
 * A distributed array.
 */

typedef dash::util::Locality::Scope Scope;

local_type  cdash__array_local;
async_type  cdash__array_async;

CArray cdash__array__new(/*param list*/);
void   cdash__array__delete(CArray _this);
View                 cdash__array__block(index_type block_gindex);

const_pointer        cdash__array__data(         CArray     _this);
iterator             cdash__array__begin(        CArray     _this);
const_iterator       cdash__array__begin(        CArray     _this);
iterator             cdash__array__end(          CArray     _this);
const_iterator       cdash__array__end(          CArray     _this);
ElementType *        cdash__array__lbegin(       CArray     _this);
ElementType *        cdash__array__lend(         CArray     _this);
reference            cdash__array__random_access(size_type  global_index);
const_reference      cdash__array__random_access(size_type  global_index);
reference            cdash__array__at(           size_type  global_pos);
const_reference      cdash__array__at(           size_type  global_pos);
size_type            cdash__array__size(         CArray     _this);
size_type            cdash__array__capacity(     CArray     _this);
Team &               cdash__array__team(         CArray     _this);
size_type            cdash__array__lsize(        CArray     _this);
size_type            cdash__array__lcapacity(    CArray     _this);
bool                 cdash__array__empty(        CArray     _this);
View                 cdash__array__local_in(     CArray     _this, 
                                                 Scope      scope);
bool                 cdash__array__is_local(     CArray     _this, 
                                                 index_type global_index);
void                 cdash__array__barrier(      CArray     _this);
const PatternType &  cdash__array__pattern(      CArray     _this);
HView<self_t, level> cdash__array__hview(        CArray    _this);
bool                 cdash__array__allocate(     CArray    _this,
                                                 size_type nelem, 
                                                 DistrSpec distribution,
                                                 Team &    team);
void                 cdash__array__deallocate(   CArray    _this);

bool                 cdash__array__allocate(CArray         _this,
                                            PatternType &  pattern);


#endif /* PYDASH__ARRAY_H_INCLUDED */
