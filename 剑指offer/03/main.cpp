#include <iostream>
using namespace std;
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication)
    {
        /* 特殊输入检查 */
        // 空数组/长度小于0
        if(numbers == nullptr || length <= 0)
            return false;

        // 数组元素不符合题干
        for(int i=0; i<length;++i)
        {
            if(numbers[i]<0 || numbers[i]>length-1)
                return false;
        }

        /* 找出任意一个重复元素*/
        for(int i=0;i<length;i++)
        {
            while(numbers[i]!=i)
            {
                // 查找重复元素
                if(numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                else
                {
                    int temp = numbers[i];
                    numbers[i] = numbers[temp];
                    numbers[temp] = temp;
                }

            }
        }
        return false;
    }
};
int main()
{
    /* 参数列表 */
    int numbers[7] = {3,1,2,0,0,5,3};
    int length = 7;
    int *duplication;

    /* 类 */
    Solution solution;
    cout<<solution.duplicate(numbers,length,duplication)<<endl;
    cout<<*duplication<<endl;
    return 0;
}
