/* 二进制中1的个数 */
#include <iostream>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n)
     {
         int res = 0;

         while(n)
         {
             n = n & (n-1);
             ++res;
         }
         cout<<res<<endl;
         return res;
     }

};

int main()
{
    Solution solution;
    int n = -1;
    solution.NumberOf1(n);
    return 0;
}
