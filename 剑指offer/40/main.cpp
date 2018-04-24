#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    // 特殊输入
    if(input.size()<=0||k>input.size()) return vector<int>();

    // 建立用于存储结果的多重集合及多重集合的最大元素的迭代器
    multiset<int, greater<int> > res;
    multiset<int, greater<int> >::iterator res_best;

    // 遍历输入
    vector<int>::iterator input_ite = input.begin(); // 向量迭代器
    for(;input_ite!=input.end();input_ite++)
    {
        // 将前k个元素插入集合
        if(res.size()<k)
            res.insert(*input_ite);
        else
        {
            // 多重集合中最大元素的迭代器
            res_best = res.begin();
            // 比较+删除+插入
            if(*input_ite<*(res.begin()))
            {
                res.erase(res_best);
                res.insert(*input_ite);
            }
        }
    }

    return vector<int>(res.begin(),res.end());
}

int main()
{
    vector<int> input = {1,2,3,5,8,8,48,1,848,64,8,48,4384,84,384,8,4,384,222};

    vector<int> a = GetLeastNumbers_Solution(input,5);

    for(int i=0;i<a.size();++i)
        cout<<a[i]<<endl;

    return 0;
}
