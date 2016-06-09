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
    // Handle special case
    if (index == 0)
    {
      push(head, newval);
    }
    else
    {
      Node* curr = *head;

      for (int i = 0; i < index-1; i++)
      {
	assert(curr != NULL);
	curr = curr->next;
      }

      assert(curr != NULL);

      push(&(curr->next), newval);
      
    }
  }

  // Given a list sorted in increasing order and a single node,
  // inserts the node into the correct sorted position in the list
  void sortedInsert(Node** head, Node* newNode)
  {
    //// Approach 1

    // // This takes care of case where empty list or
    // // inserting into beginning of head
    // if ( (*head == NULL) || (*head)->val >= newNode->val)
    // {
    //   newNode->next = *head;
    //   *head = newNode;
    // }
    // else
    // {
    //   Node* curr = *head;

    //   while ( (curr->next != NULL) && (curr->next->val < newNode->val) )
    //   {
    // 	curr = curr->next;
    //   }

    //   newNode->next = curr->next;
    //   curr->next = newNode;
	
    // }
    
    /// End Approach 1


    /// Approach 2
    // This uses a dummy node
    Node dummy(0);
    Node* curr = &dummy;
    dummy.next = *head;

    while ( (curr->next != NULL) && (curr->next->val < newNode->val) )
    {
      curr = curr->next;

    }

    newNode->next = curr->next;
    curr->next = newNode;

    *head = dummy.next;
    
    /// End Approach 2


    /// Approach 3
    /// End Approach 3
    
  }


  // Given a list, rearranges nodes so they are sorted in
  // increasing order.  It should use SortedInsert()
  void insertSort(Node** head)
  {
    Node* result = NULL;
    Node* curr = *head;
    Node* next;

    while (curr != NULL)
    {
      next = curr->next;
      sortedInsert(&result, curr);
      curr = next;

    }
    *head = result;
  }

  // Takes two lists, a and b, appends b onto the end of a
  // Then sets b to NULL
  void append(Node** a, Node** b)
  {

    // Special case if a is empty
    if (*a == NULL)
    {
      *a = *b;
    }
    else
    {
    
      Node* curr = *a;

      // advance to the end of list a
      while (curr->next != NULL)
      {
	curr = curr->next;
      }
      
      curr->next = *b;
      //curr = curr->next;
    }
    
    *b = NULL;
  }

  // Given a list, split it into two sublists: one for
  // front half, second for back half.  If odd number of
  // elements, the extra element should go in the front list
  void frontBackSplit(Node* head, Node** front, Node** back)
  {

    /// Approach 1
    // Get length of the list to get index of break off point
    int len = length(head);
    int mid = (len-1)/2;  // Cut occurs after this index

    // If there is only one element (or less) in the list
    if (len < 2)
    {
      *front = head;
      *back = NULL;
    }
    else{

      Node* curr = head;

      // Count until reach the cutoff point
      for (int i = 0; i < mid; i++){
	
	curr = curr->next;
	
      }
      
      // Cut
      *front = head;
      *back = curr->next;
      curr->next = NULL;
    }
    /// End Approach 1


    /// Approach 2
    // Use fast/slow pointer strategy

    // Take care of special case, where have 1 node or less
    if ( (head == NULL) || (head->next == NULL) )
    {
      *front = head;
      *back = NULL;
    }
    else
    {
      Node* pslow = head;
      Node* pfast = head->next;

      while(pfast != NULL)
      {

	pfast = pfast->next;
	if (pfast->next != NULL)
	{
	  pfast = pfast->next;
	  pslow = pslow->next; 
	}
	    
      }

      // Cut
      *front = head;
      *back = pslow->next;

      // Set pslow pointer to NULL
      pslow->next = NULL;
      
    }
    /// End Approach 2

  }

  // Takes a list sorted in increasing order and deletes duplicate nodes
  // Ideally, the list should be trasversed once
  void removeDuplicates(Node** head) //pointer to pointer
  {

    Node* curr = *head;

    if (curr == NULL)
    {
      return;
    }
    
    Node* todelete;

    while (curr->next != NULL)
    {
      // if current value is the same as next
      if (curr->val == curr->next->val)
      {
	todelete = curr->next;
	curr->next = curr->next->next;
	delete todelete;
      }
      curr = curr->next;
    }
    
  }


  // Takes two lists, removes front node from second list
  // and pushes it onto front of the first
  void moveNode(Node** l1, Node** l2)
  {
    // check that l1 (source) is not empty
    assert (*l2 != NULL);
    
    Node* curr = *l2;
    *l2 = (*l2)->next; // "reset" list 2's head


    curr->next = *l1;
    *l1 = curr;
    
    
  }
    
  // Takes one list and divides nodes into two smaller lists.
  // The sublists are made from alternating elements in the
  // original list; order in sublists doesn't matter
  void alternatingSplit(Node* head, Node** a, Node** b)
  {
    Node* curr = head;
    Node* acurr = NULL;
    Node* bcurr = NULL;
    
    while (curr != NULL)
    {
	moveNode(&acurr, &curr);
	if (curr != NULL)
	{
	  moveNode(&bcurr, &curr);
	}
    }

    *a = acurr;
    *b = bcurr;
  }

  // Given two lists, merge nodes together to make one list,
  // taking nodes alternately
  Node* shuffleMerge(Node* a, Node* b)
  {

    /// Approach 1 
    Node* result;
    Node* tail = result;
    result->next = NULL;

    while(1){
      if (a == NULL)
      {
	tail->next = b;
	break;
      }
      else if (b == NULL)
      {
	tail->next = a;
	break;
      }
      else{
	moveNode(&(tail->next), &a);
	tail = tail->next;
	moveNode(&(tail->next), &b);
	tail = tail->next;
      }
    }

    return (result->next);

    /// End Approach 1

  }
  
  // Takes two lists, each is sorted in increasing order
  // and merges the two into one list in increasing order
  // Should return the new list
  Node* sortedMerge(Node* a, Node* b)
  {

    Node* result;
    Node* tail = result;
    result->next = NULL;

    while(1){
      if (a == NULL)
      {
	tail->next = b;
	break;
      }
      else if (b == NULL)
      {
	tail->next = a;
	break;
      }
      //      else{

      if (a->val <= b->val)
      {
	moveNode(&(tail->next), &a);
      }
      else
      {
	moveNode(&(tail->next), &b);
      }
      tail = tail->next;
	//}
    }

    return result->next;
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
    std::cout << "Executing insertNthTest()\n";
    Node* myList = NULL;
    insertNth(&myList, 0, 13);
    std::cout << getNth(myList, 0) << "\n";
    insertNth(&myList, 1, 42);
    std::cout << getNth(myList, 1) << "\n";
    insertNth(&myList, 1, 5);
    std::cout << getNth(myList, 0) << " " << getNth(myList, 1) << "\n";
    std::cout << "\n";
    deleteList(myList);
  }

  void sortedInsertTest()
  {
    std::cout << "Executing sortedInsertTest()\n";
    Node* myList = BuildOneTwoThree();
    Node* tNode = new Node(2);
    
    sortedInsert(&myList, tNode);
    
    std::cout << getNth(myList, 0) << " "
	      << getNth(myList, 1) << " "
	      << getNth(myList, 2) << " "
	      << getNth(myList, 3) << "\n";;
    deleteList(myList);
  }

  void insertSortTest()
  {
    std::cout << "Executing insertSortedTest()\n";

    Node* myList = NULL;
    insertNth(&myList, 0, 42);
    std::cout << getNth(myList, 0) << " ";
    insertNth(&myList, 1, 13);
    std::cout << getNth(myList, 1) << " ";
    insertNth(&myList, 2, 5);
    std::cout << getNth(myList, 2) << " ";
    insertNth(&myList, 3, 10);
    std::cout << getNth(myList, 3) << "\n";
    
    insertSort(&myList);
    std::cout << getNth(myList, 0) << " "
    	      << getNth(myList, 1) << " "
    	      << getNth(myList, 2) << " "
    	      << getNth(myList, 3) << "\n";;

    
    deleteList(myList);
  }

  void removeDuplicatesTest()
  {
    std::cout << "Executing removeDuplicatesTest \n";
    Node* myList = NULL;
    insertNth(&myList, 0, 42);
    std::cout << getNth(myList, 0) << " ";
    insertNth(&myList, 1, 13);
    std::cout << getNth(myList, 1) << " ";
    insertNth(&myList, 2, 14);
    std::cout << getNth(myList, 2) << " ";
    insertNth(&myList, 3, 15);
    std::cout << getNth(myList, 3) << "\n";

    removeDuplicates(&myList);
    std::cout << getNth(myList, 0) << " "
	      << getNth(myList, 1) << " "
	      << getNth(myList, 2) << " "
       	      << getNth(myList, 3) << "\n";

    
    deleteList(myList);

    
      
  }

  void moveNodeTest()
  {

    std::cout << "Executing moveNodeTest \n";
    Node* a = BuildOneTwoThree();
    Node* b = BuildOneTwoThree();

    moveNode(&a,&b);

    std::cout << getNth(a, 0) << " "
    	      << getNth(a, 1) << " "
    	      << getNth(a, 2) << " "
       	      << getNth(a, 3) << "\n";
    deleteList(a);
    deleteList(b);

  }

  void alternatingSplitTest()
  {
    std::cout << "Executing alternatingSplitTest \n";
    Node* source = BuildOneTwoThree();
    Node* a;
    Node* b;

    alternatingSplit(source, &a, &b);

    std::cout << getNth(a, 0) << " "
    	      << getNth(a, 1) << "\n"
    	      << getNth(b, 0) << "\n";
    deleteList(source);
    deleteList(a);
    deleteList(b);
  }
  
  void sortedMergeTest()
  {
    std::cout << "Executing sortedMergeTest \n";
    Node* a = BuildOneTwoThree();
    Node* b = NULL;
    insertNth(&b, 0, 12);
    insertNth(&b, 1, 13);
    insertNth(&b, 2, 14);
    insertNth(&b, 3, 15);
 
    std::cout << "Built b \n";
    std::cout << "\n\n";
    std::cout << "Before sorted merge \n";
    Node* c = sortedMerge(a, b);
    std::cout << "After sorted merge \n";

    for (int i = 0; i < length(c); i++){

      std::cout << getNth(c, i) << " ";
	
    }
    std::cout << "\n";

    deleteList(a);
    deleteList(b);
    deleteList(c);
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
  tsol.sortedInsertTest();
  tsol.insertSortTest();
  tsol.removeDuplicatesTest();
  //tsol.moveNodeTest();
  //tsol.alternatingSplitTest();
  tsol.sortedMergeTest();
}
  
