#include<iostream>
#include<vector>
using namespace std;

/*
* 功能：二维数组中的查找
* 形参：整形目标数值target和二维整形向量vec
*/
bool Find(int target,vector<vector<int> > vec)
{
    if(!vec.empty())
    {
        int rows = vec.size();
        int cols = vec[0].size();

        if(rows!=0&&cols!=0)
        {
            int corner_rows = 0;
            int corner_cols = cols-1;

            while(corner_rows<rows&&corner_cols>=0)
            {
                if(vec[corner_rows][corner_cols]>target)
                    --corner_cols;
                else if(vec[corner_rows][corner_cols]<target)
                    ++corner_rows;
                else
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<int> > vec={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    bool temp = Find(7,vec);
    cout<<temp<<endl;
    return 0;
}
