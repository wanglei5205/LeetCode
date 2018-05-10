#include <iostream>
#include <iostream>
using namespace std;

// 递归+逻辑与的短路特性
class Solution {
public:
    int Sum_Solution(int n)
    {
        // 逻辑与的短路特性作为递归结束条件
        int res = n;
        n && (res += Sum_Solution(n-1));
        cout<<res<<endl;
        return res;
    }
};
int main()
{
    int n = 10;
    Solution solution;
    solution.Sum_Solution(n);
    return 0;
}
