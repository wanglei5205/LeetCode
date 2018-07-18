/*10A 循环计算裴波那切数列*/
#include <iostream>
using namespace std;

class Solution {
public:
    int Fibonacci(int n)
    {
        if(n <= 0)
            return 0;

        if(n == 1)
            return 1;

        int a = 0;
        int b = 1;
        int res = 0;
        for(int i = 2;i<=n;++i)
        {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }//fun
};

int main()
{
    Solution solution;

    int n = 10;
    cout<<solution.Fibonacci(n)<<endl;

    return 0;
}
