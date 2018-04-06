#include<iostream>
using namespace std;

void insertSort(int temp_sort[],int n)
{
    int temp=0;

    for(int i=1;i<n;++i)
    {
        int j = i;
        while(j>0 && temp_sort[j-1]>temp_sort[j])
        {
            temp = temp_sort[j-1];
            temp_sort[j-1] = temp_sort[j];
            temp_sort[j]=temp;
            --j;
        }
    }
    for(int i=0;i<n;++i)
        cout<<temp_sort[i]<<endl;
}
int main()
{
    int temp_sort[5]={9,3,1,4,2};
    insertSort(temp_sort,5);
    return 0;
}
