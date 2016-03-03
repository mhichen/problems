#include<iostream>
#include<assert.h>

struct Node{
  int val;
  struct Node* next;
  
  Node(int x) : val(x), next(NULL) {}
};
  

class Solution
{
  
public:

  Node* BuildOneTwoThree()
  {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;
    third->next = NULL;

    return head;
    
  }
  
  // Calculates the length of the linked list
  int length(Node* head)
  {
    int count = 0;
    Node* curr = head;
    
    while(curr != NULL)
    {
      count++;
      curr = curr->next;
    }
    
    return count;
  }

  // Counts the number of times a given int occurs in a list
  int count(Node* head, int target)
  {
    int count = 0;
    Node* curr = head;

    while (curr != NULL)
    {
      if (curr->val == target)
      {
	count++;
      }

      curr = curr->next;
    }
    
    return count;

  }

  // Gets the N-th node value
  int getNth(Node* head, int index)
  {
    
    int count = 0;
    Node* curr = head;

    while (curr != NULL)
    {
      if (count == index)
      {
	return curr->val;
      }
      count++;
      curr = curr->next;
    }

    assert(0);
  }

  // Deallocates all of memory and sets head pointer to NULL
  void deleteList(Node* head)
  {
    Node* curr = head;
    Node* next;
    
    while(curr != NULL)
    {
      next = curr->next;
      delete curr;
      curr = next;
    }
    
    head = NULL;
      
  }

  // Given a reference to the head of a list and an int, pushes
  // a new node on the front of the list.  Creates new node with
  // the int, links the list to the .next of the new node
  void push(Node** head, int newval)
  {
    Node* newNode = new Node(newval);
    
    newNode->next = (*head);

    *head = newNode;
  }
  
  // takes a non-empty list, deletes the head node,
  // returns the head node's data
  int pop(Node** head)
  {
    int result;
    Node* curr = *head;

    assert(curr != NULL);

    result = curr->val;
    *head = curr->next;

    delete curr;

    return result;
  }

  // insert new node at any index
  void insertNth(Node** head, int index, int newval)
  {
    Node* newNode = new Node(newval);
    Node* curr = *head;
    push(head, 0); // Insert dummy node at the very beginning
    
    Node* prev = *head; // this is a dummy node

    int count = 0;
    prev->next = curr;
    
    //for (int i = 0; i <= index; i++){
    while (prev != NULL)
    {
      if (count == index){

	prev->next = newNode;
	newNode->next = curr;

	pop(head); // remove dummy node
	return;
      }

      prev = curr;
      curr = curr->next;
      count++;
    }

    pop(head);
    assert(0);
    
  }
  
  //**************************************//
  //*************  Tests  ***************//
  void countTest()
  {
    std::cout << "Executing countTest()\n";
    Node* myList = BuildOneTwoThree();
    int tcount = count(myList, 2);
    std::cout << "Count " << tcount << "\n";
    deleteList(myList);
    std::cout << "\n";
  }
  
  void getNthTest()
  {
    std::cout << "Executing getNthTest()\n";
    Node* myList = BuildOneTwoThree();
    int value = getNth(myList, 2);
    std::cout << "Value of 2-th index is " << value << "\n";
    deleteList(myList);
    std::cout << "\n";
  }

  void pushTest()
  {
    std::cout << "Executing pushTest()\n";
    Node* myList = BuildOneTwoThree();
    push(&myList, 5);
    std::cout << getNth(myList, 0) << "\n";
    std::cout << getNth(myList, 1) << "\n";
    std::cout << getNth(myList, 2) << "\n";
    std::cout << getNth(myList, 3) << "\n";
    deleteList(myList);
    std::cout << "\n";
  }

  void popTest()
  {
    std::cout << "Executing popTest()\n";
    Node* myList = BuildOneTwoThree();
    int a = pop(&myList);
    int b = pop(&myList);
    int c = pop(&myList);
    int len = length(myList);

    std::cout << "In popTest \n"
      "a = " << a << "\n"
      "b = " << b << "\n"
      "c = " << c << "\n"
      "len(myList) = " << len << "\n";
    
    std::cout << "\n";
  }

  void insertNthTest()
  {
    Node* myList = NULL;
    insertNth(&myList, 0, 13);
    std::cout << getNth(myList, 0) << "\n";
    insertNth(&myList, 1, 42);
    std::cout << getNth(myList, 1) << "\n";
    insertNth(&myList, 1, 5);
    std::cout << getNth(myList, 0) << " " << getNth(myList, 1) << "\n";
  
  }
  
};

// *******************************************************
int main()
{
  Solution tsol;
  tsol.countTest();
  tsol.getNthTest();
  tsol.pushTest();
  tsol.popTest();
  tsol.insertNthTest();
}
  
