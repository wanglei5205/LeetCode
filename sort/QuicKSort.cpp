#include <iostream>
#include <vector>
using namespace std;

// һ�ο�������
int partition(vector<int> &a, int low, int high)
{
    // ����ֵ�����Ա��һ��Ԫ����Ϊ����ֵ��
    int key = a[low];
    while(low < high)
    {
        //
        while(low < high && a[high] >= key)
            --high;
        a[low] = a[high];

        //
        while(low < high && a[low] <= key)
            ++low;
        a[high] = a[low];
    }
    a[low] = key;
    return low;
}

//��������ĵݹ���ʽ
void QuickSort(vector<int> &a, int low, int high)
{
    if(low < high)
    {
        int loc = partition(a, low, high);//һ���������ĵ���
        QuickSort(a, low, loc-1);
        QuickSort(a, loc+1, high);
    }
}
int main()
{
    vector<int> a={46,79,56,38,40,84};
    QuickSort(a, 0, a.size()-1);
    for(int i=0;i<a.size();++i) cout<<a[i]<<' ';
    return 0;
}
