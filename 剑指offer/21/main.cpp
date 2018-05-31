#include <iostream>
#include <vector>
using namespace std;

// 稳定的解法
class Solution_stable{
public:
    void ReArray(vector<int > &array)
    {
        // 特殊输入
        if(array.size() == 0 || array.size() == 1)
            return;

        // 冒泡排序
        for(int i = 0;i < array.size();++i)
            for(int j = array.size()-1;j>i;--j)
                if(array[j]%2 == 1 && array[j-1]%2 ==0)
                    swap(array[j],array[j-1]);
    }
};

// 不稳定的解法
class Solution_no_stable{
public:
    void ReArray(int *array2,int length)
    {
        // 特殊输入
        if(array2 == nullptr || length == 0)
            return;

        // 指针遍历数组
        int *pLeft = array2;
        int *pRight = array2 + length-1;

        while(pLeft<pRight)
        {
            // 向后移动pLeft，直到指向偶数
            while(pLeft<pRight && (*pLeft & 1) == 1)
                pLeft++;

            // 向前移动pRight，直到指向奇数
            while(pLeft<pRight && (*pRight & 1) == 0)
                pRight--;

            // 奇偶数交换
            if(pLeft < pRight)
                swap(*pLeft,*pRight);
        }
    }
};
int main()
{
    // 稳定的解法
    cout<<"稳定的解法"<<endl;
    Solution_stable solution1;
    vector<int> array = {1,2,3,4,5,6,7,8,9,10};
    solution1.ReArray(array);

    for(int i = 0;i<array.size();++i)
        cout<<array[i]<<endl;

    // 不稳定的解法
    cout<<"不稳定的解法"<<endl;
    Solution_no_stable solution2;
    int length = 10;
    int array2[10] = {1,2,3,4,5,6,7,8,9,10};
    solution2.ReArray(array2,length);

    for(int i = 0;i<length;i++)
        cout<<array2[i]<<endl;
    return 0;
}
