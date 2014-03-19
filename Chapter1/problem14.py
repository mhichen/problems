#!/usr/bin/python3


#*******************************************************
# Identify the most often occuring word from a string
#*******************************************************

def majority_find(words):
    
    words = words.strip()
    list_of_words = words.split()

    # loop through list of words, keep track of most frequently occurring one
    # and occurrences

    most_frequent = ""
    occurrences = 0
    
    for i in list_of_words:
        if (occurrences == 0):
            most_frequent = i
            occurrences = 1
        elif (most_frequent == i):
            occurrences += 1
        else:
            occurrences -= 1

    return most_frequent
            
if __name__ == "__main__":

    string_of_words = "a b c a b d b a a a d a a a a a a d f d a a a a a a b d s a a a"
    print(majority_find(string_of_words))


    
