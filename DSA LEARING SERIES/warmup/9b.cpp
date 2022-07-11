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
        if (k == 2)
        {
            if ((d0 * 10 + d1) % 3 == 0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            continue;
        }

        ll remDigit = k - 3;
        while (remDigit > 0)
        {
            if (LD == 6)
            {
                ll sets = remDigit / 4;
                sum += 20 * sets;
                remDigit -= sets * 4;
                if (remDigit = 0)
                {
                }
                else if (remDigit == 1)
                {
                    sum += 2;
                }
                else if (remDigit == 2)
                {
                    sum += 6;
                }
                else if (remDigit == 3)
                {
                    sum += 14;
                }
                remDigit = 0;
                break;
            }
            else if (LD == 0)
            {
                remDigit = 0;
                break;
            }
            else
            {
                LD = (LD * 2) % 10;
                sum += LD;
                remDigit--;
            }
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