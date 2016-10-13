#ifndef PYDASH__GLOB_PTR_H__INCLUDED
#define PYDASH__GLOB_PTR_H__INCLUDED

#include <libdash.h>


typedef void * CGlobPtr;
typedef int    CGlobPtr_value_type;

/* For illustration, see:
 * https://stackoverflow.com/questions/1588788/wrapping-c-class-api-for-c-consumption
 */

CGlobPtr    cdash__glob_ptr__new(dart_gptr_t gptr);

void        cdash__glob_ptr__delete(dart_gptr_t gptr);

CGlobPtr    cdash__glob_ptr__copy(dart_gptr_t gptr);

CGlobPtr    cdash__glob_ptr__assign(CGlobPtr _this, CGlobPtr rhs);

int         cdash__glob_ptr__equals(CGlobPtr _this, CGlobPtr rhs);

dart_gptr_t cdash__glob_ptr__dart_gptr_t(CGlobPtr _this);

/**
 *  operator++
 */
CGlobPtr    cdash__glob_ptr__inc(CGlobPtr _this);

/**
 *  operator--
 */
CGlobPtr    cdash__glob_ptr__dec(CGlobPtr _this);

/**
 *  operator+=, operator-=
 */
CGlobPtr    cdash__glob_ptr__offset(CGlobPtr _this, int offset);



#endif /* PYDASH__GLOB_PTR_H__INCLUDED */
