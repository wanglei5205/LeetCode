#include <iostream>
using namespace std;
int n;
int a[105];

// 构建大根堆,其中a是第一个非叶子节点，z是节点个数
void HeapAdjust(int A[], int a, int z)
{
    // 重建最大堆，i是父节点，j是左子节点
    for(int i = a, j = 2 * i; j <= z; i = j, j = 2 * i)
    {
        // 取i的左右子节点中较大的子节点
        if(j < z && A[j + 1] > A[j])
            j++;

        if(A[i] < A[j])
            swap(A[i], A[j]);
        else
            break;
    }
}

// 从右到做，从下到上
void HeapSort(int A[], int n)
{
    // 第一步：建立大根堆（i是第一个非叶子节点，n是节点个数）
    for(int i = n / 2; i >= 1; i--)
    {
        HeapAdjust(A, i, n);
    }

    for(int i = n; i >= 1; i--)
    {
        // 第二步：交换堆元素（堆首和堆尾）
        swap(A[1], A[i]);

        // 第三步：重建大根堆
        HeapAdjust(A, 1, i - 1);
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    cin >> a[i];
    HeapSort(a, n);
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    cout<<a[0]<<endl;
    return 0;
}
