#include <iostream>
#include <vector>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
    // ³����
    if(array.empty())return 0;

    // ��������
    int cur_sum = array[0]; // cur_sumΪ��ǰ��
    int max_sum = array[0]; // max_sumΪ����

    // ��������Ԫ��
    for(int i = 1; i < array.size(); ++i)
    {
        // ����cur_sum
        if(cur_sum <= 0)
            cur_sum = array[i];
        else
            cur_sum += array[i];

        // ����max_sum
        if(cur_sum > max_sum)
            max_sum = cur_sum;

    }

    return max_sum;
}

int main()
{
    vector<int> arr = {1,-2,3,10,-4,7,2,-5};
    int temp = FindGreatestSumOfSubArray(arr);
    cout<<temp<<endl;
    return 0;
}
