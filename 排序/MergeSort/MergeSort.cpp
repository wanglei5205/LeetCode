#include <iostream>
#define N 105
using namespace std;
int n;
int a[N], t[N];

/* 治 */
//下标从0开始
void Merge(int a[], int l, int m, int r)
{
    // p指向临时数组
    int p = 0;
    // i指向第一个子表
    int i = l;
    // j指向第二个子表
    int j = m + 1;

    /* 两个子表都不为空时 */
    while(i <= m && j <= r)
    {
        /* 取关键字小的元素转移至临时数组 */
        if (a[i] > a[j])
            t[p++] = a[j++];
        else
            t[p++] = a[i++];
    }

    /* 将非空的输入区间转移至输出区间 */
    while(i <= m) t[p++] = a[i++];
    while(j <= r) t[p++] = a[j++];

    /* 归并完成后将结果复制到原输入数组 */
    for (i = 0; i < p; i++)
        a[l + i] = t[i];
}

/* 分 */
void MergeSort(int a[], int l, int r)
{
    /* 将长度为n的输入序列分成两个长度为n/2的子序列 */
    if (l < r)
    {
        /* 中间元素*/
        int m = (l + r) / 2;

        // 递归拆分
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);

        // 递归合并
        Merge(a, l, m, r);
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    MergeSort(a, 0, n - 1);

    for(int i = 0; i < n; i++) cout << a[i] << " ";

    return 0;
}
