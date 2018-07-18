#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix)
    {
        vector<int> res;

        if(matrix.empty())
            return res;

        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = col-1;
        int top = 0;
        int btm = row-1;

        while(left<=right &&top<=btm)
        {
            for(int i = left;i<=right;++i)
                res.push_back(matrix[top][i]);

            if(top<btm)
                for(int i=top+1;i<=btm;++i)
                    res.push_back(matrix[i][right]);

            if(top<btm &&left<right)
                for(int i=right-1;i>=left;--i)
                    res.push_back(matrix[btm][i]);

            if(top+1<btm && left<right)
                for(int i=btm-1;i>=top+1;--i)
                    res.push_back(matrix[i][left]);
            left++;right--;top++;btm--;
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = {{1,2,3,4},
                                  {12,13,14,5},
                                  {11,16,15,6},
                                  {10,9,8,7}};

    vector<int> res = solution.printMatrix(matrix);
    for(int i = 0;i<res.size();++i)
        cout<<res[i]<<endl;

    return 0;
}
