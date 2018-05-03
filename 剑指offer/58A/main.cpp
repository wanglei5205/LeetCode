#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str)
    {
        // 特殊输入
        int len=str.length();
        if(len==0) return "";

        // 使用翻转函数翻转整个句子
        Reverse(str,0,len-1);
        cout<<"句子翻转"<<endl;
        cout<<str<<endl;

        // 寻找单词并使用翻转内函数翻转单词
        int i=0;//辅助变量
        int j=0;//辅助变量

        while(i<len)
        {
            // 寻找单词开头
            if(str[i]==' ')
            {
                i++;
                j++;
            }

            // 寻找单词结尾
            if(str[j]!=' ' && str[j]!='\0')
            {
                j++;
            }
            else
            {
                Reverse(str,i,--j);
                i=++j;
            }
            cout<<"i="<<i<<endl;
            cout<<"j="<<j<<endl;
            cout<<str<<endl;
        }
        return str;
    }

    // 翻转函数
    void Reverse(string &str,int pstart,int pend)
    {
        while(pstart < pend)
        {
            char temp=str[pstart];
            str[pstart]=str[pend];
            str[pend]=temp;

            pstart++;
            pend--;
        }
    }
};
int main()
{
    string str = "I am a student.";
    Solution solution;
    solution.ReverseSentence(str);
    return 0;
}
