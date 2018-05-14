#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res; // �洢ÿ���������ڵ����ֵ
        deque<int> s;    // ���滬���������ֵ���ֵ��±�

        for(unsigned int i=0;i<num.size();++i)
        {
            // ���¶��У�ɾ��С����Ԫ�ص�ֵ
            while(s.size() && num[s.back()]<=num[i])
                s.pop_back();

            // ���¶��У����¶���Ԫ��
            if(s.size() && i-s.front()+1>size)
                s.pop_front();

            // ���¶��У���Ԫ���±�������
            s.push_back(i);

            // �洢���
            if(size&&i+1>=size)
                res.push_back(num[s.front()]);
        }
        return res;
    }
};
int main()
{
    unsigned int size = 3;
    const vector<int> num = {1,2,3,4,5,6,7,8,9};

    Solution solution;
    solution.maxInWindows(num,size);
    return 0;
}
