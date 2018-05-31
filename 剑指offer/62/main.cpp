#include <iostream>
using namespace std;

class Solution {
public:
    // n表示多少个人，m表示随机数
    int LastRemaining_Solution(int n, int m)
    {
        // 特殊输入
        if(n == 0 || m < 0) return -1;

        // 递推公式计算
        int res = 0;
        for(int i = 2; i <= n; ++i)
        {
            res = (res + m)%i;
            cout<<res<<endl;
        }
        return res;
    }
};
int main()
{
    int n = 7;
    int m = 3;
    Solution solution;
    solution.LastRemaining_Solution(n,m);
    return 0;
}
