// Stack with push, pop & getMin in O(1) time
#include <iostream>
#include <climits>
using namespace std;

class Stack
{
public:
    int data;
    Stack *next;
};
Stack *top = new Stack;
Stack *min = NULL;
Stack *newNode(int data)
{
    Stack *p = new Stack;
    p->data = data;
    p->next = NULL;
    return p;
}

void push(int data)
{
    Stack *p = newNode(data);
    // if(min == NULL || (min->data > p->data)){
    //     min = p;
    // }
    p->next = top;
    top = p;
    cout << data << " pushed to stack\n";
}

int pop()
{
    if (top ==  NULL){

        return -1;
    }
    Stack *temp = top;
    top = top->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek()
{
    if (top == NULL){
        return -1;
    }
    return top->data;
}
// int getMin(){
//     if(min == NULL){
//         return -1;
//     }
//     return min->data;
// }

int main()
{
    push(10);
    push(20);
    push(30);

    cout << pop() << " popped from stack\n";

    cout << "Top element is " << peek() << endl;

    cout << "Elements present in stack : ";
    while (top != NULL)
    {
        cout << peek() << " ";
        pop();
    }
    return 0;
}