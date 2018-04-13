#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    // ��������
    if(input.size()<=0||k>input.size()) return vector<int>();

    // �������ڴ洢����Ķ��ؼ��ϼ����ؼ��ϵ����Ԫ�صĵ�����
    multiset<int, greater<int> > res;
    multiset<int, greater<int> >::iterator res_best;

    // ��������
    vector<int>::iterator input_ite = input.begin(); // ����������
    for(;input_ite!=input.end();input_ite++)
    {
        // ��ǰk��Ԫ�ز��뼯��
        if(res.size()<k)
            res.insert(*input_ite);
        else
        {
            // ���ؼ��������Ԫ�صĵ�����
            res_best = res.begin();
            // �Ƚ�+ɾ��+����
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
