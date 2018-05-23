#include <iostream>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number)
    {
        if(number<=0)
            return 0;
        if(number ==1)
            return 1;

        int res=1;
        for(int i =2;i<=number;++i)
        {
            res = res*2;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    int n =10;
    cout<<solution.jumpFloorII(n)<<endl;
    return 0;
}
