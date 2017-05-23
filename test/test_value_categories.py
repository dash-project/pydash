import pydash

pydash.initialize(0, "")

#myid   = pydash.myid().id()
#nunits = pydash.nunits()

#v_0 = pydash.LV(0, "zero  ")
#v_1 = pydash.LV(1, "first ")
#v_2 = pydash.LV(2, "second")
#v_0 = v_1

pydash.barrier()
print("COMMENT: CREATE OBJECT A ----------------------------------------");

a = pydash.LV(123, "A");

pydash.barrier()
print("COMMENT: CREATE OBJECT B ----------------------------------------");

b = pydash.LV(455, "B")

pydash.barrier()
print("COMMENT: CREATE OBJECT A_2 --------------------------------------");

a_2 = pydash.LV(a)

pydash.barrier()
print("COMMENT: CREATE OBJECT E ----------------------------------------");

e = pydash.LV(pydash.LV(130, "E"))
e.set_value(50)

pydash.barrier()
print("COMMENT: CREATE OBJECT M ----------------------------------------");

m = pydash.ret_logged_val_by_val(145, "M")

pydash.barrier()
print("COMMENT: CREATE OBJECT P ----------------------------------------");

p = pydash.acc_logged_val_by_val(pydash.ret_logged_val_by_val(234, "X"))
print(p)

pydash.barrier()
print(" * THE GLORIOUS END  --------------------------------------------");
print(" * PFWOOOHFFF *  ------------------------------------------------");

pydash.finalize()
