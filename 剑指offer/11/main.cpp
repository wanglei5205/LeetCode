#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        // 空数组
        int size = rotateArray.size();							//数组长度
        if(size == 0)
        {
            return 0;
        }

        // 非空数组
        int left = 0;											//左指针
        int right = size - 1;									//右指针
        int mid = 0;											//中间指针（未旋转时直接输出rotateArray[0]）

        while(rotateArray[left] >= rotateArray[right])
        {
            // 循环结束标志(左右指针相邻)
            if(left+1 == right)
            {
                mid = right;
                break;
            }

            // 计算中间指针位置
            mid = left + (right - left) / 2;

            /* 顺序查找 */
            // 如果无法确定中间元素是属于前面还是后面的递增子数组，只能顺序查找
            if(rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[left]){
                return MinInOrder(rotateArray, left, right);
            }

            /* 二分查找 */
            //中间元素位于前面的递增子数组，此时最小元素位于中间元素的后面
            if(rotateArray[mid] >= rotateArray[left])
                left = mid;
            //中间元素位于后面的递增子数组，此时最小元素位于中间元素的前面
            else
                right = mid;
        }
        return rotateArray[mid];
    }
private:
    //顺序寻找最小值
    int MinInOrder(vector<int> &num, int left, int right){
        int result = num[left];
        for(int i = left + 1; i < right; i++){
            if(num[i] < result){
                result = num[i];
            }
        }
        return result;
    }
};
int main()
{
    Solution solution;
    vector<int> rotateArray = {4,5,1,2,3};
    cout<<solution.minNumberInRotateArray(rotateArray)<<endl;
    return 0;
}
