/* ¾ØÕó¸²¸Ç */
#include <iostream>
using namespace std;

class Solution {
public:
    int rectCover(int number)
    {
        if(number <= 0)
            return 0;
        if(number == 1)
            return 1;
        int a = 1;
        int b = 1;
        int res = 0;

        for(int i = 2;i<=number;++i)
        {
            res = a+b;
            a = b;
            b = res;
        }
        cout<<res<<endl;
        return res;
    }
};

int main()
{
    Solution solution;

    int n = 10;
    solution.rectCover(n);

    return 0;
}
