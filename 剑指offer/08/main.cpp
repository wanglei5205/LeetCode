/* 08����������һ���ڵ㣨���������*/
#include <iostream>
using namespace std;

class Solution{
public:
    // ����ֵ���ڵ����һ���ڵ�ĵ�ַ
    // ����ֵ���ڵ�
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        // �жϽڵ��Ƿ��ǿ�ָ��
        if(pNode == nullptr)
            return nullptr;

        // �ڵ������ӽڵ�
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
