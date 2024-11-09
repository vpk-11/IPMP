// Count number of numbers with even digit sum
#include <iostream>
#include <vector>
using namespace std;

int countEven(int num){
    int count = 0;
    for (int i = 1; i <= num; i++)
    {
        int sum = 0;
        int n = i;
        while (n>0)
        {
            sum+= n%10;
            n/=10;
        }
        if(sum%2 == 0){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<"Count: "<<countEven(n)<<endl;
}