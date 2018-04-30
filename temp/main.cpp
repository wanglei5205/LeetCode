#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void fun1(vector<int> data,int* num1,int* num2)
    {
        // 特殊输入检查
        int len = data.size();
        if(len<2)
        {
            return ;
        }

        // 依次对数组元素进行异或操作，得到异或结果
        int res = data[0];
        for(int i=1;i<len;++i)
        {
            res^=data[i];
        }
        cout<<"res="<<res<<endl;

        // 在异或结果中寻找第一个为1的位
        int first = find_first_one_bit(res);
        cout<<"first="<<first<<endl;

        // 对原数组分组并寻找孤独元素
        *num1 = *num2 = 0;
        for(int i = 0;i<len;++i)
        {
            if(is_bit1(first,data[i]))
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
        cout<<"num1="<<*num1<<endl;
        cout<<"num2="<<*num2<<endl;

    }
private:

    // 移位次数
    int find_first_one_bit(int res)
    {
        int first = 0;
        while(((res & 1) == 0 ) && (first < 8 * sizeof(int)))
        {
            res = res>>1;
            ++first;
        }

        return first;
    }

    // 分组
    bool is_bit1(int first,int num)
    {

        cout<<"原始data[i]"<<num<<endl;
        num = num>>first;
        cout<<"移位后data[i]"<<num<<endl;
        return (num & 1);
    }
};

int main()
{
    // 输入
    int num1=0;// 存储第一个孤独数字
    int num2=0;// 存储第二个孤独数字
    vector<int> data = {2,4,3,6,3,2,5,5};

    // 寻找孤独数字
    Solution solution;
    solution.fun1(data,&num1,&num2);

    return 0;
}
