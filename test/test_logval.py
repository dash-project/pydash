import pydash
import time

pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()

# Collectively instantiate array:
array  = pydash.ArrayLV(nunits)

if myid == 0:
    #time.sleep(20)
    array[0] = pydash.LV(myid, 'A')

if myid == 1:
    #time.sleep(10)
    array[1] = pydash.LV(myid, 'B')

if myid == 2:
    #time.sleep(0)
    array[2] = pydash.LV(myid, 'C')

pydash.barrier()

if myid == 0:
    for i in array:
        print("Array element global reference: {} value: {}"
                .format(i, i.get().name()))

pydash.finalize()

