import pydash
import time

pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()


my_shared_lv = pydash.give_shared_lv_copy()


print("unit {}: shared lv: ({}, {})"
        .format(myid, my_shared_lv.name(), my_shared_lv.value()))


pydash.finalize()

