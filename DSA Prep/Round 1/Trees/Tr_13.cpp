// Diff between Even & Odd Level sums
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
Node *root = new Node;

void create(Node *root)
{
    queue<Node *> q;
    Node *p, *t;
    int x;
    cout << "Enter Root Value ";
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        printf("Enter lchild Child of %d: ", p->data);
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        printf("Enter rchild Child of %d: ", p->data);
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}

void Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

int count(Node *p)
{
    if (p)
        return count(p->lchild) + count(p->rchild) + 1;

    return 0;
}

void DiffLevelSuperSum(Node *p)
{
    queue<Node *> q;
    q.push(p);
    int level = 0;
    int evenSum = 0, oddSum = 0;
    while (!q.empty())
    {
        int size = q.size();
        level += 1;

        while(size > 0)
        {
            p = q.front();
            q.pop();
 
            if(level % 2 == 0)
                evenSum += p->data;
            else
                oddSum += p->data;
         
            if (p->lchild)
            {
                q.push(p->lchild);
            }
            if (p->rchild)
            {
                q.push(p->rchild);
            }
            size -= 1;
        }
    }
    cout<<endl<<"Diff Sum = "<<evenSum - oddSum<<endl;
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    DiffLevelSuperSum(root);
    cout << endl;

    return 0;
}