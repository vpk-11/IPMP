#include <iostream>
#include <vector>
using namespace std;

int countCollissions(string directions)
{
    int count = 0;
    int i = 0;
    while (i < directions.size() - 1)
    {
        if (directions[i] != directions[i + 1])
        {
            if (directions[i] == 'S')
            {
                count++;
                directions[i+1] = 'S';
            }else if(directions[i+1] == 'S'){
                count++;
                directions[i+2] = 'S';
            }
            else
            {
                count += 2;
                i++;
            }
        }else{
            if (directions[i+1] != 'S')
            {
                i++;
            }
        }
        i++;
    }
    return count;
}

int main()
{
    string directions = "RRLL";
    cout << countCollissions(directions) << endl;
}