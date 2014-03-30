#!/usr/bin/python3

#******************************************
# Given a long stream of strings separated
# by white space, use only O(k) memory to
# identify all the words that occur more than
# [n/k] times in the stream, where n is the
# length of the stream.  You can only read
# the stream twice.
#******************************************

# Go through the list, maintin a hash that is
# no more than k -1 long.  If a string is not
# in the list and the list is < k-1 long, we add
# the string to the list; if the list is >= k - 1
# long, then we subtract an occurrence from each of
# the hash items in the list.  Of course, if the
# string is in the hash, we add to the occurence.


def majority_find(words, k):

    words = words.strip()
    list_of_words = words.split()

    most_frequent = {}


    for i in list_of_words:

        topop = None
        
        if i in most_frequent:
            most_frequent[i] += 1
        else:

            if len(most_frequent) < (k-1):
                most_frequent[i] = 1
            else:
                to_pop = []
                
                for key, v  in most_frequent.items():

                    if v == 1:
                        to_pop.append(key)
                    else:
                        most_frequent[key] = v - 1

                for key in to_pop:
                    del most_frequent[key]

    # Set values of hash to 0
    for key in most_frequent.keys():
        most_frequent[key] = 0

    for i in list_of_words:
        if i in most_frequent:
            most_frequent[i] += 1

    result = []
    for key, v in most_frequent.items():
        if v > len(list_of_words)/k:
             result.append(key)

    return result

if __name__ == "__main__":

    string_of_words = "a b c a b d b a a a d a a a a a a d f d a a a a a a b d s a a a"
    string_of_words2 = "a b c a b c a a a b a d e b b b"
    print(majority_find(string_of_words, 3))
    print(majority_find(string_of_words2, 3))
