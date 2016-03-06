#include<iostream>

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
  

class Solution
{
  
public:
  ListNode* swapNodesInPairs(ListNode* l1){

    // Create dummy head
    ListNode* dummyHead = new ListNode(0);

    dummyHead->next = l1;

    // Let p be current node
    ListNode* p = l1;
    ListNode* prev = dummyHead;

    while ( (p != NULL) && p->next != NULL)
    {
      // Let q be next, and r be next-next
      ListNode* q = p -> next;
      ListNode* r = p -> next -> next;

      // This sets up for after the swap since the
      // new previous's next will be q
      prev -> next = q;

      // This is where the swapping occurs
      q -> next = p;
      p -> next = r;

      prev = p;  // Why is this not q?
      p = r; 
    }
    return dummyHead->next;
  }
    


    

  
  
};

// *******************************************************
int main()
{
  
}
  
