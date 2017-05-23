import pydash

pydash.initialize(0, "")

#myid   = pydash.myid().id()
#nunits = pydash.nunits()

#v_0 = pydash.LV(0, "zero  ")
#v_1 = pydash.LV(1, "first ")
#v_2 = pydash.LV(2, "second")
#v_0 = v_1


a   = pydash.LV(123, "A");
a.set_value(10)

b   = pydash.LV(455, "B")
b.set_value(20)

a_2 = pydash.LV(a)
a_2.set_value(30)

e   = pydash.LV(pydash.LV(130, "E"))
e.set_value(50)

m   = pydash.ret_logged_val_by_val(145, "M")
m.set_value(40)

p   = pydash.acc_logged_val_by_val(pydash.ret_logged_val_by_val(234, "X"))

print(p)

pydash.finalize()
