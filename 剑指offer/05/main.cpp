/* 05 替换空格 */
#include <iostream>
using namespace std;
class Solution{
public:
    void replaceSpace(char *str,int length)
    {
        if(str!= nullptr && length>0)
        {
            // 统计空格个数，替换前字符个数，替换后字符个数
            int str_before = 0;
            int str_back = 0;
            int str_black = 0;

            for(int i =0;str[i] != '\0';++i)
            {
                ++str_before;
                if(str[i] == ' ')
                    ++str_black;
            }

            str_back = str_before + 2*str_black;

            if(str_back+1<=length)
            {
                // 遍历变量
                char *p = str + str_before;
                char *q = str + str_back;

                while(p != q)
                {
                    if(*p == ' ')
                    {
                        *q-- = '0';
                        *q-- = '2';
                        *q-- = '%';
                        p--;
                    }
                    else
                    {
                        *q-- = *p--;
                    }
                }
            }
        }
    }
};
int main()
{
    Solution solution;
    // 字符数组
    int length=100;
    char str[length] = {"a b c "};
    solution.replaceSpace(str,length);

    // 打印字符数组
    for(int i =0;str[i] != '\0';++i)
        cout<<str[i]<<endl;
    return 0;
}
