// 43题：把数组排成最小的数
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 升序排序
static bool cmp(int a, int b)
{
    string A = to_string(a) + to_string(b);
    string B = to_string(b) + to_string(a);
    return A < B;
}

string PrintMinNumber(vector<int> numbers)
{
    // 存储
    string res;

    if(numbers.size() == 0) return "";

    // 排序
    sort(numbers.begin(), numbers.end(), cmp);
    for(int i =0;i<numbers.size();++i)
        cout<<numbers[i]<<endl;
    // 拼接
    for(int i = 0;i < numbers.size();++i)
        res += to_string(numbers[i]);

    return res;
}

int main()
{
    vector<int> numbers = {7,32,51};
    string res = PrintMinNumber(numbers);
    cout<<res<<endl;
    return 0;
}
