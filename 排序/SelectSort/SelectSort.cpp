# include<iostream>
# include<vector>
using namespace std;

int main()
{
    vector<int > vec={49,38,65,97,76,13,27,49};

    for(int i=0;i<vec.size()-1;++i)
    {
        int min = i;

        for(int j=i+1;j<vec.size();++j){
            if(vec[min]>vec[j])
                min = j;
        }

        if(min!=i){
            int temp = vec[i];
            vec[i]=vec[min];
            vec[min]=temp;
        }

    }
    for(int i=0;i<vec.size();++i)
        cout<<vec[i]<<endl;
    return 0;
}
