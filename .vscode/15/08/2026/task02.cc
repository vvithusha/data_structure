#include <iostream>
using namespace std;
int main()
{
    int *num, *data;
    data = new int [10];
    num=data;

    for(int i=0 ; i<5 ; i++)
    {
        cout<<3 * data[i]<<endl;
    }
    delete[] data;
    return 0;
}