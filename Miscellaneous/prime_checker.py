#!/usr/bin/python3

import math
import time                                                

#*******************************************
# Decorator that times a function
# Taken from https://www.andreas-jung.com/contents/a-python-decorator-for-measuring-the-execution-time-of-methods
#*******************************************
def timeit(method):

    def timed(*args, **kw):
        ts = time.time()
        result = method(*args, **kw)
        te = time.time()

        print('%r (%r, %r) %2.2f sec' % (method.__name__, args, kw, te-ts))
        return result

    return timed

#*******************************************
# Checks if a number is prime or not
#*******************************************

def is_prime(n):
    
    for i in range(2, math.floor(math.sqrt(n))+1):
        
        if n % i == 0:
            return False
        
    return True
        
#*******************************************
# Returns all prime numbers up to the given
# number
#*******************************************
@timeit
def primes_up_to(n):

    # make a boolean array of numbers from 0 to n
    # make an array to contain the prime numbers we fine

    is_prime = [True] * (n+1)
    primes = []

    for i in range(2,n+1):

        if is_prime[i] is True:
            primes.append(i)
            
            for j in range(2*i, n+1, i):
                is_prime[j] = False

    return primes

@timeit
def primes_up_to_slow(n):
    return [p for p in range(2,n+1) if is_prime(p)]
        
if __name__ == "__main__":
    
    n = 1000000

    print(is_prime(17))
    primes_up_to(n)
    primes_up_to_slow(n)
