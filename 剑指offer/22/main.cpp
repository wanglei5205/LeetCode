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
        // 特殊输入
        if(pListHead == nullptr || k == 0)
            return nullptr;

        /* 遍历俩表 */
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
