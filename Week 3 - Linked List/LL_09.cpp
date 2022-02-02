// Intersection point of two lists
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    bool visited;
};
Node *head1 = new Node;
Node *head2 = new Node;

void create2(Node *head)
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

int length(Node *head)
{
    Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int _getIntesectionNode(int d, Node *head1, Node *head2)
{
    Node *current1 = head1;
    Node *current2 = head2;

    for (int i = 0; i < d; i++)
    {
        if (current1 == NULL)
        {
            return -1;
        }
        current1 = current1->next;
    }

    while (current1 != NULL && current2 != NULL)
    {
        if (current1 == current2)
            return current1->data;

        current1 = current1->next;
        current2 = current2->next;
    }

    return -1;
}
int getIntesectionNode(Node *head1, Node *head2)
{
    int c1 = length(head1);
    int c2 = length(head2);
    if (c1 > c2)
        return _getIntesectionNode(c1 - c2, head1, head2);

    else
        return _getIntesectionNode(c2 - c1, head2, head1);
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
    create2(head1);
    create2(head2);
    head1->next->next = head2->next;
    display(head1);
    cout<<endl;
    display(head2);
    cout<<endl;
    int x = getIntesectionNode(head1,head2);
    if(x!= -1)
        cout << "Data at point of intersection is " << x << endl;
    else
        cout<<"There is no point of intersection"<<endl;
}
