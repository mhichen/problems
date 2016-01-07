#!/usr/bin/python3

def strstr(haystack, needle):

    for c in range(0, len(haystack)):
        for d in range(0, len(needle)):
            if d == len(needle)-1:
                return c
            if ((c + d) == len(haystack)-1):
                return -1
            if (needle[d] != haystack[c + d]):
                break
            

    
if __name__ == "__main__":

    print(strstr('aba', 'ba'))
