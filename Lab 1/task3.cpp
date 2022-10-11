#include <iostream>
using namespace std;
struct Student
{
    int age;
    float gpa;
};
void readdata(Student &s)
{
    cout << "Enter age of student: ";
    cin >> s.age;
    cout << "Enter gpa of student: ";
    cin >> s.gpa;
}
void displaydata(Student &s)
{
    cout << endl
         << "Age: " << s.age << endl;
    cout << "Gpa : " << s.gpa << endl;
}
int main()
{
    Student s1;
    readdata(s1);
    displaydata(s1);
}