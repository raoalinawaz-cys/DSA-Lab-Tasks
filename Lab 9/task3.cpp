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
class ArrayQueue
{
public:
    int front;
    int rear;
    int size;
    int *arr;
    ArrayQueue(int s)
    {
        front = 0;
        rear = 0;
        size = s;
        arr = new int;
    }
    void enqueue(int value)
    {
        if (rear == size)
        {
            cout << "Queue is empty";
        }
        else
        {
            arr[rear] = value;
            rear++;
        }
    }
    void dequeue()
    {
        if (front == rear)
        {
            cout << "Queue is empty";
        }
        else
        {
            front++;
        }
    }
    void printQueue()
    {
        cout << "--------" << endl;
        cout << "Queue" << endl;
        cout << "--------" << endl;
        int temp = front;
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            while (temp != rear)
            {
                cout << arr[temp] << " ";
                temp++;
            }
        }
    }
};
class LinkedListQueue
{
public:
    Node *front;
    Node *rear;
    LinkedListQueue()
    {
        front = NULL;
        rear = NULL;
    }
    Node *createNode()
    {
        Node *newnode = new Node();
        return newnode;
    }
    void enqueue(int value)
    {
        Node *newnode = createNode();
        newnode->data = value;
        if (front == NULL && rear == NULL)
        {
            front = newnode;
            rear = newnode;
            return;
        }
        Node *temp = front;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        rear = newnode;
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is already empty";
            return;
        }
        front = front->next;
    }
    void printQueue()
    {
        Node *temp = front;
        if (front == NULL && rear == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    int choice;
    int select;
    int enqueueValue;
    cout << "1. Array" << endl;
    cout << "2. Linkedlist" << endl;
    cout << "Enter value (1 - 2): ";
    cin >> choice;
    if (choice == 1)
    {
        int size;
        cout << "Enter size of array: ";
        cin >> size;
        ArrayQueue a(size);
        system("cls");
    Selector:
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print Queue" << endl;
        cout << "4. exit" << endl;
        cout << "Enter value (1 - 4):";
        cin >> select;
        switch (select)
        {
        case 1:
        {
            cout << "Enter value to endqueue: ";
            cin >> enqueueValue;
            a.enqueue(enqueueValue);
            system("cls");
            goto Selector;
        }
        break;
        case 2:
            a.dequeue();
            system("cls");
            goto Selector;
            break;
        case 3:
            a.printQueue();
            cout << endl
                 << endl;
            goto Selector;
            break;
        case 4:
            break;
        default:
            cout << "Enter value from 1 to 4" << endl;
            goto Selector;
            break;
        }
    }
    else
    {
        LinkedListQueue a;
    LinkedListSelector:
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print Queue" << endl;
        cout << "4. exit" << endl;
        cout << "Enter value (1 - 4):";
        cin >> select;
        switch (select)
        {
        case 1:
        {
            cout << "Enter value to endqueue: ";
            cin >> enqueueValue;
            a.enqueue(enqueueValue);
            system("cls");
            goto LinkedListSelector;
        }
        break;
        case 2:
            a.dequeue();
            system("cls");
            goto LinkedListSelector;
            break;
        case 3:
            cout << "------------" << endl;
            a.printQueue();
            cout << endl
                 << "------------" << endl
                 << endl;
            goto LinkedListSelector;
            break;
        case 4:
            break;
        default:
            cout << "Enter value from 1 to 4" << endl;
            goto LinkedListSelector;
            break;
        }
    }
}
