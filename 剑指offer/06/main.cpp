/* 06 ��β��ͷ��ӡ����*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ����ڵ�ṹ
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        // �洢���
        vector<int> res;
        stack<int> stk;

        // ��������Ԫ����ջ
        while(head != nullptr)
        {
            stk.push(head->val);
            head = head->next;
        }

        // ����ջ��Ԫ�ش�������
        while(!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }

        return res;
    }
};
int main()
{
    // ��������

    // ��β��ͷ��ӡ����
    Solution solution;
    solution.printListFromTailToHead(head);

    return 0;
}
