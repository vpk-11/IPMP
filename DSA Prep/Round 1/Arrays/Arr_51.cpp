// Stock Buy Sell Problem
#include <iostream>
#include <vector>
using namespace std;

int stockBuySell(int price[], int n)
{
    vector<pair<int, int> > v;
    int curr = 0;
    int flag = 0;
    for (int i = 1; i < n; i++)
    {
        while (i < n && price[i] > price[i - 1])
        {
            i++;
        }
        if (curr != i - 1)
        {
            v.push_back(make_pair(curr, i - 1));
            flag = 1;
        }
        curr = i;
    }
    if (flag == 0)
    {
        cout << "No Profit" << endl;
    }
    int totalProfit = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "(" << v[i].first << " " << v[i].second << ")"
             << "Profit: " << price[v[i].second] - price[v[i].first] << endl;
        totalProfit += price[v[i].second] - price[v[i].first];
    }
    return totalProfit;
}

int main()
{
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price) / sizeof(price[0]);

    cout << "Total Profit: " <<stockBuySell(price, n) << endl;
}