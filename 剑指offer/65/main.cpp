#include <iostream>
using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int res,carry;
        do{
            // ��һ���������ǽ�λ���ӷ�����������
            res = num1^num2;

            // �ڶ��������Ǽӷ��Ľ�λ����λ��+����1λ��
            carry = (num1&num2)<<1;

            // ����������һ���͵ڶ������
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
