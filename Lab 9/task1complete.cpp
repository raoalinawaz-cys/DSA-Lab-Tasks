#include <iostream>
#include <string>
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
class Linkedlist
{
public:
    char data;
    Node *head;
    Linkedlist()
    {
        head = NULL;
    }
    void push(char value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    Node *lastNode()
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp;
    }
    void displayList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
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
    void push(char data)
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
};
class intNode
{
public:
    int data;
    intNode *next;
    intNode()
    {
        next = NULL;
    }
};
class intStack
{
public:
    intNode *top;
    intStack()
    {
        top = NULL;
    }
    void push(int data)
    {
        intNode *newnode = new intNode();
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
        intNode *temp = top;
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
};
void infixToPostfix(Linkedlist &postFix, string infix, Stack &s)
{
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if ((infix[i] >= '0' && infix[i] <= '9'))
        {
            postFix.push(infix[i]);
        }
        else
        {
            if (s.top == NULL)
            {
                s.push(infix[i]);
            }
            else if (infix[i] == '+' || infix[i] == '-')
            {
                if (s.top->data == '+' || s.top->data == '-' || s.top->data == '*' || s.top->data == '/' || s.top->data == '^')
                {
                    postFix.push(s.top->data);
                    s.pop();
                    s.push(infix[i]);
                }
                else if (s.top->data == '[' || s.top->data == '{' || s.top->data == '(')
                {
                    s.push(infix[i]);
                }
            }
            else if (infix[i] == '*' || infix[i] == '/')
            {

                // cout << infix[i] << endl;
                if (s.top->data == '^')
                {
                    postFix.push(s.top->data);
                    s.pop();
                    s.push(infix[i]);
                }
                else if (s.top->data == '*' || s.top->data == '/')
                {
                    postFix.push(s.top->data);
                    s.pop();
                    s.push(infix[i]);
                }
                else if (s.top->data == '{' || s.top->data == '[' || s.top->data == '(')
                {
                    s.push(infix[i]);
                }
                else if (s.top->data == '+' || s.top->data == '-')
                {
                    s.push(infix[i]);
                }
            }
            else if (infix[i] == '^')
            {
                s.push(infix[i]);
            }
            else if (infix[i] == '[' || infix[i] == '{' || infix[i] == '(')
            {
                s.push(infix[i]);
            }
            else if (infix[i] == ']' || infix[i] == '}' || infix[i] == ')')
            {
                Node *temp = s.top;
                while (temp != NULL)
                {
                    temp = s.top;
                    if (s.top->data == '[' || s.top->data == '{' || s.top->data == '(')
                    {
                        s.pop();
                        break;
                    }
                    postFix.push(s.top->data);
                    s.pop();
                }
            }
        }
        // postFix.displayList();
        // cout << endl;
    }
    while (s.top != NULL)
    {
        postFix.push(s.top->data);
        s.pop();
    }
}
int postFixEvaluate(Linkedlist &postFix)
{
    intStack st;
    Node *temp = postFix.head;
    int value = 0;
    while (temp != NULL)
    {
        if (temp->data >= '0' && temp->data <= '9')
        {
            st.push(temp->data - 48);
        }
        else
        {
            if (temp->data == '+')
            {
                value = ((st.top->next->data) + (st.top->data));
            }
            else if (temp->data == '-')
            {
                value = ((st.top->next->data) - (st.top->data));
            }
            else if (temp->data == '/')
            {
                value = ((st.top->next->data) / (st.top->data));
            }
            else if (temp->data == '*')
            {
                value = ((st.top->next->data) * (st.top->data));
            }
            st.pop();
            st.pop();
            st.push(value);
        }
        temp = temp->next;
    }
    return st.top->data;
}
bool validExpression(string s)
{
    int n1 = 0;
    int n2 = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            n1++;
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            n2++;
        }
    }
    if (n2 == (n1 - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    Stack s;
    Linkedlist postFix;
    string infix;
    // infix = "84+342-*/8*741+-*";
    // infix = "8+7*{6/(3+4*5/6)+3-2}*4-2";
    cout << "Enter expression : ";
    cin >> infix;

    if (!validExpression(infix))
    {
        cout << "Not a valid expression";
    }
    else
    {
        char last;
        for (int i = 0; infix[i] != '\0'; i++)
        {
            last = infix[i];
        }
        Node *temp = postFix.head;
        if (last >= '0' && last <= '9')
        {
            infixToPostfix(postFix, infix, s);
        }
        else
        {
            for (int i = 0; infix[i] != '\0'; i++)
            {
                postFix.push(infix[i]);
            }
        }
        postFix.displayList();
        cout << endl
             << "Value : " << postFixEvaluate(postFix);
    }
}