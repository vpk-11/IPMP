#include<iostream>
using namespace std;

bool isPalindrome(int num){
    int n, rev;
    n = num; rev = 0;
    while(num>0){
        rev = (rev*10) + (num%10);
        num/=10;
    }
    if (n == rev)
    {
        return true;
    }else{
        return false;
    }
    
}
int main(){
    
    int num;
    cin>>num;

    while (!isPalindrome(num))
    {
        num +=1;
    }
    
    cout<<"Next Palindrome is: "<<num<<endl;

    return 0;
}