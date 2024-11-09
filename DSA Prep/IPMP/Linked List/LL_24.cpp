// Pairwise swap of Nodes
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

void insert(Node *temp1, Node *temp2)
{
	Node *newNode = new Node();
	newNode->data = temp2->data;
	newNode->next = temp1->next;
	temp1->next = newNode;
}

void push(Node **head, int data)
{
	Node *newNode = new Node();
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void display(Node *temp)
{
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	Node *head1 = NULL;
	Node *head2 = NULL;
	Node *head3 = NULL;
	for (int i = 9; i > 0; i--)
		push(&head1, i);

	cout << "Given linked list \n";
	display(head1);
	cout << endl;


	return 0;
}
