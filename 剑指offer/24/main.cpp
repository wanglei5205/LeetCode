// ·­×ªÁ´±í
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        ListNode* left = nullptr;
        ListNode* node = pHead;
        ListNode* right = nullptr;
        ListNode* ReverseHead = nullptr;
        while(node!=nullptr)
        {
            right = node->next;

            if(right == nullptr)
                ReverseHead = node;

            node->next = left;

            left = node;
            node = right;
        }
        return ReverseHead;
    }
};
