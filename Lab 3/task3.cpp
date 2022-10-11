/*
Create a class of Phone directory with following data members
1. Name
2. id
3. Address
4. Phone_Num
Task:
1. Add data of at least 5 persons using Add_contact_info function and pointer
2. Use a remove Function to take an ID from user and remove the data of matching ID from 
array.
Display the data before and after removing the person
By RAO ALI NAWAZ using arrays
*/
#include <iostream>
using namespace std;
class Phone
{
public:
    string name;
    int id;
    string address;
    int phoneno;
};
void Add_contact_Info(Phone *p)
{
    cout << "Enter name of person: ";
    cin >> p->name;
    cout << "Enter id of person: ";
    cin >> p->id;
    cout << "Enter address of person: ";
    cin >> p->address;
    cout << "Enter phoneno of person: ";
    cin >> p->phoneno;
}
void remove_id(Phone *q, int id, Phone *newone)
{
    for (int i = 0; i < 2; i++)
    {
        if (id == q[i].id)
        {
            continue;
        }
        newone[i] = q[i];
    }
}
int main()
{
    int size = 2;
    Phone p[size];
    Phone *q;
    for (int i = 0; i < size; i++)
    {
        q = &p[i];
        Add_contact_Info(q);
    }
    Phone newone[size - 1];
    int id;
    cout << "Enter id of employee: ";
    cin >> id;
    remove_id(p, id, newone);
    for (int i = 0; i < size; i++)
    {
        cout << p[i].id << " " << p[i].name << " " << p[i].address << " " << p[i].phoneno
             << endl;
    }
    cout << endl;
    cout << "After removed employee: ";
    cout << endl;
    for (int i = 0; i < size - 1; i++)
    {
        cout << p[i].id << " " << p[i].name << " " << p[i].address << " " << p[i].phoneno
             << endl;
    }
}