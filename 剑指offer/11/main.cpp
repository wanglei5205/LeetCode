#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        // ������
        int size = rotateArray.size();							//���鳤��
        if(size == 0)
        {
            return 0;
        }

        // �ǿ�����
        int left = 0;											//��ָ��
        int right = size - 1;									//��ָ��
        int mid = 0;											//�м�ָ�루δ��תʱֱ�����rotateArray[0]��

        while(rotateArray[left] >= rotateArray[right])
        {
            // ѭ��������־(����ָ������)
            if(left+1 == right)
            {
                mid = right;
                break;
            }

            // �����м�ָ��λ��
            mid = left + (right - left) / 2;

            /* ˳����� */
            // ����޷�ȷ���м�Ԫ��������ǰ�滹�Ǻ���ĵ��������飬ֻ��˳�����
            if(rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[left]){
                return MinInOrder(rotateArray, left, right);
            }

            /* ���ֲ��� */
            //�м�Ԫ��λ��ǰ��ĵ��������飬��ʱ��СԪ��λ���м�Ԫ�صĺ���
            if(rotateArray[mid] >= rotateArray[left])
                left = mid;
            //�м�Ԫ��λ�ں���ĵ��������飬��ʱ��СԪ��λ���м�Ԫ�ص�ǰ��
            else
                right = mid;
        }
        return rotateArray[mid];
    }
private:
    //˳��Ѱ����Сֵ
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
