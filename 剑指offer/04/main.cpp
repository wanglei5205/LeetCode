/* 04 二维数组中的查找*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    bool fun(vector<vector<int>> arr,int target)
    {
        // 特殊输入
        if(!arr.empty())
        {
            // 行列个数
            int row = arr.size();
            int col = arr[0].size();

            // 右上角坐标
            int a = 0;
            int b = col-1;

            while(a<row && b>=0)
            {
                // 找到
                if(arr[a][b] == target)
                    return true;

                // 未找到
                if(arr[a][b] < target)
                    ++a;
                else
                    --b;
            }
        }

        return false;
    }
};
int main()
{
    Solution solution;

    // 特殊输入
    vector<vector<int>> arr1;
    int target1 = 11;
    cout<<solution.fun(arr1,target1)<<endl;

    // 正常输入
    vector<vector<int>> arr2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int target2 = 11;
    cout<<solution.fun(arr2,target2)<<endl;
    return 0;
}
