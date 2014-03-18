#!/usr/bin/python3

#******************************************************
# Given dictionary of words, returns the words grouped
# into sets that are anagrams of each other.
#******************************************************

# Sorts a string
def sort_string(tstring):
    return "".join(sorted(tstring))


def find_anagrams(words):

    # Go through list of words
    # Sort the word, check the dictionary for the key
    # if it exists, add the word to the list, if no
    # add new entry to dictionary with sorted word as
    # the key

    organized_list = dict()

    for w in words:

        sorted_word = sort_string(w)
        
        if (sorted_word in organized_list):
            organized_list[sorted_word].append(w)
        else:
            organized_list[sorted_word] = [w]


    return organized_list

# Test functions
words = ['tic', 'tac', 'toe', 'cat']
print(find_anagrams(words))
