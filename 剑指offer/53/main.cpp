#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // ����Ԫ��k�����������г��ֵĴ���
    int GetNumberOfK(vector<int> data ,int k)
    {
        // ��������
        if(data.size() == 0)
            return 0;
        cout<<data.size()<<endl;

        // �����������в���k��һ�γ��ֵ�λ��
        int first = GetFirstK(data,k,0,data.size()-1);
        cout<<first<<endl;

        // �����������в���k���һ�γ��ֵ�λ��
        int last = GetLastK(data,k,0,data.size()-1);
        cout<<last<<endl;

        // �������
        if(first != -1 && last != -1)
            return last-first+1;

        // δ�ҵ�Ԫ��
        return 0;
    }

    // ���ֲ��ҷ������ҵ�һ��k��λ��
    int GetFirstK(vector<int> data,int k,int l,int r)
    {
        // �ݹ����
        if(l>r)
            return -1;

        int mid = (l+r)>>1;

        if(k<data[mid])
        {
            r = mid-1;
        }
        else if (k>data[mid])
        {
            l = mid+1;
        }
        else
        {
            if((mid>0 && data[mid-1] != k) || mid == 0)
                return mid;
            else
                r = mid-1;
        }
        return GetFirstK(data,k,l,r);
    }

    // ���ֲ��ҷ����������һ��k��λ��
    int GetLastK(vector<int> data,int k,int l,int r)
    {
        if(l>r)
            return -1;

        int mid = (l+r)>>1;

        if(k<data[mid])
            r = mid-1;
        else if(k>data[mid])
            l = mid+1;
        else
        {
            if((mid < data.size()-1 && data[mid+1]!=k) || mid == data.size()-1)
                return mid;
            else
                l = mid+1;
        }
        return GetLastK(data,k,l,r);
    }
};
int  main()
{
    cout << "���ֲ��ҷ���������k�����������г��ֵĴ���" << endl;
    // ������
    vector<int> arr1;
    // �����в��������ҵ�����
    vector<int> arr2 = {1,3,5,7,9,10};
    // �����а������ҵ����飨����һ�Σ�
    vector<int> arr3 = {1,2,2,2,2,3,3,3,4,5};
    // �����а������ҵ����飨���ֶ�Σ�
    vector<int> arr4 = {1,2,3,4,4,4,7,8,9,10};
    Solution solution;
    cout<<solution.GetNumberOfK(arr1,4)<<endl;

    return 10086;
}
