// Perfect Sqaure Triplet (Pythagorean Triplet)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// int countPythagoreanTriplet(int n){
//     int count = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = i; j <= n; j++)
//         {
//             for (int k = j; k <= n; k++)
//             {
//                 if (k*k == i*i + j*j)
//                 {
//                     count++;
//                 }
//             }
//         }
//     }
//     return count;
// }

vector<int> getperfSq(int n)
{
    vector<int> perfSq;
    int current = 1, i = 1;
    while (current <= n)
    {
        perfSq.push_back(current);
        i++;
        current = i * i;
    }
    return perfSq;
}

int countTriplets(int n)
{
    vector<int> perfSq = getperfSq(n * n);
    int count = 0;
    for (int a = 1; a <= n; a++)
    {
        int aSquare = a * a;

        for (int i = 0; i < perfSq.size(); i++)
        {
            int cSquare = perfSq[i];

            int bSquare = abs(cSquare - aSquare);
            int b = sqrt(bSquare);
            int c = sqrt(cSquare);

            if (c < a || (find(perfSq.begin(), perfSq.end(), bSquare) == perfSq.end()))
            {
                continue;
            }

            if ((b >= a) && (b <= c) && (aSquare + bSquare == cSquare))
            {
                count++;
            }
        }
    }
    return count;
}
// Driver code
int main()
{
    int n = 10;

    cout << countTriplets(n) << endl;

    return 0;
}

// int main(){
//     int n = 10;
//     cout << countPythagoreanTriplet(n) << endl;
//     return 0;
// }