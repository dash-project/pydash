#include <cdash/Array.h>
#include <dash/Array.h>

CLocalArrayRef cdash__array__LocalArrayRef_init(CArray array)
{
  return reinterpret_cast<CLocalArrayRef>(dash::LocalArrayRef(array));
}

CLocalArrayRef cdash__array__LocalArrayRef_delete(CCLocalArrayRef array)
{
 // reinterpret_cast from CLocalArrayRef to LocalArrayRef, then deallocate?
} 

const_pointer cdash__array__LocalArrayRef_begin(CLocalArrayRef larray)
{
   return reinterpret_cast<const_pointer>(larray.begin());
}

pointer cdash__array__LocalArrayRef_begin(CLocalArrayRef larray)
{
   return reinterpret_cast<pointer>(larray.begin());
}

const_pointer cdash__array__LocalArrayRef_end(CLocalArrayRef larray)
 {
   return reinterpret_cast<const_pointer>(larray.end());
}

pointer cdash__array__LocalArrayRef_end(CLocalArrayRef larray);
{
   return reinterpret_cast<pointer>(larray.end());
}

size_type cdash__array__LocalArrayRef_size(CLocalArrayRef larray)
{
   return reinterpret_cast<size_type>(larray.size());
}

value_type cdash__array__LocalArrayRef_random_access(CLocalArrayRef larray,
                                                     size_t         n)
{
   return reinterpret_cast<value_type>(larray[n]);
}

reference cdash__array__LocalArrayRef_random_access(size_t n)
{
    return reinterpret_cast<reference>(larray[n]);
}

bool cdash__array__LocalArrayRef_is_local(CLocalArrayRef larray,
                                          index_type     g_index)
{
    return (larray.is_local(g_index));
}


self_t cdash__array__LocalArrayRef_block(CLocalArrayRef larray,
                                         index_type block_lindex)
{
    return reinterpret_cast<self_t>(larray.block(block_lindex));
}

PatternType & cdash__array__LocalArrayRef_pattern();

/*
 * AsyncArrayRef (declared inside Array.h)
 *
 */
CAsyncArrayRef cdash__array__AsyncArrayRef_init( CArray array)
{
    return reinterpret_cast<CASyncArrayRef>(AsyncArrayRef(array));
}

void cdash__array__AsyncArrayRef_delete(CAsyncArrayRef _this)
{
    ~AsyncArrayRef(_this);  
}

const_pointer cdash__array__AsyncArrayRef_begin(CAsyncArrayRef _this)
{
    return reinterpret_cast<const_pointer>(_this.begin());  
}

pointer cdash__array__AsyncArrayRef_begin(CAsyncArrayRef _this)
{
    return reinterpret_cast<pointer>(_this.begin());  
}

const_pointer cdash__array__AsyncArrayRef_end(CAsyncArrayRef _this)
{
    return reinterpret_cast<const_pointer>(_this.end());  
}
pointer cdash__array__AsyncArrayRef_end(CAsyncArrayRef _this)
{
    return reinterpret_cast<pointer>(_this.end());  
}

size_type cdash__array__AsyncArrayRef_size(CAsyncArrayRef _this)
{
    return reinterpret_cast<size_type>(_this.size());  
}

const_async_reference cdash__array__AsyncArrayRef_random_access(CAsyncArrayRef _this, 
                                                                size_t n)
{
    return reinterpret_cast<const_async_reference>(_this[n]);  
}

async_reference cdash__array__AsyncArrayRef_random_access(CAsyncArrayRef _this,
                                                          size_t n)
{
    return reinterpret_cast<async_reference>(_this[n]);  
}

void cdash__array__AsyncArrayRef_flush(CAsyncArrayRef _this)
{
    (_this.flush());
}

void cdash__array__AsyncArrayRef_flush_local(CAsyncArrayRef _this);
{
    (_this.flush());
}

void cdash__array__AsyncArrayRef_flush_all(CAsyncArrayRef _this)
{
    (_this.flush_all());
}
    
void cdash__array__AsyncArrayRef_flush_local_all(CAsyncArrayRef _this)
{
    (_this.flush_local_all());
}
    
void cdash__array__AsyncArrayRef_push(CAsyncArrayRef _this)
{
    (_this.push());
}    

void cdash__array__AsyncArrayRef_fetch(CAsyncArrayRef _this)
{
    (_this.fetch());
}    
/*
 * ArrayRef (declared inside Array.h)
 *
 */
CArrayRef cdash__array__ArrayRef_init(CArray array)
{
    return reinterpret_cast<CArrayRef>(ArrayRef(array));   
}

void cdash__array__ArrayRef_delete(CArrayRef _this)
{
  dash::array::ArrayRef::delete(_this);
}


Team &  cdash__array__ArrayRef_team(CArrayRef _this)
{
    return reinterpret_cast<Team>(ArrayRef(_this));
}

size_type cdash__array__ArrayRef_size(CArrayRef _this)
{
    return reinterpret_cast<size_type>(_this.size());
}

size_type cdash__array__ArrayRef_local_size(CArrayRef _this)
{
    return reinterpret_cast<size_type>(_this.local_size());    
}

size_type cdash__array__ArrayRef_local_capacity(CArrayRef _this)
{
    return reinterpret_cast<size_type>(_this.local_capacity());
}

size_type cdash__array__ArrayRef_extent(CArrayRef _this,
                                        dim_t     dim)
{
    return reinterpret_cast<size_type>(_this.extent(dim));
}

Extents_t cdash__array__ArrayRef_extents(CArrayRef _this)
{
    return reinterpret_cast<Extents_t>(_this.extents);    
}

bool cdash__array__ArrayRef_empty(CArrayRef _this)
{
    return (_this.empty());
}

void cdash__array__ArrayRef_barrier(CArrayRef _this)
{
   (_this.barrier());   
}

const_pointer cdash__array__ArrayRef_data(CArrayRef _this)
{
    (_this.data());
}

iterator cdash__array__ArrayRef_begin(CArrayRef _this)
{
    return reinterpret_cast<iterator>(_this.begin());       
}

const_iterator cdash__array__ArrayRef_begin(CArrayRef _this)
{
    return reinterpret_cast<const_iterator>(_this.begin());       
}

iterator cdash__array__ArrayRef_end(CArrayRef _this)
{
    return reinterpret_cast<iterator>(_this.end());
}

const_iterator cdash__array__ArrayRef_end(CArrayRef _this)
{
    return reinterpret_cast<const_iterator>(_this.end());       
}


local_type cdash__array__ArrayRef_sub_local(CArrayRef _this)
{
    return reinterpret_cast<local_type>(_this.sub_local());        
}

ElementType *  cdash__array__ArrayRef_lbegin(CArrayRef _this)
{
    return reinterpret_cast<ElementType>(_this.lbegin());        
}
    
ElementType *  cdash__array__ArrayRef_lend(CArrayRef _this)
{
    return reinterpret_cast<ElementType>(_this.lend());        
}

reference cdash__array__ArrayRef_random_access(CArrayRef _this, 
                                               size_type global_index)
{
    return reinterpret_cast<reference>(_this[global_index]);   
}
    
const_reference cdash__array__ArrayRef_random_access(CArrayRef _this,
                                                     size_type global_index)
{
    return reinterpret_cast<const_reference>(_this[global_index]);   
 
}
    
reference cdash__array__ArrayRef_at(CArrayRef _this, 
                                    size_t    n)
{
    return reinterpret_cast<reference>(_this.at(n));   
}
                                                               
const_reference cdash__array__ArrayRef_at(CArrayRef _this, 
                                          size_t    n)                                                               
{
    return reinterpret_cast<const_reference>(_this.at(n));   
}
                                                               
PatternType & cdash__array__ArrayRef_pattern(CArrayRef _this)
{
    return reinterpret_cast<PatternType>(_this.pattern());  
}          
          
/*
 * A distributed array.
 */

typedef dash::util::Locality::Scope Scope;

local_type  cdash__array_local;
async_type  cdash__array_async;

CArray cdash__array__new(/*param list*/)
{
  return reinterpret_cast<CArray>(Array(/*param list*/));
}
void cdash__array__delete(CArray _this)
{
  delete(_this);
}

View cdash__array__block(CArray _this, index_type block_gindex)
{
  return reinterpret_cast<View>(_this.block(block_gindex));
}

const_pointer cdash__array__data(CArray _this)
{
  return reinterpret_cast<View>(_this.data());
}

iterator cdash__array__begin(CArray _this)
{
  return reinterpret_cast<iterator>(_this.begin());
}

const_iterator cdash__array__begin(CArray _this)
{
  return reinterpret_cast<const_iterator>(_this.begin());
}

iterator cdash__array__end(CArray _this)
{
  return reinterpret_cast<iterator>(_this.end());
}

const_iterator cdash__array__end(CArray _this)
{
  return reinterpret_cast<const_iterator>(_this.end());
}

ElementType * cdash__array__lbegin(CArray _this)
{
  return reinterpret_cast<ElementType>(_this.lbegin());
}
ElementType * cdash__array__lbegin(CArray _this)
{
  return reinterpret_cast<ElementType>(_this.lbegin());
}

ElementType * cdash__array__lend(CArray _this)
{
  return reinterpret_cast<ElementType>(_this.lend());
}

reference cdash__array__random_access(CArray    _this, 
                                      size_type global_index)
{
  return reinterpret_cast<reference>(_this.[global_index]);                                     
}

const_reference cdash__array__random_access(CArray     _this, 
                                            size_type  global_index)
{
  return reinterpret_cast<const_reference>(_this.[global_index]);                                     
}

reference cdash__array__at(CArray    _this, 
                           size_type global_pos)
{
  return reinterpret_cast<reference>(_this.at(global_pos));                                     
}

const_reference cdash__array__at(CArray     _this,
                                 size_type  global_pos)
{
    return reinterpret_cast<const_reference>(_this.at(global_pos));                                     
}

size_type cdash__array__size(CArray _this)
{
    return reinterpret_cast<size_type>(_this.size());                                     
}
    
size_type cdash__array__capacity(CArray _this)
{
    return reinterpret_cast<size_type>(_this.capacity());                                     
}
    
Team & cdash__array__team(CArray _this)
{
    return reinterpret_cast<size_type>(_this.team());                                     
}
 
size_type cdash__array__lsize(CArray _this)
{
    return reinterpret_cast<size_type>(_this.lsize());                                     
}
 
size_type cdash__array__lcapacity(CArray _this)
{
    return reinterpret_cast<size_type>(_this.lcapacity());                                     
}
 
bool cdash__array__empty(CArray _this)
{
    return (_this.empty());
}

View cdash__array__local_in(CArray _this, 
                            Scope  scope)
{
    return reinterpret_cast<View>(_this.local_in(scope));
}
                                                     
bool cdash__array__is_local(CArray     _this,
                            index_type global_index)
{
    return (_this.is_local(global_index));
}
                                                     
void cdash__array__barrier(CArray _this)
{
    (_this.barrier());
}
const PatternType & cdash__array__pattern(CArray _this)
{
    return reinterpret_cast<PatternType>(_this.pattern());
}

HView<self_t, level> cdash__array__hview(CArray _this)
{
    return reinterpret_cast<HView<self_t, level>>(_this.hview()); 
}
bool cdash__array__allocate(CArray    _this,
                            size_type nelem,
                            DistrSpec distribution,
                            Team &    team)
{
    return (_this.allocate(/*param list*/));
}
                                                 
                            
void cdash__array__deallocate(CArray  _this,
                              Team &  team)
{
    (_this.deallocate(/*param list*/));                                                    
}

bool cdash__array__allocate(CArray         _this,
                            PatternType &  pattern)
{
   return (_this.allocate(/*param list*/)); 
}
  

