#include <iostream>
using namespace std;
#include <string>

int add(int &x)
{
    return x*2;
}
int main()
{
    int x=10;
    cout<<add(x)<<endl;
    return 0;
}