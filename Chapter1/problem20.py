#!/usr/bin/python3

#********************************************************
# Given an set of open intervals on the real line (a_i,b_i),
# for i in {0, 1, ..., n-1}, determine if there exists
# some interval (a_l, b_l) that is completely contained in
# another interval  (a_m, b_m).  If this pair exists,
# return the pair.  
#********************************************************

def find_contained_interval(intervals):

    # sort by lower bound
    # if upper bound is also sorted, then there is no such
    # interval.

    intervals.sort()

    enm = enumerate(intervals)
    next(enm)
    
    for ind, val in enm:
        if val[1] < intervals[ind-1][1]:
            return val

    return None


if __name__ == "__main__":

    interval_set = [(1, 4), (14, 17), (6, 10), (20, 29)]
    interval_set2 = [(1, 4), (14, 17), (6, 10), (20, 29), (2,3)]
    

    print(find_contained_interval(interval_set))
    print(find_contained_interval(interval_set2))
