// Create a structure Place (Variable: Name, LocatedCountry), Create a structurePerson (Variables: name, age, FavouritePlace). Favourite Place is the object of Place Structure. Get and Display Person information using member functions. And Getfunction() get values at run time. (Hint: Nested Structure).
// By RAO ALI NAWAZ
#include <iostream>
using namespace std;
struct Place
{
    string name;
    string LocatedCountry;
};
struct Person
{
    string name;
    int age;
    Place favouritePlace;
    void get()
    {
        cout << "Name of person: ";
        cin >> name;
        cout << "Age of person: ";
        cin >> age;
        cout << "Favourite Place name: ";
        cin >> favouritePlace.name;
        cout << "Favourite Place Country: ";
        cin >> favouritePlace.LocatedCountry;
    }
    void display()
    {
        cout << "Name of person: " << name << endl;
        cout << "Age of person: " << age << endl;
        cout << "Favourite Place name: " << favouritePlace.name << endl;
        cout << "Favourite Place country: " << favouritePlace.LocatedCountry << endl;
    }
};
int main()
{
    Person p;
    p.get();
    cout << endl;
    p.display();
}
