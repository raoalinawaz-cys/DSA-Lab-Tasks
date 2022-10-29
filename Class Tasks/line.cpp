#include <iostream>
using namespace std;
class Point{
	public:
	int x;
	int y;
	Point(int x, int y);
	void display();
};
Point::Point(int x = 0, int y = 0)
{
	this->x = x;
	this->y = y;
}
void Point::display()
{
	cout << x << " " << y << endl;
}
class Line{         
	public:
	Point *p1;
	Point *p2;
	Line(int x1, int x2, int y1, int y2);
	void display();
};
Line::Line(int x1, int x2, int y1, int y2)
{
	Point p(x1, y1);
	Point q(x2, y2);
	p1 = &p;
	p2 = &q;
}
void Line::display()
{
	cout << p1->x << " " << p1->y << endl;
	cout << p2->x << " " << p2->y << endl;
	//cout << p1->display() << endl;
	//cout << p2->display() << endl;
}
int main()
{
	Line l(1, 3, 4, 5);
	l.display();	
}