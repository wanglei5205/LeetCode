#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr)
            return pHead2;
        if(pHead2 == nullptr)
            return pHead1;

        ListNode* Head= nullptr;

        if(pHead1->val <pHead2->val)
        {
            Head = pHead1;
            Head->next = Merge(pHead1->next,pHead2);
        }
        else
        {
            Head = pHead2;
            Head->next = Merge(pHead1,pHead2->next);
        }
        return Head;
    }
};
