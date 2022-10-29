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
    EmployeeList();
    Node *createNode();
    void displayAllNodes();
    void insertAtHead();
    void insertAtLast();
    Node *findLast();
    void insertAtTarget();
    Node *findTarget(int id);
    void deleteAtHead();
    void deleteAtLast();
    Node *findSecondLast();
    void deleteTarget();
    Node *findPrevTarget(int id);
    void highestSalary();
};
EmployeeList::EmployeeList()
{
    head = NULL;
}
Node *EmployeeList::createNode()
{
    Node *newnode = new Node();
    return newnode;
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
    Node *newnode = createNode();
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
Node *EmployeeList::findLast()
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}
void EmployeeList::insertAtLast()
{
    Node *newnode = createNode();
    newnode->readNode();
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        Node *last = findLast();
        last->next = newnode;
    }
}
Node *EmployeeList::findTarget(int id)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else if (head->id == id)
    {
        return head;
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->id == id)
            {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}
void EmployeeList::insertAtTarget()
{
    int id;
    cout << "Enter id of employee : ";
    cin >> id;
    Node *target = findTarget(id);
    if (target == NULL)
    {
        cout << "Target does not exist";
    }
    else
    {
        Node *newnode = createNode();
        newnode->readNode();
        newnode->next = target->next;
        target->next = newnode;
    }
}
void EmployeeList::deleteAtHead()
{
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
Node *EmployeeList::findSecondLast()
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}
void EmployeeList::deleteAtLast()
{
    if (head == NULL)
    {
        cout << "List already empty" << endl;
    }
    else if (head->next == NULL)
    {
        delete head;
    }
    else
    {
        Node *secondLast = findSecondLast();
        Node *last = secondLast->next;
        secondLast->next = NULL;
        delete last;
    }
}
Node *EmployeeList::findPrevTarget(int id)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else if (head->next == NULL)
    {
        return NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->id != id)
        {
            temp = temp->next;
        }
        return temp;
    }
    return NULL;
}
void EmployeeList::deleteTarget()
{
    int id;
    cout << "Enter id of target : ";
    cin >> id;
    Node *target = findTarget(id);
    if (target == head)
    {
        // Node *temp = head;
        // head = head->next;
        // delete temp;
        deleteAtHead();
    }
    else if (target == NULL)
    {
        cout << "Target not found" << endl;
    }
    else
    {
        Node *prevTarget = findPrevTarget(id);
        prevTarget->next = target->next;
        delete target;
    }
}
void EmployeeList::highestSalary()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node *highestSalaryEmployee = head;
        Node *temp = head->next;
        while (temp != NULL)
        {
            if (temp->salary > highestSalaryEmployee->salary)
            {
                highestSalaryEmployee = temp;
            }
            temp = temp->next;
        }
        cout << "Details of highest salary employee : " << endl;
        highestSalaryEmployee->displayNode();
    }
}
int main()
{
    EmployeeList employees;
    employees.insertAtLast();
    employees.insertAtLast();
    employees.insertAtTarget();
    // employees.deleteAtLast();
    // employees.deleteTarget();
    employees.highestSalary();
    // employees.insertAtHead();
    // employees.deleteAtHead();
    cout << endl;
    employees.displayAllNodes();
}