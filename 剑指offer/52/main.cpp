#include <iostream>
using namespace std;

/* 链表节点结构如下*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

/* 两个链表的第一个公共节点 */
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        // 计算链表长度
        int len1 = Lenth(pHead1);
        int len2 = Lenth(pHead2);

        // 链表尾部对齐
        if(len1 > len2)
            pHead1 = firstNode(pHead1,len1-len2);
        else
            pHead2 = firstNode(pHead2,len2-len1);

        // 查找公共结点
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
    // 测试用例
    /* */

    // 调用函数
    Solution solution;
    cout<<solution.FindFirstCommonNode(pHead1,pHead2)<<endl;
}
