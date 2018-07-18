#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}
void three_parameter(vector<int> vec)
{
    sort(vec.begin(),vec.end(),cmp);

    for(int i=0;i<vec.size();++i)
        cout<<vec[i]<<endl;
}

void two_parameter(vector<int> vec)
{
    sort(vec.begin(),vec.end());

    for(int i=0;i<vec.size();++i)
        cout<<vec[i]<<endl;

}
int main()
{
    vector<int> vec = {1,5,9,1,4,2,8,55,121};

    two_parameter(vec);
    three_parameter(vec);

    return 0;
}
