#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers )
    {
        // ��������()
        if(numbers.size() != 5) return 0;

        // ÿ��Ԫ�س��ֵĴ���;��numbers�е�Ԫ����Ϊ�±�(���K,��Ӧ13)
        int count[14]={0};

        // ��������
        int len=numbers.size();
        int max=-1;
        int min=14;

        // �ж�
        for(int i=0;i<len;++i)
        {
            count[numbers[i]]++;
            if(numbers[i]==0) continue;
            // ��֤û���ظ�����
            if(count[numbers[i]]>1) return 0;

            if(numbers[i]>max) max=numbers[i];
            if(numbers[i]<min) min=numbers[i];

        }//end for

        if(max-min<5) return 1;

        return 0;

    }//end IsContinuous()
};

int main()
{
    vector<int> numbers = {1,2,3,5,0};
    Solution solution;
    cout<<solution.IsContinuous(numbers)<<endl;
    return 0;
}
