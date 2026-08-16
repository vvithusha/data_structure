#include <iostream>
#include <string>
using namespace std;
struct Student {
    string name;
    int age;
    float marks;

    void display() {
        cout << name << " " << age << " " << marks << endl;
    }
};

int main() {
    Student s1 = {"Kumar", 20, 85.5};
    s1.display();
    return 0;
}