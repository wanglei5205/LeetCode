#include <iostream>
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber)
    {
        if(root) dfsFind(root, expectNumber);

        return allRes;
    }

    void dfsFind(TreeNode * node , int target)
    {
        tmp.push_back(node->val);

        if(!node->left && !node->right)
        {
            if(target - node->val == 0)
                allRes.push_back(tmp);
        }
        else
        {
            if(node->left) dfsFind(node->left, target - node->val);
            if(node->right) dfsFind(node->right, target - node->val);
        }

        if(!tmp.empty())
            tmp.pop_back();
    }
private:
    vector<vector<int> >allRes;
    vector<int> tmp;
};
