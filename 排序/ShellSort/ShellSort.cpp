#include<iostream>
#include<vector>
using namespace std;
void ShellSort(vector<int>vec)
{
		// ϣ������
    for(int gap=vec.size()/2;gap>0;gap/=2)
    {
				// ֱ�Ӳ������� 
        for(int i=gap;i<vec.size();++i)
        {
            int j=i;
            while(j-gap>=0 && vec[j-gap]>vec[j])
            {
                vec[j-gap] = vec[j-gap]+vec[j];
                vec[j]     = vec[j-gap]-vec[j];
                vec[j-gap] = vec[j-gap]-vec[j];
                j=j-gap;
            }
        }
    }
		
		// ��ӡ���
    for(int i=0;i<vec.size();++i)
    {
        cout<<vec[i]<<endl;
    }

}
int main()
{
    vector<int> vec={8,9,1,7,2,3,5,4,6,0};
    ShellSort(vec);
    return 0;
}
