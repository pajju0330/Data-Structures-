#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#define ll long long int
#define maximum(a, b, c) ((max(a, b) > c) ? max(a, b) : c)
#define minimum(a, b, c) ((min(a, b) < c) ? min(a, b) : c)
#define pajju main
using namespace std;
int pajju()
{
    ll a[10];
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    sort(a, a + 3);
    cout << a[1] << endl;
    return 0;
}