#include <iostream>
using namespace std;
int n;
int a[105];
//�±��1��ʼ
void HeapAdjust(int A[], int a, int z)
{
    int i, j;
    for(i = a, j = 2 * i; j <= z; i = j, j = 2 * i)
    { //iΪ����jΪ��
        if(j < z && A[j + 1] > A[j]) j++;   //�󶥶ѣ��ش��ӷ�������
        if(A[i] < A[j])
            swap(A[i], A[j]);
        else break;
    }
}
void HeapSort(int A[], int n)
{
    int i;
    for(i = n / 2; i >= 1; i--) //�ӵ�����һ����Ҷ�ӽ�㣬���¶��϶ѻ�
        HeapAdjust(A, i, n);
    for(i = n; i > 1; i--)
    { //����A[1]�����Ԫ��A[i]��i=n, ..., 1��, �ٶѻ�
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
