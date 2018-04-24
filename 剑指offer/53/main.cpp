#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 查找元素k在有序数组中出现的次数
    int GetNumberOfK(vector<int> data ,int k)
    {
        // 特殊输入
        if(data.size() == 0)
            return 0;
        cout<<data.size()<<endl;

        // 在有序数组中查找k第一次出现的位置
        int first = GetFirstK(data,k,0,data.size()-1);
        cout<<first<<endl;

        // 在有序数组中查找k最后一次出现的位置
        int last = GetLastK(data,k,0,data.size()-1);
        cout<<last<<endl;

        // 计算次数
        if(first != -1 && last != -1)
            return last-first+1;

        // 未找到元素
        return 0;
    }

    // 二分查找法，查找第一个k的位置
    int GetFirstK(vector<int> data,int k,int l,int r)
    {
        // 递归出口
        if(l>r)
            return -1;

        int mid = (l+r)>>1;

        if(k<data[mid])
        {
            r = mid-1;
        }
        else if (k>data[mid])
        {
            l = mid+1;
        }
        else
        {
            if((mid>0 && data[mid-1] != k) || mid == 0)
                return mid;
            else
                r = mid-1;
        }
        return GetFirstK(data,k,l,r);
    }

    // 二分查找法，查找最后一个k的位置
    int GetLastK(vector<int> data,int k,int l,int r)
    {
        if(l>r)
            return -1;

        int mid = (l+r)>>1;

        if(k<data[mid])
            r = mid-1;
        else if(k>data[mid])
            l = mid+1;
        else
        {
            if((mid < data.size()-1 && data[mid+1]!=k) || mid == data.size()-1)
                return mid;
            else
                l = mid+1;
        }
        return GetLastK(data,k,l,r);
    }
};
int  main()
{
    cout << "二分查找法计算数字k在排序数组中出现的次数" << endl;
    // 空数组
    vector<int> arr1;
    // 数组中不包含查找的数字
    vector<int> arr2 = {1,3,5,7,9,10};
    // 数组中包含查找的数组（出现一次）
    vector<int> arr3 = {1,2,2,2,2,3,3,3,4,5};
    // 数组中包含查找的数组（出现多次）
    vector<int> arr4 = {1,2,3,4,4,4,7,8,9,10};
    Solution solution;
    cout<<solution.GetNumberOfK(arr1,4)<<endl;

    return 10086;
}
