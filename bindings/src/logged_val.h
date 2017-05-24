#ifndef PYDASH__LOGGED_VAL_H__INCLUDED
#define PYDASH__LOGGED_VAL_H__INCLUDED

#include "macro.h"

#include <iostream>


namespace pydash {

class logged_val {
  int  _value;
  char _name;

  friend std::ostream & operator<<(std::ostream & os, const logged_val & lv);

 public:		
  logged_val()
  : _value(64),
    _name('X') {
    LOG("logged_val", "@:" << this  << " " <<
        "ooo --- default construct " << _name);
  }

  logged_val(int n, char name)
  : _value(n),
    _name(name) {
    LOG("logged_val(n,s)", "@:" << this  << " " <<
        "*** --- create "<< _name);
  }

  // move constructor
  logged_val(logged_val && other)
      : _value(other._value),
        _name(other._name) {
    LOG("logged_val(self &&)", "@:" << this  << " " <<
        "((( --- move  * <-- @" << &other << ": " << _name);
    other._value = 0;
  }

  // copy constructor
  logged_val(const logged_val & other)
  : _name(other._name) {
    LOG("logged_val(const self &)", "@:" << this  << " " <<
        "=== --- create copy of @" << &other << ": "  << _name);
				
    _value = other._value;
				
    LOG("logged_val(const self &)", "@:" << this  << " " <<
        "=== --- copied value *_*'");
  }

  ~logged_val() {
    LOG("~logged_val()", "@:" << this  << " " <<
        "xxx --- destroy " << _name << " and free data and go home" );
  }

  int value() const {
    return _value;
  }
	
  void set_value(int new_value) {
		_value = new_value;
  }

  char name() const {
    return _name;
  }
};




} // namespace pydash

#endif // PYDASH__LOGGED_VAL_H__INCLUDED
