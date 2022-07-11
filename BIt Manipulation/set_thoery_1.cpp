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
    ll t;
    ll n;
    cin >> n;
    int a[n];
    // printing all elements of the set , that too sorted;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // for (int i = 0; i < 32; i++)
    // {
    //     if(x&(1<<i))cout<<i<<" ";
    // }
    for (int i = 0; i < (1 << n); i++) //subset
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                cout << a[j] << " ";
        }
        cout << endl;
    }

    return 0;
}