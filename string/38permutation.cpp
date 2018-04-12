#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Permutation(vector<string> &result, string str, int begin)
{
    // 递归出口
    if(begin==str.size()-1)
    {
        result.push_back(str);
        cout<<str<<endl;
    }

    for(int i=begin; i<=str.size()-1;++i)
    {
        // 去重
        if(i!=begin && str[i]==str[begin]) continue;

        // 全排列
        swap(str[i], str[begin]);
        Permutation(result, str, begin+1);
        swap(str[i],   str[begin]);
    }
}

vector<string> Permutation(string str) {
    // 存储结果
    vector<string> result;
    // 边界条件
    if(str.size()==0) return result;
    // 递归实现字符串的字典序全排列
    Permutation(result, str, 0);
    // 调整顺序
    sort(result.begin(), result.end());
    // 返回结果
    return result;
}

int main()
{
    cout << "Hello world!" << endl;
    string str="abcd";
    Permutation(str);
    return 0;
}
