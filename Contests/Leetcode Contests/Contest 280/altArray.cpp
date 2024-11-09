// Min number of ops required to convert into alt array
#include <iostream>
#include <vector>
using namespace std;

int minNoOfOps(vector<int> &nums)
{
    int count = nums.size();
    int temp = 0;
    for (int i = 2; i < count; i++)
    {
        if (i % 2 == 0 && nums[i] != nums[0])
        {
            nums[i] = nums[0];
            temp++;
        }
        else if (i % 2 != 0 && nums[i] != nums[1])
        {
            nums[i] = nums[1];
            temp++;
        }
    }
    return temp;
}
int main()
{
    int count;
    cin >> count;
    vector<int> nums;
    int x;
    for (int i = 0; i < count; i++)
    {
        cin>>x;
        nums.push_back(x);
    }
    // do
    // {
    //     cin >> x;
    //     nums.push_back(x);
    // } while (x != '\n');

    int temp = minNoOfOps(nums);
    cout << "Min No of Ops = " << temp << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}