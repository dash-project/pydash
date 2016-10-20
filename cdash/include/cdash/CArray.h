#ifndef PYDASH__ARRAY_H__INCLUDED
#define PYDASH__ARRAY_H__INCLUDED

#include <libdash.h>


typedef void * CArray;
typedef int    size_type;
typedef int    index_type;


CArray cdash__array__new(size_type nelem, ...);
void   cdash__array__delete(CArray  _this);
View   cdash__array__block(index_type block_gindex):

#endif /* PYDASH__ARRAY_H__INCLUDED */
