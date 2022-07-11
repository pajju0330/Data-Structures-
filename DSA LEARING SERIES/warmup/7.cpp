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
    ll t, g, n, i, q;
    cin >> t;
    while (t--)
    {
        cin >> g;
        while (g--)
        {
            cin >> i >> n >> q;
            if (i == q)
            {
                cout << n / 2 << "\n";
            }
            else
            {
                if (n % 2 == 0)
                {
                    cout << n / 2 << "\n";
                }
                else
                {
                    cout << (n / 2) + 1 << "\n";
                }
            }
        }
    }
    return 0;
}