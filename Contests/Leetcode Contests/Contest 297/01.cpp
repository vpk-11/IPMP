#include <iostream>
#include <vector>
using namespace std;

double calculateTax(int br[][2], int n, int income)
{
    double tax = 0;
    bool flag = true;
    for (int i = 0; i < n && flag; i++)
    {
        double d;
        if (br[i][0] <= income)
        {
            if (i == 0)
            {
                d = (br[i][1] * br[i][0]);
                cout << d << endl;
            }
            else
            {
                d = (br[i][1] * (br[i][0] - br[i - 1][0]));
                cout << d << endl;
            }
        }
        else
        {
            if (i == 0)
            {
                d = (br[i][1] * income);
                cout << d << endl;
            }
            else
            {
                d = (br[i][1] * (income - br[i - 1][0]));
                cout << d << endl;
            }
            flag = false;
        }
        tax = tax + d;
    }
    return tax / 100;
}

int main()
{
    int arr[][2] = {{1, 0}, {4, 25}, {5, 50}};
    int income = 2;
    int n = 3;
    double tax = calculateTax(arr, n, income);
    cout << "Tax is " << tax << endl;
}