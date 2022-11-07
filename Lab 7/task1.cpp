// LAB 7 TASK 1
// BY RAO ALI NAWAZ
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
};
class cSL
{
public:
    Node *head;
    cSL()
    {
        head = NULL;
    }
    void insertAtLast(int n)
    {
        Node *newnode = new Node();
        newnode->data = n;
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }
    }
    void deleteAtLast()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "list is already empty" << endl;
        }
        else if (head->next == head)
        {
            head = NULL;
            delete temp;
        }
        else
        {
            while (temp->next->next != head)
            {
                temp = temp->next;
            }
            temp->next = head;
        }
    }
    void displayNodes()
    {
        if (head == NULL)
        {
            cout << "list is already empty";
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    void deleteAtHead()
    {
        if (head == NULL)
        {
            cout << "List is already empty" << endl;
        }
        else if (head->next == head)
        {
            head = NULL;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
        }
    }
};
int main()
{
    cSL l1;
    l1.insertAtLast(3);
    l1.insertAtLast(4);
    l1.insertAtLast(5);
    l1.insertAtLast(7);
    l1.insertAtLast(8);
    l1.insertAtLast(9);

    l1.deleteAtLast();
    l1.deleteAtHead();
    l1.deleteAtHead();
    l1.displayNodes();
}