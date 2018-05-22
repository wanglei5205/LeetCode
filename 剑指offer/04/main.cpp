/* 04 ��ά�����еĲ���*/
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    bool fun(vector<vector<int>> arr,int target)
    {
        // ��������
        if(!arr.empty())
        {
            // ���и���
            int row = arr.size();
            int col = arr[0].size();

            // ���Ͻ�����
            int a = 0;
            int b = col-1;

            while(a<row && b>=0)
            {
                // �ҵ�
                if(arr[a][b] == target)
                    return true;

                // δ�ҵ�
                if(arr[a][b] < target)
                    ++a;
                else
                    --b;
            }
        }

        return false;
    }
};
int main()
{
    Solution solution;

    // ��������
    vector<vector<int>> arr1;
    int target1 = 11;
    cout<<solution.fun(arr1,target1)<<endl;

    // ��������
    vector<vector<int>> arr2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int target2 = 11;
    cout<<solution.fun(arr2,target2)<<endl;
    return 0;
}
