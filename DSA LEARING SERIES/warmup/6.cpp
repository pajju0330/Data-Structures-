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
    ll t, n;
    cin >> t;
    while (t--)
    {
        ll cnt = 0;
        cin >> n;
        for (int i = 5; n / i >= 1; i *= 5)
        {
            cnt += n / i;
        }
        cout << cnt << "\n";
    }
    return 0;
}