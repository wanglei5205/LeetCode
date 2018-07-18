/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == nullptr || pRoot2 == nullptr)
            return false;

        return DFS(pRoot1,pRoot2) || HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2);
    }

private:
    bool DFS(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(pRoot2 == nullptr)
            return true;
        if(pRoot1 == nullptr)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        else
            return DFS(pRoot1->left,pRoot2->left) &&DFS(pRoot1->right,pRoot2->right);
    }
};
