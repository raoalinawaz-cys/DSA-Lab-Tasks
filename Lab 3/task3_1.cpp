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
By RAO ALI NAWAZ using vectors
*/
#include <iostream>
#include <vector>
using namespace std;
class Phone
{
public:
    string name;
    int phoneno;
    int id;
    string address;
};
void add_Contact_info(vector<Phone> &v)
{
    Phone p;
    cout << "Name of person: ";
    cin >> p.name;
    cout << "Id of person: ";
    cin >> p.id;
    cout << "Phone No of person: ";
    cin >> p.phoneno;
    cout << "Address of person: ";
    cin >> p.address;
    v.push_back(p);
}
void display(vector<Phone> &v)
{
    vector<Phone>::iterator itr;
    for (itr = v.begin(); itr != v.end(); itr++)
    {
        cout << endl << "-------------------------------------" << endl;
        cout << "Name of Person: " << itr->name << endl;
        cout << "Id of person: " << itr->id << endl;
        cout << "Phone no of person: " << itr->phoneno << endl;
        cout << "Address of person: " << itr->address << endl;
        cout << endl << "-------------------------------------" << endl;
    }
}
void remove(vector<Phone> &v, int id)
{
    vector<Phone>::iterator itr;
    for (itr = v.begin(); itr != v.end(); itr++)
    {
        if (itr->id == id)
        {
            v.erase(itr);
        }
    }
}
int main()
{
    vector<Phone> v;
    int id;
    for (int i = 0; i < 3; i++)
    {
        add_Contact_info(v);
    }
    cout << "Enter Id of person to remove: ";
    cin >> id;
    cout << endl << "-------------------------------------------------------------------------------------------" << endl;
    cout << " Before Remove" << endl;
    cout << endl << "-------------------------------------------------------------------------------------------" << endl;
    display(v);
    remove(v, id);
    cout << endl << "-------------------------------------------------------------------------------------------" << endl;
    cout << " After Remove" << endl;
    cout << endl << "-------------------------------------------------------------------------------------------" << endl;
    display(v);
}
