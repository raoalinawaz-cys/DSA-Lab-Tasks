/*
• Create a Class “StudentInfo” 
• Read Student Information such as name, roll number, section
• Input the categories from users and show the student information
By RAO ALI NAWAZ
*/
#include <iostream>
using namespace std;
class StudentInfo{
	public:
	string name;
	int rollno;
	string section;
	void read();	
	void display();
};
void StudentInfo::read()
{
	cout << "Name of student: ";
	cin >> name;
	cout << "Rollno of student: ";
	cin >> rollno;
	cout << "Section of student: ";
	cin >> section;
}                      
void StudentInfo::display()
{
        cout << "----------------------------" << endl;
        cout << "Student Information" << endl;
        cout << "----------------------------" << endl;
        cout << "Name of student: " << name << endl;
        cout << "Rollno of student: " << rollno << endl;
        cout << "Section of student: " << section << endl;
}
int main()
{
	StudentInfo s;
	s.read();
        s.display();

}
