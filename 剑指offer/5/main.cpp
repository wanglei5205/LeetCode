#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int count=0;
    int InversePairs(vector<int> data)
    {
        // ���߽�����
        if(data.size() != 0)
        {
            MergeSort(data,0,data.size()-1);
        }
        return count;
    }

private:
    void MergeSort(vector<int> a, int l, int r)
    {
        /* ������Ϊn���������зֳ���������Ϊn/2�������� */
        if (l < r)
        {
            /* �м�Ԫ��*/
            int m = (l + r) >>1;

            // �ݹ���
            MergeSort(a, l, m);
            MergeSort(a, m + 1, r);

            // �ݹ�ϲ�
            Merge(a, l, m, r);
        }
    }
    void Merge(vector<int> a, int l, int m, int r)
    {
        vector<int> t;
        //int p = 0;    /* pָ�������� */
        int i = l;    /* iָ���һ���ӱ� */
        int j = m + 1;/* jָ��ڶ����ӱ� */

        /* �����ӱ���Ϊ��ʱ */
        while(i <= m && j <= r)
        {
            /* ȡ�ؼ���С��Ԫ��ת������ʱ���� */
            if (a[i] > a[j])
            {
                t.push_back(a[j++]);
                count=(count+m-i+1)%1000000007;
            }
            else
                t.push_back(a[i++]);
        }

        while(i <= m) t.push_back(a[i++]);/* ���ǿյ���������ת����������� */
        while(j <= r) t.push_back(a[j++]);

        for (i = 0; i < t.size(); i++) a[l + i] = t[i];/* �鲢��ɺ󽫽�����Ƶ�ԭ�������� */
    }
};

int main()
{
    int n=0;
    cin>>n;

    vector<int> a;

    for(int i=0;i<n;i++)
    {
        int temp=0;
        cin>>temp;
        a.push_back(temp);
    }
    Solution solution;
    cout<<solution.InversePairs(a)<<endl;

    return 0;
}


