import pydash

pydash.initialize(0, "")

value_a = pydash.LV(0, 'a')
value_b = pydash.LV(1, 'b')

pydash.barrier()

array  = pydash.ArrayLV(2)

array[0] = value_a
array[1] = value_b

print("Hello!")

pydash.barrier()

array[0]

pydash.finalize()
