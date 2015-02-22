#!/usr/bin/python3

#******************************************
# Given a sorted array, extract the unique
# elements.
#******************************************

def get_unique(sorted_list):

    unique_list = []
    unique_list.append(sorted_list[0])

    for i in sorted_list:
    	if i != unique_list[-1]:
            unique_list.append(i)
            
    return unique_list

if __name__ == "__main__":

   sorted_list = [1, 1, 3, 3, 3, 5, 5, 5, 9, 9, 9, 9]
   print(get_unique(sorted_list))
