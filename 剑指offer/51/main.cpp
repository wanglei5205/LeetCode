#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int count=0;
    int InversePairs(vector<int> data)
    {
        // 检查边界条件
        if(data.size() != 0)
        {
            MergeSort(data,0,data.size()-1);
        }
        return count;
    }

private:
    void MergeSort(vector<int> a, int l, int r)
    {
        /* 将长度为n的输入序列分成两个长度为n/2的子序列 */
        if (l < r)
        {
            /* 中间元素*/
            int m = (l + r) >>1;

            // 递归拆分
            MergeSort(a, l, m);
            MergeSort(a, m + 1, r);

            // 递归合并
            Merge(a, l, m, r);
        }
    }
    void Merge(vector<int> a, int l, int m, int r)
    {
        vector<int> t;
        //int p = 0;    /* p指向辅助数组 */
        int i = l;    /* i指向第一个子表 */
        int j = m + 1;/* j指向第二个子表 */

        /* 两个子表都不为空时 */
        while(i <= m && j <= r)
        {
            /* 取关键字小的元素转移至临时数组 */
            if (a[i] > a[j])
            {
                t.push_back(a[j++]);
                count=(count+m-i+1)%1000000007;
            }
            else
                t.push_back(a[i++]);
        }

        while(i <= m) t.push_back(a[i++]);/* 将非空的输入区间转移至输出区间 */
        while(j <= r) t.push_back(a[j++]);

        for (i = 0; i < t.size(); i++) a[l + i] = t[i];/* 归并完成后将结果复制到原输入数组 */
    }
};

int main()
{
    vector<int> a = {8,7,6,5,455,88,888,9999,546,46548,1315,445,554,111,5222,2264,8,331,454548};
    Solution solution;
    cout<<solution.InversePairs(a)<<endl;

    return 0;
}


