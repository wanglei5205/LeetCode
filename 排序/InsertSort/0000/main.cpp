#include <iostream>

using namespace std;

int main()
{
    int x = 9999;
    int countx = 0;
    while(x){
        countx++;
        x = x & (x-1);
    }
    cout<<countx<<endl;
}
