#include <iostream>
#include <vector>
using namespace std;

// �����˻�����
class Solution {
public:
    vector<int> multiply(const vector<int>& A)
    {
        // �洢���
        int n=A.size();
        vector<int> b(n);

        // ������
        int ret;
        ret = 1;// �洢C[i]
        for(int i=0;i<n;ret*=A[i++]){
            b[i]=ret;
        }

        ret = 1;// �洢D[i]
        for(int i=n-1;i>=0;ret*=A[i--]){
            b[i]*=ret;
        }
        return b;
    }
};

int main()
{
    const vector<int> a = {1,2,3,4,5};
    Solution solution;
    solution.multiply(a);
    return 0;
}
