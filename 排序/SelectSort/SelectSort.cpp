# include<iostream>
# include<vector>
using namespace std;

void SelectSort(vector<int> vec)
{
    for(int i=0;i<vec.size()-1;++i)
    {
        // ��ʼ����������СԪ�ص�λ��
        int min = i;

        // Ѱ����������СԪ�ص�λ��
        for(int j=i+1;j<vec.size();++j)//ע��߽����� j=i+1
        {
            if(vec[min]>vec[j])
                min = j;
        }

        // ������СԪ��
        if(min!=i)
        {
            int temp = vec[i];
            vec[i]=vec[min];
            vec[min]=temp;
        }

    }

    // ��ӡ����������
    for(int i=0;i<vec.size();++i)
        cout<<vec[i]<<endl;

}

int main()
{
    vector<int > vec={49,38,65,97,76,13,27,49};
    SelectSort(vec);

    return 0;
}
