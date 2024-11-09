// Union and Intersection of 2 Arrays
#include <iostream>
#include <vector>
using namespace std;

vector<int> Intersection(vector<int> a, vector<int> b)
{
    vector<int> v;
    if (a.size() == 0 || b.size() == 0)
    {
        return v;
    }
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] == b[j])
        {
            v.push_back(a[i]);
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return v;
}

vector<int> Union(vector<int> a, vector<int> b)
{
    if (a.size() == 0)
    {
        return b;
    }
    if (b.size() == 0)
    {
        return a;
    }
    int i = 0, j = 0;
    vector<int> v;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            v.push_back(a[i++]);
        }
        else if (a[i] == b[j])
        {
            v.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] > b[j])
        {
            v.push_back(b[j++]);
        }
    }
    while (i < a.size())
    {
        v.push_back(a[i++]);
    }
    while (j < b.size())
    {
        v.push_back(b[j++]);
    }
    return v;
}

int main()
{
    vector<int> v, w;
    int n1;
    int n2;
    int x;
    vector<int> a, b;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++)
    {
        cin>> x;
        a.push_back(x);
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> x;
        b.push_back(x);
    }
    v = Union(a, b);
    cout << "Union = ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    w = Intersection(a, b);
    cout << "Intersection = ";
    for (int i = 0; i < w.size(); i++)
    {
        cout << w[i] << " ";
    }
    cout << endl;
}