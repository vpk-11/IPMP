#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minTrps(vector<int> time, int totalTrips)
{
    int trips = 0;
    int clock = 1;
    vector<int> trp(time.size());
    for (int i = 0; i < time.size(); i++)
    {
        if (time[i] <= clock)
        {
            trp[i]++;
        }
    }
    for (int i = 0; i < trp.size(); i++)
    {
        trips += trp[i];
    }
}
int main()
{
}