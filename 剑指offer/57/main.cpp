#include <iostream>
#include <vector>
using namespace std;
/* 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得他们的和正好是s。如果有多对数字的和等于s，输入任意一对即可*/

class Solution{
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum)
    {
        // 存储结果
        vector<int> res;

        // 特殊输入
        if(array.size() <= 1)
            return res;

        // 辅助变量
        int p = 0;
        int q = array.size()-1;
        int Sum = 0;
        // 查找结果
        while(p<q)
        {
            Sum = array[p] + array[q];

            if(Sum == sum)
            {
                res.push_back(array[p]);
                res.push_back(array[q]);
                cout<<array[p]<<endl;
                cout<<array[q]<<endl;
                break;
            }

            if(Sum < sum)
                ++p;
            else
                --q;
        }
        return res;
    }
};
int main()
{
    vector<int> data={1,2,4,7,11,13,14};
    int s =15;
    Solution solution;
    solution.FindNumbersWithSum(data,s);

    return 0;
}
