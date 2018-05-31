/*07重建二叉树*/
#include <iostream>
using namespace std;

// 二叉树的节点结构
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
        // 递归出口
        if(pre.empty()|| vin.empty())
            return nullptr;

        // 建立根节点
        TreeNode* head = new TreeNode(pre[0]);

        // 中序遍历中根节点的索引号
        int root=0;
        for(int i=0;i<pre.size();++i)
        {
            if(vin[i] == pre[0])
            {
                root = i;
                break;
            }
        }

        // 拆分先序遍历和中序遍历
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

        // 根节点的左右子树
        head->left = reConstructBinaryTree(pre_before,vin_before);
        head->right = reConstructBinaryTree(pre_back,vin_back);

        return head;
    }
};
