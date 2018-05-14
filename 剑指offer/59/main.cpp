#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res; // 存储每个滑动窗口的最大值
        deque<int> s;    // 保存滑动窗口最大值数字的下标

        for(unsigned int i=0;i<num.size();++i)
        {
            // 更新队列：删除小于新元素的值
            while(s.size() && num[s.back()]<=num[i])
                s.pop_back();

            // 更新队列：更新队首元素
            if(s.size() && i-s.front()+1>size)
                s.pop_front();

            // 更新队列：新元素下标加入队列
            s.push_back(i);

            // 存储结果
            if(size&&i+1>=size)
                res.push_back(num[s.front()]);
        }
        return res;
    }
};
int main()
{
    unsigned int size = 3;
    const vector<int> num = {1,2,3,4,5,6,7,8,9};

    Solution solution;
    solution.maxInWindows(num,size);
    return 0;
}
