#include <iostream>
#include <vector>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
    // 鲁棒性
    if(array.empty())return 0;

    // 辅助变量
    int cur_sum = array[0]; // cur_sum为当前和
    int max_sum = array[0]; // max_sum为最大和

    // 遍历所有元素
    for(int i = 1; i < array.size(); ++i)
    {
        // 更新cur_sum
        if(cur_sum <= 0)
            cur_sum = array[i];
        else
            cur_sum += array[i];

        // 更新max_sum
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
