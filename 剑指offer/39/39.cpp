#include <iostream>
#include <vector>
using namespace std;
int fun(vector<int> num)
{
    // 鲁棒性
    if(num.size() == 0)
        return 0;

    // 查找
    int res = num[0];
    int cnt = 1;

    for(int i=1;i<num.size();++i)
    {
        if(num[i]==res)
            ++cnt;
        else
            --cnt;

        if(cnt == 0)
        {
            res = num[i];
            ++cnt;
        }
    }

    // 验证
    cnt = 0;
    for(int i = 0;i<num.size();++i)
        if(res == num[i])
            ++cnt;
    cout<<cnt<<endl;
    if(cnt*2 > num.size())
        return res;
    else
        return 0;
}
int main()
{
    vector<int> num ={1,2,3,3,2,2,2,222};
    cout<<fun(num)<<endl;
    return 0;
}
