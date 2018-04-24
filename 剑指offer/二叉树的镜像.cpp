# include<iostream>
# include<vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        // 二叉树有0个节点
        if(pRoot==nullptr)
            return;

        // 二叉树有1个界定啊
        if(pRoot->left==nullptr&&pRoot->right==nullptr)
            return;

        // 二叉树有多个节点时，交换当前节点的左右节点
        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;

        // 二叉树遍历
        if(pRoot->left!=nullptr)
            Mirror(pRoot->left);

        if(pRoot->right!=nullptr)
            Mirror(pRoot->right);
    }
};

int main()
{
    // 测试用例

    //
    Solution solution;
    solution.Mirror();
}
