#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // data�����飬num1�ǵ�һ���¶����֣�num2�ǵڶ����¶�����
    void FindNumsAppearOnce(vector<int> data,int *num1,int *num2)
    {
        // ����������
        int length = data.size();
        if(length < 2)
            return;

        // ��ԭʼ����ÿ��Ԫ�������
        int resultExclusiveOR = 0;
        for(int i = 0; i < length; ++i)
            resultExclusiveOR ^= data[i];

        // ���������Ѱ�ҵ�һ��Ϊ1��λ
        unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

        // Ѱ��ֻ����һ�ε�����num1��num2
        *num1 = *num2 = 0;
        for(int j = 0; j < length; j++)
            if(IsBit1(data[j], indexOf1))
                *num1 ^= data[j];
            else
                *num2 ^= data[j];
    }
private:

    // �ҵ���������num��һ��Ϊ1��λ��������0010����һ��Ϊ1��λ����2��
    unsigned int FindFirstBitIs1(int num){
        unsigned int indexBit = 0;
        // ֻ�ж�һ���ֽڵ�
        while((num & 1) == 0 && (indexBit < 8 * sizeof(unsigned int))){
            num = num >> 1;
            indexBit++;
        }
        return indexBit;
    }

    // �жϵ�indexBitλ�Ƿ�Ϊ1
    bool IsBit1(int num, unsigned int indexBit){
        num = num >> indexBit;
        return (num & 1);
    }
};

int main()
{
    // ����
    vector<int> data = {4,5,6,6,7,8,7,8};

    // ����ֻ����һ�ε�����
    int a = 0;
    int b = 0;

    // �������в�������ֻ����һ�ε�����
    Solution solution;
    solution.FindNumsAppearOnce(data,&a,&b);
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}
