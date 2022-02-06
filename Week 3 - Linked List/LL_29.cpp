#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};
Node *head = new Node;
void create(Node *head)
{
    cout << "Enter Head Data: ";
    int x;
    cin >> x;
    if (x != -1)
        head->data = x;
    else
        return;
    Node *temp = head;
    while (x != -1)
    {
        printf("Enter data of the next node of %d: ", temp->data);
        cin >> x;
        if (x != -1)
        {
            Node *p = new Node;
            p->data = x;
            p->next = NULL;
            temp->next = p;
            temp = p;
        }
        else
            break;
    }
}
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,
					Node** frontRef, Node** backRef);

void MergeSort(Node** headRef)
{
	Node* source = *headRef;
	Node* a;
	Node* b;

	if ((source == NULL) || (source->next == NULL)) {
		return;
	}

	FrontBackSplit(source, &a, &b);

	MergeSort(&a);
	MergeSort(&b);

	*headRef = SortedMerge(a, b);
}

Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

void FrontBackSplit(Node* source,
					Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->next;

	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

void display(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        display(p->next);
    }
}

int main()
{
	Node* res = NULL;
	create(head);
	MergeSort(&head);

	cout << "Sorted Linked List is: \n";
	display(head);

	return 0;
}
