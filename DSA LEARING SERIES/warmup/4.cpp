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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a[n];
    ll maximum_budget = 0;
    ll budget;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n); //40 , 3, 65 , 33, 21 ==> 3, 21, 33, 60 , 65 ==>  
    for (int i = 0; i < n; i++)
    {
        budget = a[i]*(n-i);
        maximum_budget = max(budget , maximum_budget);
    }
    cout << maximum_budget << endl;
    return 0;
}