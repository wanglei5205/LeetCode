#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers )
    {
        // 特殊输入()
        if(numbers.size() != 5) return 0;

        // 每个元素出现的次数;以numbers中的元素作为下标(最大K,对应13)
        int count[14]={0};

        // 辅助变量
        int len=numbers.size();
        int max=-1;
        int min=14;

        // 判断
        for(int i=0;i<len;++i)
        {
            count[numbers[i]]++;
            if(numbers[i]==0) continue;
            // 保证没有重复的牌
            if(count[numbers[i]]>1) return 0;

            if(numbers[i]>max) max=numbers[i];
            if(numbers[i]<min) min=numbers[i];

        }//end for

        if(max-min<5) return 1;

        return 0;

    }//end IsContinuous()
};

int main()
{
    vector<int> numbers = {1,2,3,5,0};
    Solution solution;
    cout<<solution.IsContinuous(numbers)<<endl;
    return 0;
}
