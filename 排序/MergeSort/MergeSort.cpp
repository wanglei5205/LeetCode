#include <iostream>
#define N 105
using namespace std;
int n;
int a[N], t[N];

/* �� */
//�±��0��ʼ
void Merge(int a[], int l, int m, int r)
{
    // pָ����ʱ����
    int p = 0;
    // iָ���һ���ӱ�
    int i = l;
    // jָ��ڶ����ӱ�
    int j = m + 1;

    /* �����ӱ���Ϊ��ʱ */
    while(i <= m && j <= r)
    {
        /* ȡ�ؼ���С��Ԫ��ת������ʱ���� */
        if (a[i] > a[j])
            t[p++] = a[j++];
        else
            t[p++] = a[i++];
    }

    /* ���ǿյ���������ת����������� */
    while(i <= m) t[p++] = a[i++];
    while(j <= r) t[p++] = a[j++];

    /* �鲢��ɺ󽫽�����Ƶ�ԭ�������� */
    for (i = 0; i < p; i++)
        a[l + i] = t[i];
}

/* �� */
void MergeSort(int a[], int l, int r)
{
    /* ������Ϊn���������зֳ���������Ϊn/2�������� */
    if (l < r)
    {
        /* �м�Ԫ��*/
        int m = (l + r) / 2;

        // �ݹ���
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);

        // �ݹ�ϲ�
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
