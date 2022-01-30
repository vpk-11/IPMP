// triplet from 3 lists for given sum
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

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
void tripleSum(Node **head1, Node **head2, Node **head3, int sum)
{
	Node *temp1 = *head1;
	bool flag = true;
	while (temp1 != NULL && flag)
	{
		int x1 = temp1->data;
		Node *temp2 = *head2;
		while (temp2 != NULL && flag)
		{
			int x2 = temp2->data;
			Node *temp3 = *head3;
			while (temp3 != NULL && flag)
			{
				int x3 = temp3->data;
				if((x1 + x2 + x3) == sum){
					cout<<"Triplet is "<<x1<<", "<<x2<<", "<<x3<<endl;
					flag = false;
				}
				temp3 = temp3->next;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	if (flag)
	{
		cout<<"No such triplet exists"<<endl;
	}
	
}
int main()
{
	Node *head1 = NULL;
	Node *head2 = NULL;
	Node *head3 = NULL;
	for (int i = 9; i > 0; i -= 3)
		push(&head1, i);

	for (int i = 12; i > 0; i -= 4)
		push(&head2, i);

	for (int i = 15; i > 0; i -= 5)
		push(&head3, i);
	cout << "Given linked list \n";
	display(head1);
	cout << endl;
	display(head2);
	cout << endl;
	display(head3);
	cout << endl<<endl;

	int sum;
	cin >> sum;
	tripleSum(&head1, &head2, &head3, 28);

	return 0;
}
