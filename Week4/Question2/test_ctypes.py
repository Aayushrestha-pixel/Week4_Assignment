import ctypes

# load the shared library
lib = ctypes.CDLL('./string_lib.so')

# create a string buffer
text = "aayush shrestha"
buffer = ctypes.create_string_buffer(text.encode())

# call the C function
lib.to_uppercase(buffer)

# print result
print("Result:", buffer.value.decode())