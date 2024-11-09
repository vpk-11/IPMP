// Two Stacks in 1 Array
#include <iostream>
#include <stdlib.h>
using namespace std;
int top1, top2;

void push1(int arr[], int n, int x)
{
    if (top1 < top2 - 1)
    {
        top1++;
        arr[top1] = x;
    }
    else
    {
        cout << "Stack Overflow";
        exit(1);
    }
}
void push2(int arr[], int n, int x)
{
    if (top1 < top2 - 1)
    {
        top2--;
        arr[top2] = x;
    }
    else
    {
        cout << "Stack Overflow";
        exit(1);
    }
}
int pop1(int arr[], int n)
{
    if (top1 >= 0)
    {
        int x = arr[top1];
        top1--;
        return x;
    }
    else
    {
        cout << "Stack UnderFlow";
        exit(1);
    }
}
int pop2(int arr[], int n)
{
    if (top2 < n)
    {
        int x = arr[top2];
        top2++;
        return x;
    }
    else
    {
        cout << "Stack UnderFlow";
        exit(1);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    top1 = -1;
    top2 = n;
    push1(arr, n, 10);
    push2(arr, n, 5);
    push1(arr, n, 15);
    push2(arr, n, 11);
    push2(arr, n, 7);
    cout << "Popped element from stack1 is " << pop1(arr, n) << endl;
    cout << "Popped element from stack2 is " << pop2(arr, n)<< endl;
    return 0;
}
