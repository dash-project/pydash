import pydash
import time

pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()

# Collectively instantiate array:
array  = pydash.ArrayInt(3 * nunits)

# Initialize array:
for l in range(0,array.local.size()):
    array.local[l] = 100 * (1 + myid) + l

pydash.barrier()

for u in range(0,nunits):
    if u == myid:
        for lelem in array.local:
            print("unit {} Array.local[]: {}".format(myid, lelem))
    pydash.barrier()

time.sleep(1)
pydash.barrier()

if myid == 0:
    for gi in range(0,array.size()):
        print("Array[{}]: {}".format(gi, array[gi]))

pydash.barrier()

pydash.finalize()
