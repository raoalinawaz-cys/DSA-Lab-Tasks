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
    void push(int data)
    {
        Node *newnode = new Node();
        newnode->data = data;
        if (top == NULL)
        {
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            top = top->next;
        }
    }
    void displayStack()
    {
        Node *temp = top;
        if (top == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }
    bool is_empty()
    {
        if (top == NULL)
            return 1;
        return 0;
    }
    void sort(Stack *t)
    {
        while (!is_empty())
        {
            int temp = top->data;
            pop();
            while (!t->is_empty() && t->top->data > temp)
            {
                push(t->top->data);
                t->pop();
            }
            t->push(temp);
        }
    }
};
int main()
{
    Stack s, t;
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(8);
    cout << "------------------------" << endl;
    cout << "Before Sorting" << endl;
    cout << "------------------------" << endl;
    cout << "S : ";
    s.displayStack();
    cout << endl
         << "T : ";
    t.displayStack();
    s.sort(&t);
    cout << "------------------------" << endl;
    cout << "After Sorting" << endl;
    cout << "------------------------" << endl;
    cout << "S : ";
    s.displayStack();
    cout << "T : ";
    t.displayStack();
}