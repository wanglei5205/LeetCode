#include <iostream>
#include <vector>
using namespace std;

// �ȶ��Ľⷨ
class Solution_stable{
public:
    void ReArray(vector<int > &array)
    {
        // ��������
        if(array.size() == 0 || array.size() == 1)
            return;

        // ð������
        for(int i = 0;i < array.size();++i)
            for(int j = array.size()-1;j>i;--j)
                if(array[j]%2 == 1 && array[j-1]%2 ==0)
                    swap(array[j],array[j-1]);
    }
};

// ���ȶ��Ľⷨ
class Solution_no_stable{
public:
    void ReArray(int *array2,int length)
    {
        // ��������
        if(array2 == nullptr || length == 0)
            return;

        // ָ���������
        int *pLeft = array2;
        int *pRight = array2 + length-1;

        while(pLeft<pRight)
        {
            // ����ƶ�pLeft��ֱ��ָ��ż��
            while(pLeft<pRight && (*pLeft & 1) == 1)
                pLeft++;

            // ��ǰ�ƶ�pRight��ֱ��ָ������
            while(pLeft<pRight && (*pRight & 1) == 0)
                pRight--;

            // ��ż������
            if(pLeft < pRight)
                swap(*pLeft,*pRight);
        }
    }
};
int main()
{
    // �ȶ��Ľⷨ
    cout<<"�ȶ��Ľⷨ"<<endl;
    Solution_stable solution1;
    vector<int> array = {1,2,3,4,5,6,7,8,9,10};
    solution1.ReArray(array);

    for(int i = 0;i<array.size();++i)
        cout<<array[i]<<endl;

    // ���ȶ��Ľⷨ
    cout<<"���ȶ��Ľⷨ"<<endl;
    Solution_no_stable solution2;
    int length = 10;
    int array2[10] = {1,2,3,4,5,6,7,8,9,10};
    solution2.ReArray(array2,length);

    for(int i = 0;i<length;i++)
        cout<<array2[i]<<endl;
    return 0;
}
