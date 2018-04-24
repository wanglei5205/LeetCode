#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution{
public:
    void fun()
    {
        vector<int> temp;

        for(int i=0;i<100;++i)
            temp.push_back(i+1);
        cout<<temp[55]<<endl;
    }
};
int main()
{
    Solution solution;
    solution.fun();

    return 0;
}
