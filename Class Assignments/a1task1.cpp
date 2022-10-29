#include <iostream>
using namespace std;
class Node
{
public:
    int id;
    string name;
    int salary;
    Node *next;
    Node();
    void readNode();
    void displayNode();
};
Node::Node()
{
    next = NULL;
}
void Node::readNode()
{
    cout << "Enter data of employee: " << endl;
    cout << "Id : ";
    cin >> id;
    cout << "Name : ";
    cin >> name;
    cout << "Salary : ";
    cin >> salary;
}
void Node::displayNode()
{
    cout << "Id : " << id << endl;
    cout << "Name : " << name << endl;
    cout << "Salary : " << salary << endl;
}
class EmployeeList
{
public:
    Node *head;
    Node *last;
    EmployeeList();
    void createNode();
    void displayAllNodes();
    void insertAtHead();
    void insertAtLast();
};
EmployeeList::EmployeeList()
{
    head = NULL;
    last = NULL;
}
void EmployeeList::createNode()
{
    Node *newnode = new Node();
    if (head == NULL)
    {
        head = newnode;
        last = head;
    }
    else
    {

        last->next = newnode;
        last = newnode;
    }
}
void EmployeeList::displayAllNodes()
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "Employee list is empty" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            temp->displayNode();
            temp = temp->next;
        }
    }
}
void EmployeeList::insertAtHead()
{
    Node *newnode = new Node();
    newnode->readNode();
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void EmployeeList::insertAtLast()
{
    createNode();
    last->readNode();
}
int main()
{
    EmployeeList employees;
    employees.insertAtLast();
    employees.insertAtLast();
    employees.insertAtHead();
    cout << endl;
    employees.displayAllNodes();
}