// Bubble Sort
#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int a[], int n){
    
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}

int main(){

}