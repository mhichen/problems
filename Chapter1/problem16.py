#!/usr/bin/python3

# ************************************************
# Given a binary search tree T, searches for K
# ************************************************


class Node:

    def __init__(self, key, left = None, right = None):
        self.key = key
        self.left = left
        self.right = right


    def find_first_largest(self, n):
        
        # check this node's key first
        if n < self.key:
            
            if self.left is None:
                result = None
            else:
                result = self.left.find_first_largest(n)
            
            if result is None:
                return self.key
            else:
                return result
        else:
            if self.right is not None:
                return self.right.find_first_largest(n)
            else:
                return None

            
            

        
    # inserts a number n recursively
    def insert_recursive(self, n):

        if n < self.key:
            if self.left is None:
                self.left = Node(n)
            else:
                 self.left.insert_recursive(n)

        # Greater or equal to 
        else:
            if self.right is None:
                self.right = Node(n)
            else:
                 self.right.insert_recursive(n)
            
            
    # inserts a number n iteratively
    def insert_iterative(self, n):

        T = self

        while True:

            if n < T.key:
                if T.left is None:
                    T.left = Node(n)
                    break
                else:
                    T = T.left

            else:
                if T.right is None:
                    T.right = Node(n)
                    break
                else:
                    T = T.right
                
        
    # Prints the BST recursively
    def print(self, indent = 0):

        if self.left is not None:
            self.left.print(indent+1)
 
        print(indent * "  ", self.key)
            
        if self.right is not None:
            self.right.print(indent+1)
        
    

# Recursive search through binary search tree
def search_bst_recursive(T,K):

    if T is None:
        return False
    
    if (K < T.key):
        return search_bst_recursive(T.left, K)
    elif (K > T.key):
        return search_bst_recursive(T.right, K)

    return True

# Iterative search through binary search tree
def search_bst_iter(T,K):

    while (T is not None):

        if (K < T.key):
            T = T.left
        elif (K > T.key):
            T = T.right
        else:
            return True

    return False

        
if __name__ == "__main__":

    T = Node(1, Node(0), Node(2))

    print(search_bst_recursive(T,1))
    print(search_bst_recursive(T,3))
    print(search_bst_iter(T,1))
    print(search_bst_iter(T,3))

    
    print("-----------------")
    T.print()
    print("-----------------")
    T.insert_recursive(4)
    T.print()
    print("-----------------")
    T.insert_recursive(3)
    T.print()
    print("-----------------")
    T.insert_iterative(1)
    T.print()
    print("-----------------")
    T.insert_iterative(10)
    T.print()
