#include <bits/stdc++.h>
#define ll long long int
using namespace std;
using namespace std::chrono;

int maxiSum(ll ind, vector<int> &v, vector<int> &dp) // no adjucent subseq sum;
{
    if (ind == 0)
        return v[0];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    ll pick = v[ind] + maxiSum(ind - 2, v, dp);
    ll notPick = 0 + maxiSum(ind - 1, v, dp);
    return dp[ind] = max(pick, notPick);
}

int main()
{
    auto start = high_resolution_clock::now();
    ll n;
    ll num;
    cin >> n;
    vector<int> v;
    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    cout << maxiSum(n - 1, v, dp) << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << "ms"
         << "\n";
    return 0;
}