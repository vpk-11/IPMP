// No of Set Bits
#include <iostream>
using namespace std;

int noOfSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}

int main()
{
    int num;
    cin>>num;
    cout<<"No of Set Bits in "<<num<<" = "<<noOfSetBits(num)<<endl;
    return 0;
}