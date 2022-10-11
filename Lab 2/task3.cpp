// Create a Structure Movie (Variables: Name, Year, rating). Create object of movie.Create Pointer object of movie. The pointer of movie pointing the object of movie. Give values to the movie object and Print the Movie object value using Pointer.
// By RAO ALI NAWAZ
#include <iostream>
using namespace std;
struct Movie
{
    string name;
    int year;
    int rating;
};
int main()
{
    Movie *p;
    Movie m;
    p = &m;
    cout << "Name of movie: ";
    cin >> m.name;
    cout << "Year of movie: ";
    cin >> m.year;
    cout << "Rating of movie: ";
    cin >> m.rating;
    cout << endl
         << "Name of movie: " << p->name << endl;
    cout << "Year of movie: " << p->year << endl;
    cout << "Rating of movie: " << p->rating << endl;
}
