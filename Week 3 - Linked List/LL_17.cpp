// Sort List of 0s, 1s, 2s
#include <iostream>
#include <unordered_map>
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
void sortLL(Node *head)
{
    unordered_map<int, int> map;
    Node *temp = head;

    while (temp != NULL)
    {
        map[temp->data]++;
        temp = temp->next;
    }

    int i = 0, j = 0;
    temp = head;

    while (temp != NULL)
    {
        if (map[i] == 0)
            ++i;
        else
        {
            temp->data = i;
            --map[i];
            temp = temp->next;
        }
    }
}

int main()
{
    Node *head1 = NULL;
    int arr[] = {1, 2, 1, 2, 0, 1, 2, 0, 1, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        push(&head1, arr[i]);

    cout << "Given linked list \n";
    display(head1);
    cout << endl;
    sortLL(head1);
    display(head1);
    cout << endl<<endl;
    return 0;
}
