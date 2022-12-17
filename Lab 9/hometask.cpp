#include <iostream>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
    Node()
    {
        next = NULL;
    }
};
class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    Node *createNode()
    {
        Node *newnode = new Node();
        return newnode;
    }
    void push(char c)
    {
        Node *newnode = createNode();
        newnode->data = c;
        if (top == NULL)
        {
            top = newnode;
            return;
        }
        newnode->next = top;
        top = newnode;
    }
    Node *pop()
    {
        if (top == NULL)
        {
            cout << "Stack is already empty";
            return NULL;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            return temp;
        }
    }
    char topElement()
    {
        return top->data;
    }
    void displayStack()
    {
        if (top == NULL)
        {
            cout << "Stack is empty";
        }
        else
        {
            Node *temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
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
    void enqueue(char c)
    {
        Node *newnode = createNode();
        newnode->data = c;
        if (front == NULL && rear == NULL)
        {
            front = newnode;
            rear = newnode;
            return;
        }
        rear->next = newnode;
        rear = newnode;
    }
    Node *dequeue()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "Queue is empty";
            return NULL;
        }
        else if (front == rear)
        {
            front = NULL;
            rear = NULL;
            return NULL;
        }
        Node *temp = front;
        front = front->next;
        return temp;
    }
    char topElement()
    {
        return front->data;
    }
    void displayQueue()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "Queue is empty";
            return;
        }
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    string s;
    Stack st;
    Queue q;
    bool palindrome = true;
    char c;
    int choice = 0;
Menu:
    system("cls");
    switch (choice)
    {
    case 0:
    {
        cout << "Enter a character: ";
        cin >> c;
        s = s + char(tolower(c));
        for (int i = 0; s[i] != '\0'; i++)
        {
            st.push(s[i]);
            q.enqueue(s[i]);
        }
        while (st.top != NULL && q.front != NULL)
        {
            if (st.topElement() == q.topElement())
            {
                st.pop();
                q.dequeue();
                palindrome = true;
                continue;
            }
            else
            {
                palindrome = false;
                break;
            }
        }
        while (st.top != NULL && q.front != NULL)
        {
            st.pop();
            q.dequeue();
        }
        cout << endl
             << s << "        ";
        if (palindrome)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
        cout << endl
             << endl
             << endl;
        cout << "0. Continue" << endl;
        cout << "1. Exit" << endl;
        cout << endl
             << "Enter choice :";
        cin >>
            choice;
        goto Menu;
    }
    break;
    case 1:
        break;
    default:
        cout << "Enter value 0 or 1";
        goto Menu;
    }
}