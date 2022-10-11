/*
Create a class Employee(Variables: Name, joining date, dept)
1.Create another class dept.Dept
2.class will be inherited from Employee class.
By RAO ALI NAWAZ
*/
#include <iostream>
using namespace std;
class Dept
{
public:
    string dept;
};
class Employee : public Dept
{
public:
    string name;
    int date;
    Employee(string name, int date, string dept)
    {
        this->name = name;
        this->date = date;
        this->dept = dept;
    }
    void display()
    {
        cout << "Name of employee: " << name << endl;
        cout << "Joinning date of employee: " << date << endl;
        cout << "Department of employee: " << dept << endl;
    }
};
int main()
{
    Employee e("ran", 9102022, "cys");
    cout << "Information of employee: " << endl;
    e.display();
}