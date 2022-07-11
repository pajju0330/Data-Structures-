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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll digit;
        ll number = 0;
        while (n > 0)
        {
            digit = n % 10;
            number = (number * 10) + digit;
            n = n / 10;
        }
        cout << number << endl;
    }
    return 0;
}