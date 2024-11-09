#include <iostream>
using namespace std;

int countOpsTillZero(int num1, int num2)
{
    int count = 0;
    while (num1 > 0 && num2 > 0)
    {
        if (num1 > num2)
        {
            num1 -= num2;
            count++;
        }
        else
        {
            num2 -= num1;
            count++;
        }
    }
    return count;
}

int main()
{
    int num1, num2;
    cin>>num1 >> num2;
    cout << "No of Ops = " << countOpsTillZero(num1, num2)<<endl;
}