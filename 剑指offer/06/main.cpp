/* 06 从尾到头打印链表*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 链表节点结构
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
        // 存储结果
        vector<int> res;
        stack<int> stk;

        // 遍历链表，元素入栈
        while(head != nullptr)
        {
            stk.push(head->val);
            head = head->next;
        }

        // 遍历栈，元素存入向量
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
    // 建立链表

    // 从尾到头打印链表
    Solution solution;
    solution.printListFromTailToHead(head);

    return 0;
}
