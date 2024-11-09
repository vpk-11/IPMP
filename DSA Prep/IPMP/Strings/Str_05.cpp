// print duplicates
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

void printDuplicatesIndices(string str)
{
    // map<char, vector<int> > map;
    // for (int i = 0; i < str.length(); i++)
    // {
    //     map[str[i]].push_back(i);
    // }
    // cout << "Char\t\tIndices" << endl;
    // for (int i = 0; i < map.size(); i++)
    // {
    //     cout << str[i] << "\t\t";
    //     for (int j = 0; j < map[str[i]].size(); j++)
    //     {
    //         cout << map[str[i]][j] << " ";
    //     }
    //     cout << endl;
    // }
    map<char, int> map;
    for (int i = 0; i < str.length(); i++)
        map[str[i]]++;

    for (auto it : map)
    {
        if (it.second > 1){
            cout << it.first << ", count = " << it.second << "\n";
        }
    }
}

int main()
{
    string str = "test string";
    printDuplicatesIndices(str);
}