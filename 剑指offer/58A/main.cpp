#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str)
    {
        // ��������
        int len=str.length();
        if(len==0) return "";

        // ʹ�÷�ת������ת��������
        Reverse(str,0,len-1);
        cout<<"���ӷ�ת"<<endl;
        cout<<str<<endl;

        // Ѱ�ҵ��ʲ�ʹ�÷�ת�ں�����ת����
        int i=0;//��������
        int j=0;//��������

        while(i<len)
        {
            // Ѱ�ҵ��ʿ�ͷ
            if(str[i]==' ')
            {
                i++;
                j++;
            }

            // Ѱ�ҵ��ʽ�β
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

    // ��ת����
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
