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
        // ��������0���ڵ�
        if(pRoot==nullptr)
            return;

        // ��������1���綨��
        if(pRoot->left==nullptr&&pRoot->right==nullptr)
            return;

        // �������ж���ڵ�ʱ��������ǰ�ڵ�����ҽڵ�
        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;

        // ����������
        if(pRoot->left!=nullptr)
            Mirror(pRoot->left);

        if(pRoot->right!=nullptr)
            Mirror(pRoot->right);
    }
};

int main()
{
    // ��������

    //
    Solution solution;
    solution.Mirror();
}
