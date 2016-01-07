#include<iostream>

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
  

class Solution
{
  
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    // Create dummy head
    ListNode* dummyHead = new ListNode(0);
    ListNode* p = dummyHead;

    // As long as there are nodes left in both lists
    while ( (l1 != NULL) && (l2 != NULL) )
    {
      // If value of node at list 1 is less than that at list 2
      // then assign the next node in p as node at list 1 and increment
      if (l1->val < l2->val)
      {
	p->next = l1;
	l1 = l1->next;
      }
      else
      {
	p->next = l2;
	l2 = l2->next;
      }

      // Increment node
      p = p->next;
    } // End while loop

    if (l1 != NULL)
    {
      p->next = l1;
    }
    if (l2 != NULL){
      p->next = l2;
    }

    return dummyHead->next;
  }
  
  
};

// *******************************************************
int main()
{
  
}
  
