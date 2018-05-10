#include <iostream>
#include <vector>
using namespace std;

// 构建乘积数组
class Solution {
public:
    vector<int> multiply(const vector<int>& A)
    {
        // 存储结果
        int n=A.size();
        vector<int> b(n);

        // 计算结果
        int ret;
        ret = 1;// 存储C[i]
        for(int i=0;i<n;ret*=A[i++]){
            b[i]=ret;
        }

        ret = 1;// 存储D[i]
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
