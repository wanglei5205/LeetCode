#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string LeftRotateString(string &str, int n)
    {
        int len = str.size();
        // 特殊输入
        if(!str.empty() && n <= len && n >= 0)
        {

            int pFirstStart = 0;
            int pFirstEnd = n - 1;
            int pSecondStart = n;
            int pSecondEnd = len - 1;

            // 翻转字符串的前面n个字符
            reverse(str, pFirstStart, pFirstEnd);
            // 翻转字符串的后面部分
            reverse(str, pSecondStart, pSecondEnd);
            // 翻转整个字符串
            reverse(str, pFirstStart, pSecondEnd);

        }
        return str;
    }

    // 翻转函数
    void reverse(string &str, int begin, int end)
    {
        while(begin < end)
        {
            char tmp = str[begin];
            str[begin] = str[end];
            str[end] = tmp;
            begin++;
            end--;
        }
    }
};

int main()
{
    // 测试用例
    string str = "abcdefg";
    int n = 2;

    // 函数调用
    Solution solution;
    solution.LeftRotateString(str,n);
    cout<<str<<endl;
    return 0;
}
