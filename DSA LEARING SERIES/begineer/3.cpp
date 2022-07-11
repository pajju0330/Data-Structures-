#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#define ll long long int
#define maximum(a, b, c) ((max(a, b) > c) ? max(a, b) : c)
#define pajju main
using namespace std;
int pajju()
{
    ll t;
    cin >> t;
    ll count = 0;
    vector<int> v;
    for (int i = 1; i <= t; i++)
    {
        if (t % i == 0)
        {
            count++;
            v.push_back(i);
        }
    }
    cout << count << endl;
    for (int i = 0; i < v.size(); i++)
    {

        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}