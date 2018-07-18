/*10B ÇàÍÜÌøÌ¨½×*/
#include <iostream>
using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        // f(0)
        if(number <0)
            return 0;
        // f(1)
        if(number == 1)
            return 1;

        // f(n)
        int a = 1;
        int b = 1;
        int res = 0;
        for(int i = 2;i<=number;++i)
        {
            res = a+b;
            a = b;
            b = res;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    int n = 10;
    cout<<solution.jumpFloor(n)<<endl;
    return 0;
}
