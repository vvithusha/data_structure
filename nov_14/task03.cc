#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int regNo;
    float marks;
    static int count;                       // declaration
public:
    Student(string n, int r, float m) : name(n), regNo(r), marks(m) {
        count++;                            // one more object created
    }
    void display() const {                  // const: cannot modify members
        cout << name << " " << regNo << " " << marks << endl;
    }
    static int getCount() { return count; }
};
int Student::count = 0;                     // definition outside the class

int main() {
    Student s1("Kamal", 101, 78.5);
    Student s2("Nimali", 102, 85);
    s1.display();
    s2.display();
    cout << "Students: " << Student::getCount() << endl;
    return 0;
}