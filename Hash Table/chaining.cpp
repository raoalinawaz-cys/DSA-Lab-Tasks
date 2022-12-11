#include <iostream>
#define SIZE 7
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
// class Linkedlist
// {
// public:
//     Node *head;
//     Linkedlist()
//     {
//         head = NULL;
//     }
//     Node *createNode()
//     {
//         Node *newnode = new Node();
//         return newnode;
//     }
//     void insertAthead(int value)
//     {
//         Node *newnode = createNode();
//         newnode->data = value;
//         if (head == NULL)
//         {
//             head = newnode;
//         }
//         else
//         {
//             newnode->next = head;
//             head = newnode;
//         }
//     }
//     void display()
//     {
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << "NULL";
//     }
// };
void insert(int value, Node **chain)
{
    Node *newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;
    int key = value % SIZE;
    if (chain[key] == NULL)
    {
        chain[key] = newnode;
    }
    else
    {
        Node *temp = chain[key];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void print(Node **chain)
{
    for (int i = 0; i < SIZE; i++)
    {
        Node *temp = chain[i];
        cout << "Chain[" << i << "] >>> ";
        while (temp != NULL)
        {
            cout << temp->data << " > ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}
int main()
{
    Node *chain[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        chain[i] = NULL;
    }
    insert(5, chain);
    insert(6, chain);
    insert(0, chain);
    insert(8, chain);
    insert(123, chain);
    insert(9, chain);
    insert(12, chain);
    insert(10, chain);
    insert(11, chain);

    print(chain);
    // for (int i = 0; i < SIZE; i++)
    // {
    //     Node *temp = chain[i];
    //     cout << "Chain[" << i << "] >>> ";
    //     while (temp != NULL)
    //     {
    //         cout << temp->data << " > ";
    //         temp = temp->next;
    //     }
    //     cout << "NULL" << endl;
    // }
}