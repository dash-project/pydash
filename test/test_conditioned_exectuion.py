import pydash
import time

pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()

# Collectively instantiate array:
array  = pydash.ArrayLV(3)

if myid == 0:
    print(myid)
    #time.sleep(20)
    array[0] = pydash.LV(myid, "first")

if myid == 1:
    print(myid)
    #time.sleep(10)
    array[1] = pydash.LV(myid, "second")

if myid == 2:
    print(myid)
    #time.sleep(0)
    array[2] = pydash.LV(myid, "third")

pydash.barrier()

if myid == 0:
    print("Ich bin cool")

pydash.finalize()
