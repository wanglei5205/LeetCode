#include <iostream>
using namespace std;

// ȫ�ֱ�������ʶ��Ч����
bool InvalidInput = false;

class Solution {
public:
    double Power(double base, int exponent)
    {
        InvalidInput = false;

        // ��Ч���룺��������,ָ���Ǹ���
        if(Equal(base,0.0) && exponent < 0)
        {
            InvalidInput = true;
            return 0.0;
        }

        // ָ��Ϊ����ָ��Ϊ�������ദ��
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

    // �ж������������Ƿ����
    bool Equal(double num1,double num2)
    {
        if((num1-num2) > -0.0000001 && (num1-num2)<0.0000001)
            return true;
        else
            return false;
    }

    // ��ʱ�临�Ӷ�O(logn)��������ָ��(�ݹ飩
    double WithUnsignedExponent(double base,unsigned int exponent)
    {
        if(exponent == 0)
            return 1;

        if(exponent == 1)
            return base;

        // �ݹ����ָ��
        double result = WithUnsignedExponent(base,exponent>>1);

        // ָ����������ż��
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
