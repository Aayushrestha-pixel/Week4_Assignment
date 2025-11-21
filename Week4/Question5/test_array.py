import array_module

# create array of size 5
array_module.init_array(5)
print("Array initialized with size 5")

# set some values
array_module.set_value(0, 10)
array_module.set_value(1, 20)
array_module.set_value(2, 30)
print("Values set at indices 0, 1, 2")

# get and print values
print(f"Value at index 0: {array_module.get_value(0)}")
print(f"Value at index 1: {array_module.get_value(1)}")
print(f"Value at index 2: {array_module.get_value(2)}")

# free memory
array_module.free_array()
print("Array memory freed")