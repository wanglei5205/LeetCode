#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include"stdafx.h"
using namespace std;

string lsubstr_1(const string & str)
{
    vector<string> vs;
    for (int i = 0; i < str.size(); i++)
        vs.push_back(str.substr(i));
    sort(vs.begin(), vs.end());
    int max = 0;
    int flag = 0;
    for (int i = 0; i <( vs.size()-1); i++)
    {
        int j = 0;
        while (vs[i][j] == vs[i + 1][j] && j<vs[i].size() && j<vs[i+1].size())
            j++;
        if (j>max)
        {
            max = j;
            flag = i;
        }          
    }
    return vs[flag].substr(0, max);
}
//方法二
string lsubstr_2(const string & str)
{
    string maxstr;
    for (int i = 0; i < str.size();i++)
    for (int j = (str.size() - i); j >=1 ; j--)
    {
        string subs = str.substr(i, j);
        int front = str.find(subs);
        int back = str.rfind(subs);
        if (front != back && subs.size() > maxstr.size())
            maxstr = subs;
    }
    return maxstr;
}
//方法三
string lsubstr_3(const string & str)
{
    string maxstr;
    for (int i = 0; i < str.size(); i++)
        for (int j = 0; j < i; j++)
        {
            string temp;
            int k = j;
            int m = i;
            while (str[m] == str[k] && i<str.size() && k<str.size())
            {
                m++; k++;
            }
            temp = str.substr(j, k - j);
            if (temp.size()>maxstr.size())
                maxstr = temp;
        }
    return maxstr;
}

void main(void)
{
    cout<<"4"<<endl;
    string test;
    cin >> test;
    getline(cin, test);
    //cout << lsubstr_1(test) << endl;
    //cout << lsubstr_2(test) << endl;
    cout << lsubstr_3(test) << endl;
}
