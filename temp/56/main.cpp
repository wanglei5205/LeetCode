#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // data是数组，num1是第一个孤独数字，num2是第二个孤独数字
    void FindNumsAppearOnce(vector<int> data,int *num1,int *num2)
    {
        // 特殊输入检查
        int length = data.size();
        if(length < 2)
            return;

        // 对原始数组每个元素求异或
        int resultExclusiveOR = 0;
        for(int i = 0; i < length; ++i)
            resultExclusiveOR ^= data[i];

        // 在异或结果中寻找第一个为1的位
        unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

        // 寻找只出现一次的数字num1，num2
        *num1 = *num2 = 0;
        for(int j = 0; j < length; j++)
            if(IsBit1(data[j], indexOf1))
                *num1 ^= data[j];
            else
                *num2 ^= data[j];
    }
private:

    // 找到二进制数num第一个为1的位数，比如0010，第一个为1的位数是2。
    unsigned int FindFirstBitIs1(int num){
        unsigned int indexBit = 0;
        // 只判断一个字节的
        while((num & 1) == 0 && (indexBit < 8 * sizeof(unsigned int))){
            num = num >> 1;
            indexBit++;
        }
        return indexBit;
    }

    // 判断第indexBit位是否为1
    bool IsBit1(int num, unsigned int indexBit){
        num = num >> indexBit;
        return (num & 1);
    }
};

int main()
{
    // 数组
    vector<int> data = {4,5,6,6,7,8,7,8};

    // 两个只出现一次的数字
    int a = 0;
    int b = 0;

    // 在数组中查找两个只出现一次的数字
    Solution solution;
    solution.FindNumsAppearOnce(data,&a,&b);
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}
