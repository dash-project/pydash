#ifndef PYDASH__ARRAY_H__INCLUDED
#define PYDASH__ARRAY_H__INCLUDED

#include <libdash.h>

typedef void *      CArray;
typedef int         size_type;
typedef int         index_type;
typedef int         bool;
typedef int         level;
typedef             self_t;
typedef dash::HView HView;


CArray               cdash__array__new(size_type nelem, ...);
void                 cdash__array__delete(CArray  _this);
View                 cdash__array__block(index_type block_gindex);
const_pointer        cdash__array__data();
iterator             cdash__array__begin();
const_iterator       cdash__array__begin();
iterator             cdash__array__end();
const_iterator       cdash__array__end();
ElementType *        cdash__array__lbegin();
ElementType *        cdash__array__lend();
reference            cdash__array__at(size_type global_pos);
const_reference      cdash__array__at(size_type global_pos);
size_type            cdash__array__size();
size_type            cdash__array__capacity();
Team &               cdash__array__team();
size_type            cdash__array__lsize();
size_type            cdash__array__lcapacity();
bool                 cdash__array__empty();
View                 cdash__array__local_in(dash::util::Locality::Scope scope);
bool                 cdash__array__is_local(index_type global_index);
void                 cdash__array__barrier();
const PatternType &  cdash__array__pattern();
HView<self_t, level> cdash__array__hview();
bool                 cdash__array__allocate(size_type nelem, 
                                            dash::DistributionSpec<1> distribution,
                                            dash::Team &              team = dash::Team::All());
void                 cdash__array__deallocate();
bool                 cdash__array__allocate(const PatternType & pattern);

#endif /* PYDASH__ARRAY_H__INCLUDED */
