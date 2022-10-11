#include <iostream>
#include <math.h>
using namespace std;
class Coordinate{
	public:
	int x;
	int y;
};
class Point{
	public:
	Coordinate p;
	Point(int x=0, int y=0);
	void display();
	void distance(Point p);
};
Point::Point(int x, int y)
{
	p.x = x;
	p.y = y;
}
void Point::display(){
	cout << "x: " << p.x << " y: " << p.y << endl;
}
void Point::distance(Point q){
	int distance = sqrt(pow(q.p.x - p.x, 2) + pow(q.p.y - p.y, 2));
	cout << "Distance between two points: " << distance << endl;
};
void isZero(Point p)
{
	if(p.p.x == 0 && p.p.y == 0)
	{
		cout << "Point is zero it is at center" << endl;
	}                                                       
	else
	{
		cout << "Point is not zero it is not at center" << endl;
	}
}
Point middlePoint(Point p)
{
	Point temp;
	temp.p.x = p.p.x/2;
	temp.p.y = p.p.y/2;
	return temp;	
}
void isEqual(Point p, Point q)
{
	if(p.p.x == q.p.x && p.p.y == q.p.y)
	{
		cout << "Both points are equal" << endl;
	}
	else
	{
		cout << "Points are not equal" << endl;
	}
}
void isGreater(Point p, Point q)
{
	int p_distance = sqrt(pow(p.p.x, 2) + pow(p.p.y, 2));
	int q_distance = sqrt(pow(q.p.x, 2) + pow(p.p.y, 2));
	if(p_distance == q_distance)
	{
		cout << "Both points are equal" << endl;
	}
	else if(p_distance > q_distance)
	{
		cout << "P point is greater than q point" << endl;
	}
	else
	{
		cout << "q point is smaller than P point" << endl;
	}
}
int main()
{
	Point p1(2, 3);
	Point p2(4, 5);
	cout << "---------------------------------" << endl;
	cout << "Points" << endl;
	cout << "---------------------------------" << endl << endl;
	p1.display();
	p2.display();
	cout << endl << "---------------------------------" << endl;
	cout << "Distance between two points" << endl;
	cout << "---------------------------------" << endl << endl;
	p1.distance(p2);
	cout << endl << "---------------------------------" << endl;
	cout << "Middle Points from origin" << endl;
	cout << "---------------------------------" << endl << endl;
	Point mp1 = middlePoint(p1);
	Point mp2 = middlePoint(p2);
	cout << "Middle Point of point p1: " << mp1.p.x << " , " << mp1.p.y << endl;
	cout << "Middle Point of point p2: " << mp2.p.x << " , " << mp2.p.y << endl;
	cout << endl << "---------------------------------" << endl;
	cout << "Points equality check" << endl;
	cout << "---------------------------------" << endl << endl;
	isEqual(p1, p2);
	cout << endl << "---------------------------------" << endl;
	cout << "Greater check" << endl;
	cout << "---------------------------------" << endl << endl;
	isGreater(p1, p2);
	cout << endl << "---------------------------------" << endl;
	cout << "Zero point check" << endl;
	cout << "---------------------------------" << endl << endl;
	cout << "P1: ";
	isZero(p1);
	cout << "P2: ";
	isZero(p2);
	
}