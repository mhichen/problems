#!/usr/bin/python3

import math

#*******************************************
# Checks if a number is prime or not
#*******************************************

def is_prime(n):
    
    for i in range(2, math.floor(math.sqrt(n))+1):
        
        if n % i == 0:
            return False
        
    return True
        
        
        
        
        
if __name__ == "__main__":
    
    print(is_prime(17))
    
    