#include <iostream>
using namespace std;
int n;
int a[105];

// ���������,����a�ǵ�һ����Ҷ�ӽڵ㣬z�ǽڵ����
void HeapAdjust(int A[], int a, int z)
{
    // �ؽ����ѣ�i�Ǹ��ڵ㣬j�����ӽڵ�
    for(int i = a, j = 2 * i; j <= z; i = j, j = 2 * i)
    {
        // ȡi�������ӽڵ��нϴ���ӽڵ�
        if(j < z && A[j + 1] > A[j])
            j++;

        if(A[i] < A[j])
            swap(A[i], A[j]);
        else
            break;
    }
}

// ���ҵ��������µ���
void HeapSort(int A[], int n)
{
    // ��һ������������ѣ�i�ǵ�һ����Ҷ�ӽڵ㣬n�ǽڵ������
    for(int i = n / 2; i >= 1; i--)
    {
        HeapAdjust(A, i, n);
    }

    for(int i = n; i >= 1; i--)
    {
        // �ڶ�����������Ԫ�أ����׺Ͷ�β��
        swap(A[1], A[i]);

        // ���������ؽ������
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
