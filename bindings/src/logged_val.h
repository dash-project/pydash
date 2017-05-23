#ifndef PYDASH__LOGGED_VAL_H__INCLUDED
#define PYDASH__LOGGED_VAL_H__INCLUDED

#include "macro.h"

#include <string>
#include <iostream>


namespace pydash {

class logged_val {
  int         _value;
  std::string _name;

  friend std::ostream & operator<<(std::ostream & os, const logged_val & lv);

 public:		
  logged_val()
  : _value(64),
    _name("myvalue") {
    LOG("logged_val",
        "ooo --- default construct " << _name);
  }

  logged_val(int n, const std::string & name)
  : _value(n),
    _name(name) {
    LOG("logged_val(n,s)",
        "*** --- create "<< _name);
  }

  // move constructor
  logged_val(logged_val && other)
      : _value(other._value),
        _name(other._name) {
    LOG("logged_val(self &&)",
        "((( --- move  * <-- " << _name);
    other._value = 0;
  }

  // copy constructor
  logged_val(const logged_val & other)
  : _name(other._name) {
    LOG("logged_val(const self &)",
        "=== --- create copy of " << _name);
				
    _value = other._value;
				
    LOG("Value Type(const self &)",
        "=== --- copied value *_*'");
  }

  ~logged_val() {
    LOG("~logged_val()",
        "xxx --- destroy " << _name << "and free data and go home" );
  }

  int value() const {
    return _value;
  }
	
  void set_value(int new_value) {
		_value = new_value;
  }

  const std::string & name() const {
    return _name;
  }
};

logged_val return_logged_val_by_val( int size, std::string name)
{
  if (size % 2 == 0) {
    return logged_val(size / 2, name);
  } else {
    return logged_val(size * 2, name);
  }
}

int accept_logged_val_by_val(logged_val a)
{
  mine = logged_val(std::move(a));
  mine.set_value(345);

  return mine.value();
}


} // namespace pydash

#endif // PYDASH__LOGGED_VAL_H__INCLUDED
