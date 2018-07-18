#include <iostream>
#include <vector>
using namespace std;

// 一次快速排序
int partition(vector<int> &a, int low, int high)
{
    // 枢轴值（线性表第一个元素作为枢轴值）
    int key = a[low];
    while(low < high)
    {
        // 从右侧找小于pivot的值，替换low位置的元素
        while(low < high && a[high] >= key)
            --high;
        a[low] = a[high];

        // 从左侧找大于pivot的值，替换high位置的元素
        while(low < high && a[low] <= key)
            ++low;
        a[high] = a[low];
    }
    a[low] = key;

    return low;// 返回一趟排序后确定的元素位置
}

//快速排序的递归形式
void QuickSort(vector<int> &a, int low, int high)
{
    if(low < high)// 递归出口
    {
        int loc = partition(a, low, high);//一趟排序结果的调用
        QuickSort(a, low, loc-1);
        QuickSort(a, loc+1, high);
    }
}

int main()
{
    vector<int> a={46,79,56,38,40,84};
    QuickSort(a, 0, a.size()-1);

    // 打印排序后的数组
    for(int i=0;i<a.size();++i)
        cout<<a[i]<<' ';

    return 0;
}
