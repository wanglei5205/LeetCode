#include <iostream>
using namespace std;
int n;
int a[105];
//下标从1开始
void HeapAdjust(int A[], int a, int z)
{
    int i, j;
    for(i = a, j = 2 * i; j <= z; i = j, j = 2 * i)
    { //i为父，j为子
        if(j < z && A[j + 1] > A[j]) j++;   //大顶堆，沿大孩子方向下行
        if(A[i] < A[j])
            swap(A[i], A[j]);
        else break;
    }
}
void HeapSort(int A[], int n)
{
    int i;
    for(i = n / 2; i >= 1; i--) //从倒数第一个非叶子结点，自下而上堆化
        HeapAdjust(A, i, n);
    for(i = n; i > 1; i--)
    { //交换A[1]与最后元素A[i]（i=n, ..., 1）, 再堆化
        swap(A[1], A[i]);
        HeapAdjust(A, 1, i - 1);
    }
}
int main()
{
    int i;
    cin >> n;
    for(i = 1; i <= n; i++)
    cin >> a[i];
    HeapSort(a, n);
    for(i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
