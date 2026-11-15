#include <iostream>
using namespace std;
int main()
{
//Array of integers
    const int size=5;
    int marks[size];
    int sum=0;

    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter marks for student "<<i+1<<": ";
        cin>>marks[i];
        sum+=marks[i];
    }
    cout<<"Sum of marks: "<<(double)sum<<endl;

//Structures
    struct Student
    {
        string name;
        int age;
        double marks;
    };
     
    Student s1[size];
   for(int l=0 ; l<size ; l++)
   {
       cout<<"Enter name for student "<<l+1<<": ";
       cin>>s1[l].name;
       cout<<"Enter age for student "<<l+1<<": ";
       cin>>s1[l].age;
       cout<<"Enter marks for student "<<l+1<<": ";
       cin>>s1[l].marks;

       cout<<"Student "<<l+1<<": "<<s1[l].name<<", Age: "<<s1[l].age<<", Marks: "<<s1[l].marks<<endl;
   }
 
//Enumerations
    enum color {red,green,blue};

    color c1=red;
    color c2=green;
    cout<<c1+c2<<endl;

//Exercise Enumerations
    enum traffic_light {red_light, yellow_light, green_light};
    cout<<"Enter traffic light color (0 for red, 1 for yellow, 2 for green): ";
    int light;
    cin>>light;

    if(light == 0)
    {
        cout<<"Stop"<<endl;
    }
    else if(light == 1)
    {
        cout<<"Prepare to stop"<<endl;
    }
    else if(light == 2)
    {
        cout<<"Go"<<endl;
    }
    else
    {
        cout<<"Invalid input"<<endl;
    }
    return 0;
}