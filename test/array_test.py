
import pydash

pydash.initialize(0, "")

myid   = pydash.myid().id()
nunits = pydash.nunits()

# Collectively instantiate array:
arr = pydash.ArrayInt(3 * nunits)

# Initialize array:
arr.set(myid * 3 + 0, 100 * (1 + myid) + 0)
arr.set(myid * 3 + 1, 100 * (1 + myid) + 1)
arr.set(myid * 3 + 2, 100 * (1 + myid) + 2)

# Wait for all units:
pydash.barrier()

fromid = nunits - myid - 1

print("Unit {} read array[{}..{}] : {}, {}, {}".format(
      myid,
      fromid * 3,
      fromid * 3 + 2,
      arr.get(fromid * 3 + 0),
      arr.get(fromid * 3 + 1),
      arr.get(fromid * 3 + 2)
     ))

pydash.finalize()
