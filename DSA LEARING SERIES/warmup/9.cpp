#include <iostream>
#include <cmath>
#include <cstring>
#define ll long long int
#define maximum(a, b, c) ((max(a, b) > c) ? max(a, b) : c)
#define pajju main
using namespace std;
int pajju()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, k, d0, d1;
    cin >> t;
    while (t--)
    {
        cin >> k >> d0 >> d1;
        ll LD = (d0 + d1) % 10;
        ll sum = d0 + d1 + LD;
        int remDigit = k - 3;
        while (remDigit > 0)
        {
            LD = (LD * 2) % 10;
            sum += LD;
            remDigit--;
        }
        if (sum % 3 == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}