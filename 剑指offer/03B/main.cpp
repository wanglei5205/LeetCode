#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int duplication(vector<int> vec)
    {
        // 空数组
        int length = vec.size();
        if(vec.size() == 0)
        {
            cout<<"空数组"<<endl;
            return -1;
        }

        // 数字超界
        for(int i =0;i<length;++i)
        {
            if(vec[i]<1 || vec[i]>length-1)
            {
                cout<<"数字超界"<<endl;
                return -1;
            }

        }
        // 定义数字范围
        int begin = 1;
        int end = length-1;

        // 指定数字范围内的数字个数
        while(begin<=end)
        {
            // 计算数字范围的中点
            int mid = (begin + end)>>1;

            // 统计指定数字范围内的数字个数
            int count = countrange(vec,begin,mid,length);

            if(end > begin)
            {
                // 更新数字范围
                if(count>(mid - begin + 1))
                    end = mid;
                else
                    begin = mid + 1;
            }
            else
            {
                if(count > 1)
                    return begin;
                else
                    break;
            }
        }

        return -1;
    }

    int countrange(vector<int> vec,int begin,int end,int length)
    {
        int count=0;
        for(int i=0;i<length;++i)
        {
            if(vec[i]>=begin && vec[i]<=end)
                ++count;
        }

        return count;
    }
};

int main()
{
    vector<int> vec ;
    vector<int> vec1 = {1,2,3,4,5,6,7};
    vector<int> vec2 = {1,1,2,3,4,5,6};
    vector<int> vec3 = {2,2,3,3,4,5,6};


    Solution solution;
    cout<<solution.duplication(vec)<<endl;
    cout<<solution.duplication(vec1)<<endl;
    cout<<solution.duplication(vec2)<<endl;
    cout<<solution.duplication(vec3)<<endl;

    return 0;
}
