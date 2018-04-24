#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 返回第index丑数的值
int GetUglyNumber_Solution(int index) {
    // 特殊输入检查
    if (index < 7)return index;

    // 辅助空间：存储结果
    vector<int> res(index);
    res[0] = 1;

    // 辅助变量：三类数字的下标
    int t2 = 0, t3 = 0, t5 = 0;

    for (int i = 1; i < index; ++i)
    {
        // 计算丑数
        res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));

        // 更新辅助变量
        if (res[i] == res[t2] * 2)t2++;
        if (res[i] == res[t3] * 3)t3++;
        if (res[i] == res[t5] * 5)t5++;
    }
    return res[index - 1];
}

int main()
{
    int n = 7;
    cout<<GetUglyNumber_Solution(n)<<endl;
    return 0;
}
