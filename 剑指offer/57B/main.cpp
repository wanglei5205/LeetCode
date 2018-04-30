#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {

        // 结果
        vector<vector<int> > res;

        // 特殊输入
        if(sum<3)
            return res;

        // 辅助变量
        int small = 1;
        int big = 2;
        int middle = (sum+1)>>1;

        while(small < middle)
        {
            // count
            int count =0;
            for(int i = small;i<=big;++i)
                count +=i;

            //
            if(count == sum)
            {
                // 存储结果
                vector<int> temp;
                for(int i = small ;i <= big;++i)
                {
                    cout<<i<<endl;
                    temp.push_back(i);
                }

                res.push_back(temp);

                ++small;
                ++big;
            }

            if(count<sum)
                ++big;
            else
                ++small;
        }

        return res;
    }
};
int main()
{
    int sum = 100;
    Solution solution;
    solution.FindContinuousSequence(sum);
    return 0;
}
