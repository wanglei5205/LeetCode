#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // ����Ԫ��k�����������г��ֵĴ���
    int GetNumberOfK(vector<int>data,int k)
    {
        // ��������
        if(data.size() == 0)
            return 0;

        // �����һ�κ����һ��k���ֵ�λ��
        int first = GetFirst(data,k,0,data.size()-1);
        int last = GetLast(data,k,0,data.size()-1);

        // �������һ�γ���
        if(first!=-1 && last != -1)
            return last - first +1;

        // û���ҵ�Ԫ��
        return 0;
    }

    int GetFirst(vector<int> data,int k,int l,int r)
    {
        // ���ֲ��ҷ����ݹ飩
        if(l>r)
            return -1;

        //
        int mid = (l+r)>>1;

        if(k<data[mid])
            r = mid-1;
        else if(k>data[mid])
            l = mid+1;
        else
            {
                if((k!= data[mid-1] && mid>0 )|| mid == 0)
                    return mid;
                else
                    r = mid-1;
            }
        return GetFirst(data,k,l,r);
    }

    // �ҵ����һ��k��λ��
    int GetLast(vector<int> data,int k,int l,int r)
    {
        // �ݹ����
        if(l>r)
            return -1;

        // �ݹ����
        int mid = (l+r)>>1;
        if(k < data[mid])
            r = mid-1;
        else if(k > data[mid])
            l = mid+1;
        else
        {
            if((k!=data[mid+1] && mid < data.size()-1 )|| mid == data.size()-1)
                return mid;
            else
                l = mid +1;
        }

        return GetLast(data,k,l,r);
    }
};

int main()
{
    int k=2;
    vector<int>data={1,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,5,6};
    Solution solution;
    cout<<solution.GetNumberOfK(data,k)<<endl;
    return 0;
}
