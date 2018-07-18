# include<iostream>
# include<vector>
using namespace std;

void SelectSort(vector<int> vec)
{
    for(int i=0;i<vec.size()-1;++i)
    {
        // 初始化数组中最小元素的位置
        int min = i;

        // 寻找数组中最小元素的位置
        for(int j=i+1;j<vec.size();++j)//注意边界条件 j=i+1
        {
            if(vec[min]>vec[j])
                min = j;
        }

        // 更新最小元素
        if(min!=i)
        {
            int temp = vec[i];
            vec[i]=vec[min];
            vec[min]=temp;
        }

    }

    // 打印排序后的数组
    for(int i=0;i<vec.size();++i)
        cout<<vec[i]<<endl;

}

int main()
{
    vector<int > vec={49,38,65,97,76,13,27,49};
    SelectSort(vec);

    return 0;
}
