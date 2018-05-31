#include <iostream>
using namespace std;
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication)
    {
        /* ���������� */
        // ������/����С��0
        if(numbers == nullptr || length <= 0)
            return false;

        // ����Ԫ�ز��������
        for(int i=0; i<length;++i)
        {
            if(numbers[i]<0 || numbers[i]>length-1)
                return false;
        }

        /* �ҳ�����һ���ظ�Ԫ��*/
        for(int i=0;i<length;i++)
        {
            while(numbers[i]!=i)
            {
                // �����ظ�Ԫ��
                if(numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                else
                {
                    int temp = numbers[i];
                    numbers[i] = numbers[temp];
                    numbers[temp] = temp;
                }

            }
        }
        return false;
    }
};
int main()
{
    /* �����б� */
    int numbers[7] = {3,1,2,0,0,5,3};
    int length = 7;
    int *duplication;

    /* �� */
    Solution solution;
    cout<<solution.duplicate(numbers,length,duplication)<<endl;
    cout<<*duplication<<endl;
    return 0;
}
