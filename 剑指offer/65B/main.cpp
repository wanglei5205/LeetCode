#include <iostream>
using namespace std;

void fun1(int m,int n)
{
    cout << "����һ�����ڼӼ�����������������" << endl;
    m = m + n;
    n = m - n;
    m = m - n;
    cout<<m<<"    "<<n<<endl;
}

void fun2(int m,int n)
{
    cout << "������������������㣬������������" << endl;
    m = m^n;
    n = m^n;
    m = m^n;
    cout<<m<<"    "<<n<<endl;
}
int main()
{
    int m = 10;
    int n = 20;
    cout << "ԭʼ��ֵ" << endl;
    cout<<m<<"    "<<n<<endl;
    fun1(m,n);
    fun2(m,n);
    return 0;
}
