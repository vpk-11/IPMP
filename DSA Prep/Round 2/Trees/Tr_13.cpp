// Difference between sums of odd level and even level nodes of a Binary Tree
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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
        printf("Enter Left Child of %d: ", p->data);
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        printf("Enter Right Child of %d: ", p->data);
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

int diffBtwSumsOfOddEvenLevels(Node *root)
{
    if(root == NULL){
        return 0;
    }
    queue<Node *> q;
    Node *p;
    q.push(root);
    vector<int> sums;
    int result = 0;
    while (!q.empty())
    {
        int count = q.size();
        int sum = 0;
        result = max(count, result);
        while (count > 0)
        {
            p = q.front();
            q.pop();
            if (p->lchild)
            {
                q.push(p->lchild);
                sum += p->lchild->data;
            }
            if (p->rchild)
            {
                q.push(p->rchild);
                sum += p->rchild->data;
            }
            count--;
        }
        sums.push_back(sum);
    }
    result = root->data;
    
    for (int i = 0; i < sums.size(); i++)
    {
        cout << sums[i] << " ";
        if (i % 2 == 0)
        {
            result -= sums[i]; 
        }
        else{
            result += sums[i];
        }
    }
    cout << endl;
    return result;
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    int ans = diffBtwSumsOfOddEvenLevels(root);
    cout << "Difference between sums of odd levels and even levels " << ans << endl;
}
