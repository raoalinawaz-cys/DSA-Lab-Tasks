#include <iostream>
using namespace std;
class Node
{
public:
    int id;
    string name;
    int salary;
    Node *next;
    Node *prev;
    Node();
    void readNode();
    void displayNode();
};
Node::Node()
{
    next = NULL;
    prev = NULL;
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
    void ascendingDisplayNodes();
    void descendingDisplayNodes();
    void insertAtHead();
    void insertAtLast();
    void insertAtTarget();
    Node *findTarget(int id);
    Node *findLast();
    void deleteAtHead();
    void deleteAtLast();
    void deleteTarget();
    void ascendingOrder();
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
void EmployeeList::ascendingDisplayNodes()
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
void EmployeeList::descendingDisplayNodes()
{
    Node *temp = findLast();
    if (temp == NULL)
    {
        cout << "Employee list is empty" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            temp->displayNode();
            temp = temp->prev;
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
        head->prev = newnode;
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
        newnode->prev = last;
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
    else if (target->next == NULL)
    {
        insertAtLast();
    }
    else
    {
        Node *newnode = createNode();
        newnode->readNode();
        newnode->prev = target;
        target->next->prev = newnode;
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
void EmployeeList::deleteAtLast()
{
    if (head == NULL)
    {
        cout << "List already empty" << endl;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node *last = findLast();
        Node *secondLast = last->prev;
        secondLast->next = NULL;
        delete last;
    }
}
void EmployeeList::deleteTarget()
{
    int id;
    cout << "Enter id of target : ";
    cin >> id;
    Node *target = findTarget(id);
    if (target == head)
    {
        deleteAtHead();
    }
    else if (target == NULL)
    {
        cout << "Target not found" << endl;
    }
    else
    {

        Node *prevTarget = target->prev;
        Node *nextTarget = target->next;
        nextTarget->prev = prevTarget;
        prevTarget->next = target->next;
        delete target;
    }
}
void EmployeeList::ascendingOrder()
{

    Node *temp = head;
    Node *sorter;
    while (temp != NULL)
    {
        sorter = temp->next;
        while (sorter != NULL)
        {
            if (temp->id > sorter->id)
            {
                Node *swapnode = new Node();
                swapnode->id = temp->id;
                swapnode->name = temp->name;
                swapnode->salary = temp->salary;

                temp->id = sorter->id;
                temp->name = sorter->name;
                temp->salary = sorter->salary;

                sorter->name = swapnode->name;
                sorter->id = swapnode->id;
                sorter->salary = swapnode->salary;

                delete swapnode;
            }
            sorter = sorter->next;
        }
        temp = temp->next;
    }
}
int main()
{
    EmployeeList employees;
    cout << endl;
    int n = 0;
    Node *temp = employees.head;
    do
    {

        temp = employees.head;
        cout << endl
             << "---------------------" << endl;
        while (temp != NULL)
        {
            cout << temp->id << " ";
            temp = temp->next;
        }
        cout << endl
             << "---------------------" << endl;
        cout << endl;
        cout << "1      ascending" << endl;
        cout << "2      descending" << endl;
        cout << "3      insertAtHead" << endl;
        cout << "4      insertAtLast" << endl;
        cout << "5      insertAtTarget" << endl;
        cout << "6      deleteAtHead" << endl;
        cout << "7      deleteAtLast" << endl;
        cout << "8      deletetarget" << endl;
        cout << "9      ascendingOrder" << endl;
        cout << "10      ascendingOrder" << endl;

        cout << endl
             << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            employees.ascendingDisplayNodes();
            break;
        case 2:
            employees.descendingDisplayNodes();
            break;
        case 3:
            employees.insertAtHead();
            break;
        case 4:
            employees.insertAtLast();
            break;
        case 5:
            employees.insertAtTarget();
            break;
        case 6:
            employees.deleteAtHead();
            break;
        case 7:
            employees.deleteAtLast();
            break;
        case 8:
            employees.deleteTarget();
            break;
        case 9:
            employees.ascendingOrder();
            break;
        case 10:
            break;
        default:
            cout << "Enter 1-10" << endl;
        }

        /* code */
    } while (n != 10);
}