#include <iostream>
using namespace std;
int main() {

//cast a division result
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<"without cast:"<<a/b<<endl;
    cout<<"with cast:"<<static_cast<double>(a)/b<<endl;
    

// Nested if else statement
   int marks;
   cout<<"Enter the marks:";
   cin>>marks;

    if(marks>=90)
    {
        cout<<"grade A"<<endl;
    }
    else if(marks>=80)
    {
        cout<<"grade B"<<endl;
    }
    else if(marks>=70)
    {
        cout<<"grade C"<<endl;
    }
    else if(marks>=60)
    {
        cout<<"grade D"<<endl;
    }
    else
    {
        cout<<"grade F"<<endl;
    }

//switch statement
    int day;
    cout<<"Enter the day number (1-7): ";
    cin>>day;
    switch(day)
    {
        case 1:
            cout<<"Monday"<<endl;
            break;
        case 2:
            cout<<"Tuesday"<<endl;
            break;
        case 3:
            cout<<"Wednesday"<<endl;
            break;
        case 4:
            cout<<"Thursday"<<endl;
            break;
        case 5:
            cout<<"Friday"<<endl;
            break;
        case 6:
            cout<<"Saturday"<<endl;
            break;
        case 7:
            cout<<"Sunday"<<endl;
            break;
        default:
            cout<<"Invalid"<<endl;
    }

//for loop in c++
    for(int k=1 ; k<=10 ; k++)
    {
        cout<<k <<" ";
    }
    cout<<endl;

//while loop
int n;
cout<<"Enter the positive number:";
cin>>n;
int sum = 0;
while(n>0)
{
    sum=sum+n;
    n--;
}
cout<<"Sum : "<<sum<<endl;

//Sum of Digits with a while Loop
int j,j1=0;
int sum2=0;
cout<<"enter the three digit number:";
cin>>j;
while (j>0)
{
    j1 = j%10; 
    sum2 = sum2+j1;
    j=j/10;
}
cout<<"Sum of digits : "<<sum2<<endl;
    return 0;
}