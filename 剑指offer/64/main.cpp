#include <iostream>
#include <iostream>
using namespace std;

// �ݹ�+�߼���Ķ�·����
class Solution {
public:
    int Sum_Solution(int n)
    {
        // �߼���Ķ�·������Ϊ�ݹ��������
        int res = n;
        n && (res += Sum_Solution(n-1));
        cout<<res<<endl;
        return res;
    }
};
int main()
{
    int n = 10;
    Solution solution;
    solution.Sum_Solution(n);
    return 0;
}
