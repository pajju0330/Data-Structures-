#include <iostream>
#include <cmath>
#include <cstring>
#include <array>
#define ll long long int
#define maximum(a, b, c) ((max(a, b) > c) ? max(a, b) : c)
#define pajju main
using namespace std;
int pajju()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a[100000];
    ll count = 0;
    for (int i = 0; i < 1000000; i++)
    {
        if (a[i] == 42)
        {
            count++;
            break;
        }
        cin >> a[i];
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        cout << a[i] << "\n";
    }

    return 0;
}