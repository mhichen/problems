#!/usr/bin/python3

from problem16 import Node

#*******************************************
# Given a BST T and a key K, write a method
# that searches for the first entry larger
# than K
#*******************************************


if __name__ == "__main__":

    T = Node(1, Node(0), Node(2))
    T.print()

    print(T.find_first_largest(1))