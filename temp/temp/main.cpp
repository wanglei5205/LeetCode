#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 查找元素k在有序数组中出现的次数
    int GetNumberOfK(vector<int>data,int k)
    {
        // 特殊输入
        if(data.size() == 0)
            return 0;

        // 计算第一次和最后一次k出现的位置
        int first = GetFirst(data,k,0,data.size()-1);
        int last = GetLast(data,k,0,data.size()-1);

        // 计算最后一次出现
        if(first!=-1 && last != -1)
            return last - first +1;

        // 没有找到元素
        return 0;
    }

    int GetFirst(vector<int> data,int k,int l,int r)
    {
        // 二分查找法（递归）
        if(l>r)
            return -1;

        //
        int mid = (l+r)>>1;

        if(k<data[mid])
            r = mid-1;
        else if(k>data[mid])
            l = mid+1;
        else
            {
                if((k!= data[mid-1] && mid>0 )|| mid == 0)
                    return mid;
                else
                    r = mid-1;
            }
        return GetFirst(data,k,l,r);
    }

    // 找到最后一个k的位置
    int GetLast(vector<int> data,int k,int l,int r)
    {
        // 递归出口
        if(l>r)
            return -1;

        // 递归查找
        int mid = (l+r)>>1;
        if(k < data[mid])
            r = mid-1;
        else if(k > data[mid])
            l = mid+1;
        else
        {
            if((k!=data[mid+1] && mid < data.size()-1 )|| mid == data.size()-1)
                return mid;
            else
                l = mid +1;
        }

        return GetLast(data,k,l,r);
    }
};

int main()
{
    int k=2;
    vector<int>data={1,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,5,6};
    Solution solution;
    cout<<solution.GetNumberOfK(data,k)<<endl;
    return 0;
}
