import pydash

pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()

v_0 = pydash.LV(0, "zero  ")
v_1 = pydash.LV(1, "first ")
#v_2 = pydash.LV(2, "second")

v_0 = v_1 #copy or reference?


pydash.finalize()
