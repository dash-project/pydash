
import pydash

pydash.initialize(0, "")

print("My unit id: {}".format(pydash.myid().id()))

pydash.finalize()
