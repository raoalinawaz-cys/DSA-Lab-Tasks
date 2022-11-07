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
class list{
	public:
	Node *head;
	list();
	void createNode(int value);
	void displayNodes();
	void mergeListAlternatively(list *secondList);
	Node *removeNode(int data);
};
list::list()
{
	head = NULL;
}
void list::createNode(int value)
{
	Node *newnode = new Node();
	newnode ->data = value;
	if(head == NULL)
	{
		head = newnode;
		return;
	}
	Node *temp = head;
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	temp-> next = newnode;
	
}
void list::displayNodes()
{
	if(head == NULL)
	{
		cout << "list is empty" << endl;
		return;
	}
	Node *temp = head;
	while(temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	
}
Node *list::removeNode(int data)
{
	Node *temp = head;
	Node *prev = NULL;
	if(head == NULL)
	{
		//cout << "List is empty";
		return NULL;
	}                   
	if(head->data == data)
	{
		head = head -> next;
		temp -> next = NULL;
		return temp;
	}
	while(temp->next != NULL)
	{
		if(temp->data == data)
		{
			prev -> next = temp->next;
			temp -> next = NULL;
			return temp;
		}
		cout << "found"  << temp -> data << endl;
		prev = temp;
		temp = temp->next;
	}            
	prev -> next = NULL;
	temp -> next = NULL;
	return temp;
}
void list::mergeListAlternatively(list *secondList)
{
	Node *first = head;
	Node *second = secondList->head;
	Node *temp = NULL;
	Node *placer = NULL;
	while(first != NULL)
	{     	
		temp = secondList->removeNode(second->data);
		second = secondList->head;
		if(temp == NULL) return;
		placer = first;
		first = first -> next;
		temp-> next = placer -> next;
		placer-> next = temp;
		if(second == NULL) return;
	}                         
}
int main()
{
	list first;
	first.createNode(1);
	first.createNode(5);
	first.createNode(7);
	first.createNode(3);
	first.createNode(9);
	list second;
	second.createNode(6);
	second.createNode(10);
	second.createNode(2);
	second.createNode(4);
	/*
	list first;
	first.createNode(1);
	first.createNode(2);
	first.createNode(3);
	list second;
	second.createNode(4);
	second.createNode(5);
	second.createNode(6);
	second.createNode(7);
	*/
	cout << endl << "--------------------------" << endl;
	cout << "Before merging: " << endl;
	cout << "--------------------------" << endl;
	cout << "List 1: ";
	first.displayNodes();
	cout << endl << "List 2: ";
	second.displayNodes();
	cout << endl;
	first.mergeListAlternatively(&second);
	cout << endl << "--------------------------" << endl;
	cout << "After merging: " << endl;
	cout << "--------------------------" << endl;
	cout << "List 1: ";
	first.displayNodes();
	cout << endl << "List 2: ";
	second.displayNodes();
}
