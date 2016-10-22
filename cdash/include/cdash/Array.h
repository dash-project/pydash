#ifndef PYDASH__ARRAY_H__INCLUDED
#define PYDASH__ARRAY_H__INCLUDED

#include <libdash.h>

typedef void *                    CArray;
typedef int                       size_type;
typedef int                       index_type;
typedef int                       bool;
typedef int                       level;
typedef                           self_t;
typedef dash::HView               HView;
typedef dash::Team                Team;
typedef dash::DistributionSpec<1> DistrSpec;

CArray               cdash__array__new(CArray    _this, 
                                       size_type nelem, ...);

void                 cdash__array__delete(CArray _this);

View                 cdash__array__block(index_type block_gindex);

const_pointer        cdash__array__data(CArray _this);

iterator             cdash__array__begin(CArray _this);

const_iterator       cdash__array__begin(CArray _this);

iterator             cdash__array__end(CArray _this);

const_iterator       cdash__array__end(CArray _this);

ElementType *        cdash__array__lbegin(CArray _this);

ElementType *        cdash__array__lend(CArray _this);

reference            cdash__array__at(size_type global_pos);

const_reference      cdash__array__at(size_type global_pos);

size_type            cdash__array__size(CArray _this);

size_type            cdash__array__capacity(CArray _this);

Team &               cdash__array__team(CArray _this);

size_type            cdash__array__lsize(CArray _this);

size_type            cdash__array__lcapacity(CArray _this);

bool                 cdash__array__empty(CArray _this);

View                 cdash__array__local_in(CArray _this, 
                                            dash::util::Locality::Scope scope);

bool                 cdash__array__is_local(CArray _this, 
                                            index_type global_index);

void                 cdash__array__barrier(CArray _this);

const PatternType &  cdash__array__pattern(CArray _this);

HView<self_t, level> cdash__array__hview(CArray _this);

bool                 cdash__array__allocate(CArray    _this,
                                            size_type nelem, 
                                            DistrSpec distribution,
                                            Team &    team = dash::Team::All());

void                 cdash__array__deallocate(CArray _this);

bool                 cdash__array__allocate(CArray _this,
                                            const PatternType & pattern);

#endif /* PYDASH__ARRAY_H__INCLUDED */
