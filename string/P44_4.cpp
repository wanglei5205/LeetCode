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
    // 边界条件（空）
    if(str!=NULL)
    {
        // 统计个数
        int count_space = 0;// 空格个数
        int count_old = 0;  // 替换前字符个数
        int count_new = 0;  // 替换后字符个数

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

        // 边界条件（越界）
        if(count_new<length)
        {
            cout<<"测试点"<<endl;
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
