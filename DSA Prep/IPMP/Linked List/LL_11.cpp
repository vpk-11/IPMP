// Union and Intersection of 2 Lists
#include <iostream>
#include <vector>
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
bool isPresent(Node *temp, int data)
{
    while (temp!=NULL)
    {
        if(temp->data == data)
            return true;
        temp = temp->next;
    }
    return false;
}
void getIntesectionNodes(Node *temp1, Node *temp2)
{
    vector<int> v;
    while (temp1!=NULL)
    {
        if(isPresent(head2,temp1->data))
            v.push_back(temp1->data);
        
        temp1 = temp1->next;
    }
    if(v.size()){
        cout<<"Intersection of the 2 Lists is: ";
        for(int i = 0; i<v.size(); i++)
            cout<<v[i]<<" ";
    } else{
        cout<<"No Intersection";
    }
    cout<<endl;
    
}
void getUnionOfNodes(Node *temp1, Node *temp2)
{
    vector<int> v;
    while (temp1!=NULL)
    {
        v.push_back(temp1->data);    
        temp1 = temp1->next;
    }
    while (temp2!=NULL)
    {
        if(!isPresent(head1,temp2->data))
            v.push_back(temp2->data);
        
        temp2 = temp2->next;
    }
    if(v.size()){
        cout<<"Union of the 2 Lists is: ";
        for(int i = 0; i<v.size(); i++)
            cout<<v[i]<<" ";
    } else{
        cout<<"No Union";
    }
    cout<<endl;
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
    display(head1);
    cout << endl;
    display(head2);
    cout << endl;
    getIntesectionNodes(head1, head2);
    getUnionOfNodes(head1, head2);
}