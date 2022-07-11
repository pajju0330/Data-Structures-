#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
using namespace std::chrono;

void subseq(int ind, vector<int> &v, ll arr[], ll n, vector<vector<ll>> &ans)
{
    if (ind == n)
    {
        if (v.size() == 0)
        {
            return;
        }
        vector<ll> temp;
        for (auto &&i : v)
        {
            temp.push_back(i);
        }
        ans.push_back(temp);
        return;
    }
    v.push_back(arr[ind]);
    subseq(ind + 1, v, arr, n, ans);
    v.pop_back();
    subseq(ind + 1, v, arr, n, ans);
}

int num(vector<ll> &ans)
{
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    ll maxi = ans[0] * 2;
    ll sum = 0;
    for (int i = 1; i < ans.size(); i++)
    {
        sum += ans[i];
    }
    ll cnt = 0;
    ll val = abs(maxi - sum);
    if (val % 7 == 0)
    {
        cnt++;
        cnt %= mod;
    }
    return cnt;
}

int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> vs;
        vector<vector<ll>> ans;
        subseq(0, vs, a, n, ans);
        // for (auto &&i : ans)
        // {
        //     for (auto &&j : i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        ll finalAns = 0;
        for (auto &&i : ans)
        {
            finalAns += num(i);
        }
        cout << finalAns << "\n";
    }
    return 0;
}