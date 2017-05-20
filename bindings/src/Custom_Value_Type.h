#include <string>
#include "macro.h"

template <class T>
class Custom_Value_Type {
	
public:
  typedef T   value_type;

public:

  Custom_Value_Type()
  : _value(64),
    _name("d") {
    LOG("Custom_Value_Type",
        "ooo --- default construct " << _name);
  }

  Custom_Value_Type(T n, std::string name)
  : _value(n),
    _name(name) {
    LOG("Custom_Value_Type(n,s)",
        "*** --- create " << _name);
  }

  // move constructor
  Custom_Value_Type(Custom_Value_Type<T> && other)
      : _value(other._value),
        _name(other._name) {
    LOG("Custom_Value_Type(self &&)",
        "((( --- move  * <-- " << _name);
    other._value = 0;
  }

  // copy constructor
  Custom_Value_Type(const Custom_Value_Type<T> & other)
  : _name(other._name) {
    LOG("Custom_Value_Type(const self &)",
        "=== --- create copy of " << _name);
				
				_value = other._value;
				
    LOG("Value Type(const self &)",
        "=== --- copied value *_*'");
  }

  ~Custom_Value_Type() {
    LOG("~Custom_Value_Type()",
        "xxx --- destroy " << _name << " and free data and go home" );
  }

  T get_value() const {
    return _value;
  }
	
  void set_value(T new_value) {
		_value = new_value;
  }
	

 private:
  T                 _value;
  const std::string _name;
};