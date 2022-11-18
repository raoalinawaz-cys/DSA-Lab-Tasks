#include <iostream>
#include <math.h>
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
    int pop()
    {
        if (top == NULL)
        {
            return 9;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            return temp->data;
        }
    }
    void displayStack()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
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
int stackTop(Stack s1, Stack s2, Stack s3)
{
    if (s1.top != NULL && s1.top->data == 1)
    {
        return 1;
    }
    else if (s2.top != NULL && s2.top->data == 1)
    {
        return 2;
    }
    else if (s3.top != NULL && s3.top->data == 1)
    {
        return 3;
    }
}
void toh(int n, Stack &s1, Stack &s2, Stack &s3)
{
    int i, x, a, b;
    for (i = 0; i < (pow(2, n)); i++)
    {
        cout << "s1 : ";
        s1.displayStack();
        cout << "\ns2 : ";
        s2.displayStack();
        cout << endl
             << "s3 : ";
        s3.displayStack();
        cout << endl
             << endl;

        x = stackTop(s1, s2, s3);
        if (i % 2 == 0)
        {
            if (x == 1)
            {
                s3.push(s1.pop());
            }
            else if (x == 2)
            {
                s1.push(s2.pop());
            }
            else if (x == 3)
            {
                s2.push(s3.pop());
            }
        }
        else
        {
            if (x == 1)
            {
                a = s2.pop();
                b = s3.pop();
                if (a < b && b != 9)
                {
                    s3.push(b);
                    s3.push(a);
                }
                else if (a > b && b != 9)
                {
                    s2.push(a);
                    s2.push(b);
                }
                else if (b == 9)
                {
                    s3.push(a);
                }
                else if (a == 9)
                {
                    s2.push(b);
                }
            }
            else if (x == 2)
            {
                a = s1.pop();
                b = s3.pop();
                if (a < b && b != 9)
                {
                    s3.push(b);
                    s3.push(a);
                }
                else if (a > b && a != 9)
                {
                    s1.push(a);
                    s1.push(b);
                }
                else if (b == 9)
                {
                    s3.push(a);
                }
                else if (a == 9)
                {
                    s1.push(b);
                }
            }
            else if (x == 3)
            {
                a = s1.pop();
                b = s2.pop();
                if (a < b && b != 9)
                {
                    s2.push(b);
                    s2.push(a);
                }
                else if (a > b && a != 9)
                {
                    s1.push(a);
                    s1.push(b);
                }
                else if (b == 9)
                {
                    s2.push(a);
                }
                else if (a == 9)
                {
                    s1.push(b);
                }
            }
        }
    }
}
int main()
{
    Stack s1, s2, s3;
    int n;
    cout << "Enter size of stack: ";
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        s1.push(i);
    }
    toh(n, s1, s2, s3);
}