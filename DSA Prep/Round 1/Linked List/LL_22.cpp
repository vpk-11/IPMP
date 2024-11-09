// Add 2 Numbers represented by LL
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *head1 = new Node;
Node *head2 = new Node;
Node *sumList = new Node;

void display(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        display(p->next);
    }
}
int length(Node *temp)
{
    int size = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}
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
void insertAtFront(Node *head, int data)
{
    Node *temp = new Node;
    temp->data = data;
    if (head == NULL)
        temp->next = NULL;
    else
        temp->next = head;
    head = temp;
}
void push(Node **head, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

vector<int> addListNodes(Node *temp1, Node *temp2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    if (l1 < l2)
    {
        int d = l2 - l1;
        for(int i = 0; i<d; i++)
            push(&head1, 0);

        display(head1);
        cout<<endl;
    }
    else if (l2 < l1)
    {
        int d = l1 - l2;
        for(int i = 0; i<d; i++)
            push(&head2, 0);
        display(head2);
        cout<<endl;
    }
    vector<int> s1, s2, sumStack;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        s1.push_back(temp1->data);
        s2.push_back(temp2->data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    int sum = 0, carry = 0;
    if (s1.size() != s2.size())
    {
        cout<<"No"<<endl;
    }
    
    for (int i = s1.size()-1; i >= 0; i--)
    {
        sum = s1[i] + s2[i] + carry;
        carry = sum / 10;
        sum = sum %10;
        sumStack.push_back(sum);
    }
    if (carry != 0)
        sumStack.push_back(carry);

    return sumStack;
}
int main()
{
    create(head1);
    create(head2);
    cout << "List 1 is: ";
    display(head1);
    cout << endl;
    cout << "List 2 is: ";
    display(head2);
    cout << endl;
    vector<int> s = addListNodes(head1, head2);
    cout << "Sum is: ";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}