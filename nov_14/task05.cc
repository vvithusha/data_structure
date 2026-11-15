#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
protected:
    int age;
public:
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setAge(int a) { age = a; }
    int getAge() { return age; }
};

class Student : public Person {
private:
    int regNo;
public:
    void setRegNo(int r) { regNo = r; }
    int getRegNo() { return regNo; }
    void display() {
        cout << getName() << " " << age<< " " << regNo << endl;
    }
};

int main()
{
    Student s;
    s.setName("vithu");
    s.setAge(21);
  
    s.setRegNo(126);
    s.display();
    return 0;
}