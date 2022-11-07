#include <iostream>
using namespace std;
class Node
{
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
class Doublylist
{
public:
	Node *head = NULL;
	void createNode();
	void displayList();
	int maxValue();
	void deleteNode(int m);
	void deleteMax();
};
void Doublylist::createNode()
{
	Node *newnode = new Node();
	newnode->readNode();
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
		newnode->prev = temp;
	}
}
void Doublylist::deleteMax()
{
	int max = maxValue();
	deleteNode(max);
}
int Doublylist::maxValue()
{
	Node *temp = head;
	int max = head->data;
	while (temp != NULL)
	{
		if (max < temp->data)
		{
			max = temp->data;
		}
		temp = temp->next;
	}
	cout << "Max number in linked list : " << max << endl;
	return max;
}
void Doublylist::deleteNode(int m)
{
	Node *temp = head;
	Node *deleter;
	Node *nextnode;
	if (head->data == m)
	{
		head = head->next;
		head->prev = NULL;
		delete temp;
		return;
	}
	else
	{
		while (temp->next != NULL)
		{
			if (temp->data == m)
			{
				nextnode = temp->next;
				temp->prev->next = nextnode;
				nextnode->prev = temp->prev;
				return;
			}
			temp = temp->next;
		}
		temp = temp->prev;
		temp->next = NULL;
	}
}
void Doublylist::displayList()
{
	if (head == NULL)
	{
		cout << "List is empty";
		return;
	}
	int i = 1;
	Node *temp = head;
	while (temp != NULL)
	{
		cout << "Node " << i << " Value: " << temp->data << endl;
		temp = temp->next;
		i++;
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
	list->deleteMax();

	list->displayList();
}