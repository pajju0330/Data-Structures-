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
        cin >> n;
        ll a[n];
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) // 4 5 1 2 2
        {
            if (a[i] >= a[i + 1]) //4>=5--> 1 
            {
                cnt++;
                continue;
            }
            a[i + 1] = a[i]; //5 = 5 - 4 = 1
        }
        cout<<cnt<<"\n";
    }
    return 0;
}