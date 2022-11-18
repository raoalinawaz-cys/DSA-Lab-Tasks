#include <iostream>
#define SIZE 4
using namespace std;
class stack
{
public:
    int arr[SIZE];
    int top = -1;
    void push(int data)
    {
        if (top == SIZE - 1)
        {
            cout << "Stack is full";
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
        }
        else
        {
            cout << arr[top] << " Popped" << endl;
            top--;
        }
    }
    void printStack()
    {
        cout << "-------" << endl;
        cout << "Stack" << endl;
        cout << "-------" << endl;

        if (top == -1)
        {
            cout << "Stack is empty";
        }
        else
        {
            while (top != -1)
            {
                cout << top << " > ";
                cout << arr[top] << endl;
                top--;
            }
        }
    }
};
int main()
{
    stack browser;
    browser.push(4);
    browser.push(5);
    browser.pop();
    // browser.pop();
    browser.printStack();
}