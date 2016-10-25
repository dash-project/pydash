#include <cdash/Array.h>

#include <dash/Array.h>

/*
 * TO-DO: 
 * ==================================
 * Implement all methods from 
 * pydash/cdash/include/cdash/Array.h
 */
 
//LocalArrayRef
CLocalArrayRef cdash__array__LocalArrayRef_init(        CArray         array)
{
  return reinterpret_cast<CLocalArrayRef>(dash::LocalArrayRef(array));
}

CLocalArrayRef cdash__array__LocalArrayRef_delete(      CCLocalArrayRef array)
{
 // reinterpret_cast from CLocalArrayRef to LocalArrayRef, then deallocate?
} 

const_pointer cdash__array__LocalArrayRef_begin(        CLocalArrayRef larray)
{
   return reinterpret_cast<const_pointer>larray.begin();
}

pointer       cdash__array__LocalArrayRef_begin(        CLocalArrayRef larray)
{
   return reinterpret_cast<pointer>larray.begin();
}

const_pointer cdash__array__LocalArrayRef_end(          CLocalArrayRef larray)
 {
   return reinterpret_cast<const_pointer>larray.end();
}

pointer       cdash__array__LocalArrayRef_end(          CLocalArrayRef larray);
{
   return reinterpret_cast<pointer>larray.end();
}

size_type     cdash__array__LocalArrayRef_size(         CLocalArrayRef larray)
{
   return reinterpret_cast<size_type>larray.size();
}

value_type    cdash__array__LocalArrayRef_random_access(CLocalArrayRef larray,
                                                        size_t         n)
{
   return reinterpret_cast<value_type>larray[n];
}

reference     cdash__array__LocalArrayRef_random_access(size_t         n)
{
    return reinterpret_cast<reference>larray[n];
}

bool          cdash__array__LocalArrayRef_is_local(CLocalArrayRef larray,
                                                   index_type     g_index)
{
    return larray.is_local(g_index);
}


self_t        cdash__array__LocalArrayRef_block(CLocalArrayRef larray,
                                                index_type block_lindex)
{
    return reinterpret_cast<self_t>larray.block(block_lindex);
}

PatternType & cdash__array__LocalArrayRef_pattern();
