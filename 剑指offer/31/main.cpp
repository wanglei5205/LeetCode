#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        // �������루��ɼ�������������ȣ����������������ֲ��ظ���
        if(pushV.size()==0)
            return false;

        // �����ռ�
        stack<int> stk;

        // ѭ���ж�
        for(int i=0��int j =0;i<pushV.size();++i)
        {
            stk.push(pushV[i]);
            while(!stk.empty() && stk.top() == popV[j])
            {
                stk.pop();
                j++;
            }
        }

        // �ж�ջ�Ƿ�Ϊ��
        if(stk.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
