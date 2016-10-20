#ifndef PYDASH__ARRAY_H__INCLUDED
#define PYDASH__ARRAY_H__INCLUDED

#include <libdash.h>


typedef void * CArray;
typedef int    size_type;
typedef int    index_type;


CArray         cdash__array__new(size_type nelem, ...);
void           cdash__array__delete(CArray  _this);
View           cdash__array__block(index_type block_gindex);
const_pointer  cdash__array__data();
iterator       cdash__array__begin();
const_iterator cdash__array__begin()
iterator       cdash__array__end()
const_iterator cdash__array__end()
ElementType *  cdash__array__lbegin();
ElementType *  cdash__array__lend();
reference      cdash__array__at(size_type global_pos);



#endif /* PYDASH__ARRAY_H__INCLUDED */
