#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
};
class CDL
{
public:
    Node *head;
    Node *last;
    CDL()
    {
        head = NULL;
        last = NULL;
    }
    void insertAtLast(int n)
    {
        Node *newnode = new Node();
        newnode->data = n;
        if (head == NULL)
        {
            head = newnode;
            head->prev = newnode;
            head->next = newnode;
            last = newnode;
        }
        else if (head->next == head)
        {
            newnode->next = head;
            head->next = newnode;
            head->prev = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            newnode->next = head;
            head->prev = newnode;
            last = newnode;
        }
    }
    void displayList()
    {
        if (head == NULL)
        {
            cout << "list is already empty";
        }
        else if (head->next == head)
        {
            cout << head->data << endl;
        }
        else
        {
            Node *temp = head;
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
        }
    }
    void insertAtHead(int n)
    {
        Node *newnode = new Node();
        newnode->data = n;
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
            newnode->prev = head;
            last = head;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            last->next = head;
        }
    }
    void insertAtPoint(int n, int value)
    {
        Node *temp = head;
        int count = 0;
        do
        {
            if (temp->data == n)
            {
                count++;
                break;
            }
            temp = temp->next;
        } while (temp != head);
        if (count != 0)
        {
            if (temp->next == head)
            {
                insertAtLast(value);
            }
            else
            {
                Node *newnode = new Node();
                newnode->next = temp->next;
                temp->next->prev = newnode;
                newnode->data = value;
                newnode->prev = temp;
                temp->next = newnode;
            }
        }
        else
        {
            cout << n << " is not in linked list" << endl;
        }
    }
};
int main()
{
    CDL l1;
    l1.insertAtLast(2);
    l1.insertAtLast(3);
    l1.insertAtLast(4);
    l1.insertAtHead(7);
    l1.insertAtHead(8);
    l1.insertAtHead(9);
    l1.insertAtPoint(4, 5);

    l1.displayList();
}