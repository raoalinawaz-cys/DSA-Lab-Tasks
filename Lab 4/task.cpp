// Linked List operations
// By RAO ALI NAWAZ
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void printLinkedList(node *head)
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void insertDataStart(node **head, int value)
{
    node *newnode;
    newnode = new node();
    newnode->next = *head;
    newnode->data = value;
    *head = newnode;
}
void insertNodeInTheEnd(node *head, int value)
{
    node *newnode;
    newnode = new node();
    newnode->data = value;
    newnode->next = NULL;

    node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void deleteNode(node **head, int value)
{
    node *temp = *head;
    if ((*head)->data == value)
    {
        *head = (*head)->next;
        delete temp;
    }
    else
    {
        node *check = *head;
        while (check != NULL)
        {
            if (check->next->data == value)
            {
                // if(check -> next -> next == NULL)
                temp = check->next;
                check->next = check->next->next;
                delete temp;
                break;
            }
            else
            {
                check = check->next;
            }
        }
    }
}
void updataData(node *head, int value, int data)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            temp->data = data;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
}
void insertData(node *head, int data, int value)
{
	node *temp = head;
	node *newnode = new node();
	newnode -> data = value;
	while(temp -> data != data)
	{
		temp = temp -> next;
	}
	newnode -> next = temp -> next;
	temp -> next = newnode;
	
}
int main()
{
    	node *head, *middle, *last;
	head = new node();    
	head->data = 2;
	head -> next = NULL;
	insertNodeInTheEnd(head, 3);
	insertData(head, 2, 5);
	insertData(head, 3, 9);
	//deleteNode(&head, 2);
	printLinkedList(head);
}