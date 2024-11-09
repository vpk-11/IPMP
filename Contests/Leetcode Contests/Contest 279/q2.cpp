// sort even and odd indices seperately
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void Pswap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
long long smallestNumber(long long num)
{
    long long  num1 = num, i, n, ans = 0 , temp;
    for (i = 0; num != 0; i++)
    {
        num = num / 10;
    }
    n = i;
    int arr[n];
    num = abs(num1);
    for (i = 0; i < n; i++)
    {
        arr[i] = num % 10;
        num = num / 10;
    }
    sort(arr, arr + n);
    num = num1;
    if (num1 > 0)
    {
        for ( i = 0; i < n; i++)
        {
            if(arr[i] == 0){
                Pswap(&arr[i], &arr[i+1]);
            }
            else {
                break;
            }
        }
        
        ans=arr[0];
        for (i = 1; i < n; i++)
        {
            ans = ans * 10 + arr[i];
        }
        return ans;
    }
    else{
        for (i = n-1; i >= 0; i--)
        {
            
            ans= ans*10 + arr[i];
            cout<<ans<<endl;
        }
        return -ans;
    }
}
int main()
{
    long long int n;
    cin >> n;
    cout << smallestNumber(n);
    return 0;
}


// long long sortEvenOdd(long long nums)
// {
//     if (nums == 0)
//         return 0;
//     vector<int> v;
//     long long n = nums;
//     while (n>0)
//     {
//         int rem = n%10;
//         v.push_back(rem);
//         n/=10;
//     }
//     if(nums>0){
//         sort(v.begin(), v.end());
//         int j = 0;
//         for(j = 0; j<v.size();j++){
//             if(v[j]>0){
//                 swap(&v[j], &v[0]);
//                 break;
//             }
//         }
//         for (int i = 0; i < v.size(); i++)
//         {
//             n = n*10;
//             n+= v[i];
//         }
//         return n;
        
//     } else{
//         sort(v.begin(), v.end(), greater<int>());
//         // int j;
//         // for(j = v.size(); j>0;j--){
//         //     if(v[j]>0){
//         //         swap(&v[j], &v[v.size()]);
//         //         break;
//         //     }
//         // }
//         for (int i = 0; i < v.size(); i++)
//         {
//             n = n*10;
//             n = n + v[i];
//         }
//         return n;
//     }
// }

// int main(){
//     cout<<sortEvenOdd(-7560)<<endl;
// }