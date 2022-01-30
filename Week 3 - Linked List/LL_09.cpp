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

void getIntersectionNode()
{
    Node *temp1 = head1;
    Node *temp2 = head2; bool flag = false;
    while (temp1!=NULL)
    {
        temp1->visited = true;
        temp1 = temp1->next;
    }
    while (temp2!=NULL)
    {
        if (temp2->visited == true)
        {
            bool flag = true;
            break;
        } else{
            temp2->visited = true;
            temp2 = temp2->next;
        }
    }
    if (flag)
    {
        cout<<"Intersection exists and it is at: "<<temp2->data<<endl;
    } else{
        cout<<"No intersection"<<endl;
    }
    
    
}

int main()
{
    Node *newNode;

    head1->data = 10;

    Node *head2 = new Node();
    head2->data = 3;

    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;

    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;

    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    getIntersectionNode();
}