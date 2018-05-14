#include <iostream>
#include <string>
using namespace std;
// 67:���ַ���ת��������

class Solution {
public:
    /*ȫ�ֱ���*/
    enum {VALID,INVALID}; // ö��Ԫ��
    int status= INVALID;  // ����Ƿ��ǷǷ�����

    /*���ܺ���*/
    int StrToInt(string str)
    {
        long long num = 0;             // �洢���
        const char* cstr = str.c_str();// ָ���ַ������ָ��(�����ַ�����

        // �ж��Ƿ��ǿ�ָ��Ϳ��ַ���""
        if( (cstr != NULL) && (*cstr != '\0') )
        {
            // �������λ
            int symbol = 1;
            if(*cstr == '-')
            {
                symbol = -1;
                cstr++;
            }
            else if(*cstr == '+')
            {
                symbol = 1;
                cstr++;
            }

            // ��������λ
            while(*cstr != '\0')
            {
                if(*cstr > '0' && *cstr < '9')
                {
                    // stringתint����
                    status = VALID;           // ���Ϊ�Ϸ�����
                    num = num*10 + (*cstr -'0');  // stringת��Ϊint����
                    cstr++;

                    // �����������
                    if( ((symbol>0) && (num > 0x7FFFFFFF)) ||((symbol<0) && (num > 0x80000000)) )
                    {
                        status = INVALID; // ������������Ϊ�Ƿ�����
                        num = 0;
                        break;
                    }
                }
                else
                {
                    status = INVALID;
                    num = 0;
                    break;
                }
            }

            // ������λ
            if(status == VALID)
                num = num * symbol;
        }
        cout<<(int)num<<endl;
        return (int)num;
    }
};
int main()
{
    string str = "-123";
    Solution solution;
    solution.StrToInt(str);
    return 0;
}
