#include <iostream>
using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int res,carry;
        do{
            // 第一步：不考虑进位做加法（异或操作）
            res = num1^num2;

            // 第二步：考虑加法的进位（按位与+左移1位）
            carry = (num1&num2)<<1;

            // 第三步：第一步和第二步相加
            num1 = res;
            num2 = carry;

        }while(num2 != 0);

        return num1;
    }
};
int main()


{
    Solution solution;
    solution.Add(-8,-4);
    return 0;
}
