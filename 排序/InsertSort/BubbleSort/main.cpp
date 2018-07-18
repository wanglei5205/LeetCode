#include<iostream>
#include<vector>
using namespace std;

void BubbleSort(vector<int> vec)
{
    // 辅助空间
    int temp = 0;

    for(int i=0;i<vec.size()-1;++i)        // 边界条件
    {
        for(int j=0;j<vec.size()-i-1;++j)  // 边界条件
        {
            if(vec[j]>vec[j+1])
            {
                temp=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=temp;
            }
        }

    }

    for(int i =0;i<vec.size();++i)
        cout<<vec[i]<<endl;

}
int main()
{
    vector<int > vec={9,3,1,4,2,7,8,6,5};
		BubbleSort(vec);
		return 0;
}
