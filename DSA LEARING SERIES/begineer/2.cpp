#include <iostream>
#include <cmath>
#include <cstring>
#define ll long long int
#define maximum(a, b, c) ((max(a, b) > c) ? max(a, b) : c)
#define pajju main
using namespace std;
int pajju()
{
    ll n;
    cin >> n;
    if (n % 5 == 0 && n % 11 == 0)
    {
        cout << "BOTH" << endl;
    }
    else if (n % 5 == 0 || n % 11 == 0)
    {
        cout << "ONE" << endl;
    }
    else
    {
        cout << "NONE" << endl;
    }
    return 0;
}