#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        // 特殊输入（题干假设两个序列相等，并假设序列中数字不重复）
        if(pushV.size()==0)
            return false;

        // 辅助空间
        stack<int> stk;

        // 循环判断
        for(int i=0，int j =0;i<pushV.size();++i)
        {
            stk.push(pushV[i]);
            while(!stk.empty() && stk.top() == popV[j])
            {
                stk.pop();
                j++;
            }
        }

        // 判断栈是否为空
        if(stk.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
