#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string LeftRotateString(string &str, int n)
    {
        int len = str.size();
        // ��������
        if(!str.empty() && n <= len && n >= 0)
        {

            int pFirstStart = 0;
            int pFirstEnd = n - 1;
            int pSecondStart = n;
            int pSecondEnd = len - 1;

            // ��ת�ַ�����ǰ��n���ַ�
            reverse(str, pFirstStart, pFirstEnd);
            // ��ת�ַ����ĺ��沿��
            reverse(str, pSecondStart, pSecondEnd);
            // ��ת�����ַ���
            reverse(str, pFirstStart, pSecondEnd);

        }
        return str;
    }

    // ��ת����
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
    // ��������
    string str = "abcdefg";
    int n = 2;

    // ��������
    Solution solution;
    solution.LeftRotateString(str,n);
    cout<<str<<endl;
    return 0;
}
