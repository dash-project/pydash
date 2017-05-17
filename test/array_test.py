
import pydash

pydash.initialize(0, "")

myid = pydash.myid().id()

print("My unit id: {}".format(myid))

# Collectively instantiate array:
arr = pydash.ArrayInt(100)

# Initialize array:
arr.set(myid, 100 + myid)

# Wait for all units:
pydash.barrier()

print("Unit {} read array[{}] : {}".format(myid, myid, arr.get(myid)))

pydash.finalize()
