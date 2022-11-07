#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Node
{
public:
    string data;
    Node *next;
    Node *prev;
    Node()
    {
        next = NULL;
        prev = NULL;
    }
};
bool primeNumber(int number)
{
    if (number == 0 || number == 1)
    {
        return false;
    }
    else if (number == 2 || number == 3)
    {
        return true;
    }
    else
    {
        int check = 0;
        for (int i = 2; i <= number / 2; i++)
        {
            if (number % i == 0)
            {
                return false;
            }
        }
        if (check == 0)
        {
            return true;
        }
    }
}
class LinkedList
{
public:
    Node *head;
    Node *last;
    LinkedList()
    {
        head = NULL;
        last = NULL;
    }
    void insertAtLast(string n)
    {
        Node *newnode = new Node();
        newnode->data = n;
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
            newnode->prev = head;
            last = newnode;
        }
        else if (head->next == head)
        {
            head->next = newnode;
            newnode->next = head;
            newnode->prev = head;
            head->prev = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            newnode->next = head;
            newnode->prev = last;
            head->prev = newnode;
            last = newnode;
        }
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "list is empty" << endl;
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
    int listSize()
    {
        if (head == NULL)
        {
            return 0;
        }
        Node *temp = head;
        int i = 0;
        do
        {
            i++;
            temp = temp->next;
        } while (temp != head);
        return i;
    }
    void removeNode(string n)
    {
        if (head->data == n)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                head = head->next;
                head->prev = last;
                last->next = head;
            }
        }
        else
        {
            Node *temp = head;
            do
            {
                if (temp->data == n)
                {
                    break;
                }
                temp = temp->next;
            } while (temp != head);
            if (temp->next == head)
            {
                temp = temp->prev;
                temp->next = head;
                head->prev = temp;
                last = temp;
            }
            else
            {
                Node *node = temp->next;
                Node *prevNode = temp->prev;
                prevNode->next = node;
                node->prev = prevNode;
            }
        }
    }
    Node *findTarget(string n)
    {
        if (head == NULL)
        {
            cout << "list is empty";
            return NULL;
        }
        else if (head->data == n)
        {
            return head;
        }
        else
        {
            Node *temp = head;
            do
            {
                if (temp->data == n)
                {
                    return temp;
                }
                temp = temp->next;
            } while (temp != head);
        }
        cout << "Target not found" << endl;
    }
    void final(LinkedList *l)
    {
        int l1Size = listSize();
        int l2Size = l->listSize();
        Node *middle = l->head;
        int middleno = l2Size / 2;
        Node *temp = l->head;
        for (int i = 1; i < middleno; i++)
        {
            middle = middle->next;
        }
        temp = middle;
        Node *nextNode = middle->next;
        for (int i = 1; l->listSize() != 0; i++)
        {
            if (i == l1Size)
            {
                // cout << temp->data << " ";
                l->removeNode(temp->data);
                // l->display();
                middle = middle->next;
                temp = middle;
                i = 1;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList l1;
    LinkedList l2;
    ifstream data("data.txt");
    if (data.is_open())
    {
        cout << "File successfully opened" << endl;
        int i = 1;
        string line;
        while (!data.eof())
        {
            data >> line;
            if (primeNumber(i))
            {
                l1.insertAtLast(line);
            }
            else
            {
                l2.insertAtLast(line);
            }
            i++;
        }
        data.close();
    }
    cout << "----------------------------" << endl;
    cout << "Before elimination" << endl;
    cout << "----------------------------" << endl;
    cout << l1.listSize() << " ";
    l1.display();
    cout << endl
         << l2.listSize() << " ";
    l2.display();

    l1.final(&l2);

    cout << endl
         << endl
         << "----------------------------" << endl;
    cout << "After elimination" << endl;
    cout << "----------------------------" << endl;
    cout << l1.listSize() << " ";
    l1.display();
    cout << endl
         << l2.listSize() << " ";
    l2.display();
}