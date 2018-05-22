/* 08二叉树的下一个节点（中序遍历）*/
#include <iostream>
using namespace std;

class Solution{
public:
    // 返回值：节点的下一个节点的地址
    // 参数值：节点
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        // 判断节点是否是空指针
        if(pNode == nullptr)
            return nullptr;

        // 节点有右子节点
        if(pNode->right != nullptr)
        {
            TreeLinkNode* temp = pNode->right;
            while(temp->left!=nullptr)
            {
                temp = temp->left;
            }
            res = temp;
        }
        else if(pNode->next != nullptr)
        {
            TreeLinkNode* parent = pNode->next;
            while(parent->right == pNode && parent != nullptr)
            {
                parent = parent->next;
                pNode = pNode->next;
            }
            res = parent;
        }
        return res;
    }
};
int main()
{
    return 0;
}
