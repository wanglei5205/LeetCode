#include<iostream>
using namespace std;

void replace_space(int length,char *str);

int main()
{   int length = 25;
    char a[length]="123 456 7 8 9 ";
    for(int i=0;i<length;i++)
        cout<<a[i]<<endl;
    replace_space(length,a);
    return 0;

}
void replace_space(int length,char *str)
{
    // �߽��������գ�
    if(str!=NULL)
    {
        // ͳ�Ƹ���
        int count_space = 0;// �ո����
        int count_old = 0;  // �滻ǰ�ַ�����
        int count_new = 0;  // �滻���ַ�����

        while(*str!='\0')
        {
            ++count_old;
            if(*str==' ')
                ++count_space;
            str++;
        }

        count_new = count_old + 2*count_space;

        cout<<count_space<<endl;
        cout<<count_old<<endl;
        cout<<count_new<<endl;

        // �߽�������Խ�磩
        if(count_new<length)
        {
            cout<<"���Ե�"<<endl;
            char *p1=str+count_old;
            char *p2=str+count_new;

            while(p1<p2)
            {
                if(*p1!=' ')
                    *p2--=*p1;
                else
                {
                    *p2--='0';
                    *p2--='2';
                    *p2--='%';
                }
                --p1;
            }
        }
        str=str-count_old;
        for(int j=0;j<count_new;j++)
        {
            cout<<str[j]<<endl;
        }
    }

}
