#include <iostream>
#include <string>
using namespace std;

class Solution{
public:

    int fun1(int n,int m)
    {
        // Ïà¼Ó³ý2
        int temp =0;
        temp = (n+m)>>1;
        cout<<temp<<endl;

        temp = ((m-n)>>1) + n;
        cout<<temp<<endl;

        return temp;

    }

};

int main()
{
    int n = 100;
    int m = 200;
    Solution solution;
    solution.fun1(n,m);

    return 0;
}
