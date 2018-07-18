#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        // ��������
        if(pListHead == nullptr || k == 0)
            return nullptr;

        /* �������� */
        ListNode* head = pListHead;
        ListNode* behind = pListHead;

        for(int i=0;i<k-1;++i)
        {
            if(head->next == nullptr)
                return nullptr;
            else
                return head = head->next;
        }

        while(behind->next != nullptr)
        {
            head = head->next;
            behind = behind->next;
        }
        return behind;
    }
};
