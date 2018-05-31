/*07�ؽ�������*/
#include <iostream>
using namespace std;

// �������Ľڵ�ṹ
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
    {
        // �ݹ����
        if(pre.empty()|| vin.empty())
            return nullptr;

        // �������ڵ�
        TreeNode* head = new TreeNode(pre[0]);

        // ��������и��ڵ��������
        int root=0;
        for(int i=0;i<pre.size();++i)
        {
            if(vin[i] == pre[0])
            {
                root = i;
                break;
            }
        }

        // �������������������
        vector<int> pre_before,pre_back,vin_before,vin_back;
        for(int i=0;i<root;++i)
        {
            pre_before.push_back(pre[i+1]);
            vin_before.push_back(vin[i]);
        }

        for(int i=root+1;i<pre.size();++i)
        {
            pre_back.push_back(pre[i]);
            vin_back.push_back(vin[i]);
        }

        // ���ڵ����������
        head->left = reConstructBinaryTree(pre_before,vin_before);
        head->right = reConstructBinaryTree(pre_back,vin_back);

        return head;
    }
};
