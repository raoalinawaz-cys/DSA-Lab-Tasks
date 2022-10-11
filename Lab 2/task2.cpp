// Write a Program using structure Circle have member variable Radius. Createmember functions in the structure to get area and circumference of circle. Get Value fromusers.
// By RAO ALI NAWAZ
#include <iostream>
using namespace std;
struct circle
{
    float radius;
    double a;
    double c;
    void area()
    {
        a = 3.145 * radius * radius;
    }
    void circumference()
    {
        c = 2 * 3.145 * radius;
    }
};
int main()
{
    circle c1;
    cout << "Enter radius of circle: ";
    cin >> c1.radius;
    c1.area();
    c1.circumference();
    cout << endl
         << "Radius of circle: " << c1.radius << endl;
    cout << "Area of circle: " << c1.a << endl;
    cout << "Circumference of circle: " << c1.c << endl;
}
