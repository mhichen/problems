#!/usr/bin/python3

#*********************************************
# Use the fact that if pairs can be connected
# by straight lines without intersecting, then
# pairs can be connected without intersecting.
#*********************************************


def intersects(lines):

    sorted_list = sorted(lines)

    for ind, val in enumerate(sorted_list):
        
        if ind == 0:
            continue
        if (val[0] + val[1]) > (sorted_list[ind-1][0] + sorted_list[ind-1][1]):
            return False
        else:
            return True
        

if __name__ == "__main__":


    lines_list = [(0, 1), (1, -1)]
    lines_list_2 = [(0, 0.5), (0.7, 0)]
    
    print(intersects(lines_list))
    print(intersects(lines_list_2))
        