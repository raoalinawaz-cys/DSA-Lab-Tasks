#include <iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
	Node *prev;
	void readNode();
	Node();
};
Node::Node()
{
	next = NULL;
	prev = NULL;
}                
void Node::readNode()
{
	cin >> data;
}
class Doublylist{
	public:
	Node *head = NULL;
	void createNode();
	void displayList();
};
void Doublylist::createNode()
{                       
	Node *newnode = new Node();
	newnode->readNode();
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{           
		Node *temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
	}
}
void Doublylist::displayList()
{
	if(head == NULL)
	{
		cout << "List is empty";
		return;
	}
	Node *temp = head;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}
int main()
{
	Doublylist *list;
	list->createNode();
	list->createNode();
	list->createNode();
	list->createNode();
	list->createNode();
	list->displayList();
}