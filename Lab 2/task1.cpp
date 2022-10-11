// Write a Program using structure Rectangle using (Length and width variables instructure) and create functions area () and perimeter (). Get values of Length and Widthat runtime. Display Results using Display() function
// By RAO ALI NAWAZ
#include <iostream>
using namespace std;
struct Rectangle
{
    float length;
    float width;
    double a;
    double p;
    void area()
    {
        a = length * width;
    }
    void perimeter()
    {
        p = 2 * length + 2 * width;
    }
};
void display(Rectangle r1)
{
    cout << "Length of rectangle: " << r1.length << endl;
    cout << "Width of rectangle: " << r1.width << endl;
    cout << "Area of rectangle: " << r1.a << endl;
    cout << "Perimeter of rectangle: " << r1.p << endl;
}
int main()
{
    Rectangle r;
    cout << "Length: ";
    cin >> r.length;
    cout << "Width: ";
    cin >> r.width;
    r.area();
    r.perimeter();
    display(r);
}
