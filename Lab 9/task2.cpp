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
class Queue
{
public:
    Node *front;
    Node *rear;
    Queue()
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
    void displayQueue()
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
    void reverseDisplay(Node *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        reverseDisplay(temp->next);
        cout << temp->data << " ";
    }
};
int main()
{
    Queue q;
    q.enqueue(3);
    q.enqueue(8);
    q.enqueue(5);
    q.enqueue(9);
    q.enqueue(16);
    // q.dequeue();
    // q.dequeue();
    q.displayQueue();
    cout << endl
         << "Reverse Order: ";
    q.reverseDisplay(q.front);
}