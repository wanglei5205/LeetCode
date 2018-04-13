#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> Permutation(string str) {
    // �洢���
    vector<string> result;
    // �߽�����
    if(str.size()==0) return result;
    // �ݹ�ʵ���ַ������ֵ���ȫ����
    Permutation(result, str, 0);
    // ����˳��
    sort(result.begin(), result.end());
    // ���ؽ��
    return result;
    }

void Permutation(vector<string> &result, string str, int begin)
{
    // �ݹ����
    if(begin==str.size()-1) result.push_back(str);

    for(int i=begin; i<=str.size()-1;++i)
    {
        // ȥ��
        if(i!=begin && str[i]==str[begin]) continue;

        // ȫ����
        swap(str[i], str[begin]);
        Permutation(result, str, begin+1);
        swap(str[i], str[begin]);
    }
}

int main()
{
    string str="abc";
    Permutation(str);
}

