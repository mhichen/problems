#!/usr/bin/python3

#*********************************************
# Given two sorted arrays of length m and n,
# write an algorithm for getting the k-th
# smallest element in the union of the two
# arrays, done in O(logm + logn) time.
# Keep in mind that the elements may be
# repeated.
#*********************************************

def find_kth_smallest(m, n, k):

    # Take l elements from list m
    # Which leaves k - l elements from list n
    # This means l < m.size and k - l < n.size
    # Set an index l to be between k - n.size
    # and m.size, but since k - n.size could be
    # a negative number, allow for 0 too

    start = max(0, k - len(n))
    end = min(k, len(m))

    while (start < end):
        mid = int(start + (end - start)/2)

        # If this is the case, use one more element
        # from n
        if ((mid > 0) and (k - mid < len(n)) and (m[mid - 1] > n[k - mid])):
            end = mid #k - mid + 1

        # If this is the case, use one more element
        # from m
        elif ((k - mid > 0) and (mid < len(m)) and (n[k - mid - 1] > m[mid])):
            
            start = mid + 1

        else:
            start = mid
            break


    if (start == 0):
        return n[k - 1]
    elif (start == k):
        return m[k - 1]
    else:
        return max(m[start - 1], n[k - start - 1])
    

if __name__ == "__main__":

    a = [1, 3, 4, 5, 6, 7, 8, 9]
    b = [0, 2, 4, 6, 8]

    print(find_kth_smallest(a, b, 3))
    
