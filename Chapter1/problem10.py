#!/usr/bin/python3

import re

#******************************************************
# Given a letter L and a magazine article M, return
# true if L can be written using M, false otherwise.
# If a word appears k times in L, it has to have appeared
# in M k times as well.
#******************************************************

# Given a string, returns a hash table with the words as the key
# and the occurrences as the value
def hash_this(A):

    # First need to convert the string into a list of words
    A_list = re.findall(r"[\w]+", A)

    A_hash = dict()
    
    for i in A_list:
        if i in A_hash:
            A_hash[i] = A_hash[i] + 1
        else:
            A_hash[i] = 1

    return A_hash


def one_contains_other(M, L):

    # Hash both article and letter
    M_hash = hash_this(M)
    L_hash = hash_this(L)

    # Loop through L_hash, see if occurrences match in M_hash
    for l in L_hash:
        if (l in M_hash):
            if ((M_hash[l] < L_hash[l])):
                return False
        else:
            return False
        
    return True


if __name__ == "__main__":
    article = "    Once upon a time, there was a cute, little princess; her name was Annie"
    letter = "Annie was a princess"
    letter2 = "Annie was a beautiful princess"
    
    print(one_contains_other(article, letter))
    print(one_contains_other(article, letter2))
