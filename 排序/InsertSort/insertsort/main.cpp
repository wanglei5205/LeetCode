#include<iostream>
#include<vector>
using namespace std;

void insertSort(vector<int> vec)
{
    if(vec.size()>0)
    {
        for(int i=1;i<vec.size();++i)
        {
            int j = i;

            while(j-1>=0 && vec[j-1]>vec[j])
            {
                vec[j-1] = vec[j-1]+vec[j];
                vec[j]   = vec[j-1]-vec[j];
                vec[j-1] = vec[j-1]-vec[j];
                --j;
            }
        }

        for(int i=0;i<vec.size();++i)
            cout<<vec[i]<<endl;
    }

}
int main()
{
    vector<int> vec={9,3,1,4,2};
    insertSort(vec);
    return 0;
}
