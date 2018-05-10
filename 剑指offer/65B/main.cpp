#include <iostream>
using namespace std;

void fun1(int m,int n)
{
    cout << "方法一，基于加减法，交换两个变量" << endl;
    m = m + n;
    n = m - n;
    m = m - n;
    cout<<m<<"    "<<n<<endl;
}

void fun2(int m,int n)
{
    cout << "方法二，基于异或运算，交换两个变量" << endl;
    m = m^n;
    n = m^n;
    m = m^n;
    cout<<m<<"    "<<n<<endl;
}
int main()
{
    int m = 10;
    int n = 20;
    cout << "原始数值" << endl;
    cout<<m<<"    "<<n<<endl;
    fun1(m,n);
    fun2(m,n);
    return 0;
}
