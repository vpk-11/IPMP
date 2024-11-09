// sort even and odd indices seperately
#include <iostream>
#include <vector>

using namespace std;

vector<int> sortEvenOdd(vector<int> nums)
{
    if(nums.size()==2){
        return nums;
    }
    int counter = 2;

    while(counter < nums.size())
    {
        for (int i = 0  ; i < nums.size() - counter; i+=2)
        {
           if (nums[i]>nums[i+2]){
               int temp = nums[i];
               nums[i] = nums[i+2];
               nums[i+2] = temp;
           }
        }
        counter+=2;
    }
    counter = 1;
    while(counter < nums.size())
    {
        for (int i = 1  ; i < nums.size() - counter; i+=2)
        {
           if (nums[i] < nums[i+2]){
               int temp = nums[i];
               nums[i] = nums[i+2];
               nums[i+2] = temp;
           }
        }
        counter+=2;
    }
    return nums;
}

int main(){
    vector<int> v;
    v.push_back(6);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }cout<<endl;
    v = sortEvenOdd(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}