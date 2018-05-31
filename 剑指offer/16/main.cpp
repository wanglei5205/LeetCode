#include <iostream>
using namespace std;

// 全局变量：标识无效输入
bool InvalidInput = false;

class Solution {
public:
    double Power(double base, int exponent)
    {
        InvalidInput = false;

        // 无效输入：底数是零,指数是负数
        if(Equal(base,0.0) && exponent < 0)
        {
            InvalidInput = true;
            return 0.0;
        }

        // 指数为正和指数为负，分类处理
        double res = 0.0;
        if(exponent < 0)
        {
            res = WithUnsignedExponent(base,-exponent);
            res = 1.0/res;
        }
        else
        {
            res = WithUnsignedExponent(base,exponent);
        }
        return res;

    }

    // 判断两个浮点数是否相等
    bool Equal(double num1,double num2)
    {
        if((num1-num2) > -0.0000001 && (num1-num2)<0.0000001)
            return true;
        else
            return false;
    }

    // 以时间复杂度O(logn)求整数的指数(递归）
    double WithUnsignedExponent(double base,unsigned int exponent)
    {
        if(exponent == 0)
            return 1;

        if(exponent == 1)
            return base;

        // 递归计算指数
        double result = WithUnsignedExponent(base,exponent>>1);

        // 指数是奇数或偶数
        if(exponent & 1 == 1)
        {
            result *= result;
            result *= base;
        }
        else
        {
            result *= result;
        }

        return result;
    }
};

int main()
{
    Solution solution;
    double base = 0.0;
    int exponent = 0;
    cout<<solution.Power(base,exponent)<<endl;
    return 0;
}
