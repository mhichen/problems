#!/usr/bin/python3

#*********************************************
# Flip first zero from the right to one
#*********************************************

# to flip the first one to zero, we do
# bin(x & (x-1))

#     x = 0b1110001
# x + 1 = 0b1110010
# x - 1 = 0b1110000

f = lambda x: (x) | (x+1)#((x+1) | (x-1)) | (x)

k = 0b1110001
print(bin(k))
print(bin(f(k)))
