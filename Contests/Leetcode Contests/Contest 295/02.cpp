// Apply Discount to prices

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>
using namespace std;

double toDouble(string s, int dis){
    double num;
    stringstream ss;
    ss >> s;
    ss >> num;

    num /= dis;
    return num;
}

string discountPrices(string str, int discount)
{
    vector<pair<string, double> > v;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '$')
        {
            string mod;
            while (i < str.size() - 1 && str[i+1] != ' ')
            {
                if (str[i + 1] == '$')
                {
                    mod.erase();
                    break;
                }
                else
                {
                    mod.push_back(str[i+1]);
                }
            }
            if (mod[0] != '\0')
            {
                pair<string, double> p;
                p.first = mod;
                p.second = stod(mod);
                v.push_back(p);
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        v[i].second /= discount;
    }
    string output;
    for (size_t i = 0; i < count; i++)
    {
        /* code */
    }
    
}

int main()
{

}