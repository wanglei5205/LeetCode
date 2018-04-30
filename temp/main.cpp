#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void fun1(vector<int> data,int* num1,int* num2)
    {
        // ����������
        int len = data.size();
        if(len<2)
        {
            return ;
        }

        // ���ζ�����Ԫ�ؽ������������õ������
        int res = data[0];
        for(int i=1;i<len;++i)
        {
            res^=data[i];
        }
        cout<<"res="<<res<<endl;

        // ���������Ѱ�ҵ�һ��Ϊ1��λ
        int first = find_first_one_bit(res);
        cout<<"first="<<first<<endl;

        // ��ԭ������鲢Ѱ�ҹ¶�Ԫ��
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

    // ��λ����
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

    // ����
    bool is_bit1(int first,int num)
    {

        cout<<"ԭʼdata[i]"<<num<<endl;
        num = num>>first;
        cout<<"��λ��data[i]"<<num<<endl;
        return (num & 1);
    }
};

int main()
{
    // ����
    int num1=0;// �洢��һ���¶�����
    int num2=0;// �洢�ڶ����¶�����
    vector<int> data = {2,4,3,6,3,2,5,5};

    // Ѱ�ҹ¶�����
    Solution solution;
    solution.fun1(data,&num1,&num2);

    return 0;
}
