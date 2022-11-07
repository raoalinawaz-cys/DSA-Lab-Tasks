#include <iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
	Node();
};
Node::Node()
{
	next = NULL;
}
class Linkedlist{
	public:
	Node *head;
	Linkedlist();
	void createNode(int value);
	void displayNodes();
	void swapNodes();
};
Linkedlist::Linkedlist()
{
	head = NULL;
}
void Linkedlist::createNode(int value)
{
	Node *newnode = new Node();
	newnode->data = value;
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		Node *temp = head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newnode;
	}
}
void Linkedlist::displayNodes()
{
	if(head == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	Node *temp = head;
	while(temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}                                      
	
}
void Linkedlist::swapNodes()
{
	Node *first = head;
	Node *second = first -> next;
	int swap;
	while(first -> next != NULL)
	{
		swap = first -> data;
		first -> data = second -> data;
		second -> data = swap;
		if(second->next == NULL) break;
		first = first -> next -> next;
		second = second -> next -> next;
	}
}
int main()
{
	Linkedlist numbers;
	numbers.createNode(1);
	numbers.createNode(2);
	numbers.createNode(3);
	numbers.createNode(4);
	numbers.createNode(5);	
	//numbers.createNode(6);
	numbers.displayNodes();
	cout << endl;
	numbers.swapNodes();
	cout << endl;
	numbers.displayNodes();
}