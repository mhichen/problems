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
    ListNode* p = l1, *q = l2, *curr = dummyHead;

    int carry = 0;

    // Needs to be OR since one list could be longer than the other
    while ( (p != NULL) || (q != NULL) )
    {
      int x = (p != NULL) ? p->val : 0;
      int y = (q != NULL) ? q->val: 0;
      int dummyval = x + y + carry;

      carry = dummyval / 10;

      curr->next = new ListNode(dummyval % 10);
      curr = curr->next;

      if (p != NULL)
      {
	p = p->next;
      }

      if (q != NULL)
      {
	q = q->next;
      }
    } // End of while

    if (carry > 0){
      curr->next = new ListNode(carry);
    }

    return dummyHead->next;
  }
  
  
};

// *******************************************************
int main()
{
  
}
  
