#!/usr/bin/python3

def reverse_integer(num):

    rnum = 0
    negative = False
    
    if num < 0:
        negative = True
        num = abs(num)
    
    while num != 0:

        if (rnum > 214748364):
            return 0
        
        rnum = rnum * 10 + num % 10
        num = num // 10

    if negative == True:
        rnum = -rnum

    return rnum
    
print(reverse_integer(1000000003))
