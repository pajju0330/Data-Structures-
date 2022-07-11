#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long int
#define maximum(a, b, c) ((max(a, b) > c) ? max(a, b) : c)
#define pajju main
using namespace std;
int pajju()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        ll n = s.length();
        ll mid = s.length() / 2;
        ll count = 0;
        if (s.length() % 2 == 0)
        {
            sort(s.begin(), s.begin() + mid);
            sort(s.begin() + mid, s.end());
            for (int i = 0, j = mid; i < mid, j < n; i++, j++)
            {
                if (s[i] == s[j])
                {
                    count++;
                }
            }
            if (count == n / 2)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            sort(s.begin(), s.begin() + mid);
            sort(s.begin() + mid+1, s.end());
            for (int i = 0, j = mid + 1; i < mid, j < n; i++, j++)
            {
                if (s[i] == s[j])
                {
                    count++;
                }
            }
            if (count == n / 2)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}