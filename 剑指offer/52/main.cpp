#include <iostream>
using namespace std;

/* ����ڵ�ṹ����*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

/* ��������ĵ�һ�������ڵ� */
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        // ����������
        int len1 = Lenth(pHead1);
        int len2 = Lenth(pHead2);

        // ����β������
        if(len1 > len2)
            pHead1 = firstNode(pHead1,len1-len2);
        else
            pHead2 = firstNode(pHead2,len2-len1);

        // ���ҹ������
        while(pHead1!=nullptr)
        {
            if(pHead1 == pHead2)
                return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }

        return nullptr;

    }
    int Lenth(ListNode * p)
    {
        int temp = 0;
        while(p!=nullptr)
        {
            temp++;
            p = p->next;
        }
        return temp;
    }

    ListNode *firstNode(ListNode *tempNode,int diff)
    {
        while(diff--)
        {
            tempNode = tempNode->next;
        }
        return tempNode;
    }
};

void main()
{
    // ��������
    /* */

    // ���ú���
    Solution solution;
    cout<<solution.FindFirstCommonNode(pHead1,pHead2)<<endl;
}
