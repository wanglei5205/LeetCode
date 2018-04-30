#include <iostream>
#include <vector>
using namespace std;
/* ����һ����������������һ������s���������в�����������ʹ�����ǵĺ�������s������ж�����ֵĺ͵���s����������һ�Լ���*/

class Solution{
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum)
    {
        // �洢���
        vector<int> res;

        // ��������
        if(array.size() <= 1)
            return res;

        // ��������
        int p = 0;
        int q = array.size()-1;
        int Sum = 0;
        // ���ҽ��
        while(p<q)
        {
            Sum = array[p] + array[q];

            if(Sum == sum)
            {
                res.push_back(array[p]);
                res.push_back(array[q]);
                cout<<array[p]<<endl;
                cout<<array[q]<<endl;
                break;
            }

            if(Sum < sum)
                ++p;
            else
                --q;
        }
        return res;
    }
};
int main()
{
    vector<int> data={1,2,4,7,11,13,14};
    int s =15;
    Solution solution;
    solution.FindNumbersWithSum(data,s);

    return 0;
}
