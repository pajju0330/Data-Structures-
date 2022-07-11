#include <bits/stdc++.h>
#define ll long long int
using namespace std;
using namespace std::chrono;

int frog(int index , vector<int>v , vector<int>dp)
{
    if(index == 0) return 0;
    if(dp[index] != -1) return dp[index];
    ll left = frog(index-1, v ,dp) + abs(v[index] - v[index-1]);
    ll right = INT_MAX;
    if(index>1)  right = frog(index-2, v,dp) + abs(v[index] - v[index-2]);
    return dp[index] = min(left,right);
}
int main() 
{
    auto start = high_resolution_clock::now();
    ll n ;
    ll num;
    cin>>n;
    vector<int>height;
    vector<int>dp(n+1,-1);
    vector<int>dp2(n+1,-1);
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        height.push_back(num);
    } 
    cout<< frog(n , height , dp) <<"\n";
    dp2[0] = 0;
    ll  first;
    ll second = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        first = dp2[i-1] + abs(height[i] - height[i-1]);
        if(i>1) second = dp2[i-2] + abs(height[i] - height[i-2]);
        dp2[i] = min(first,second);
    }
    cout<<dp2[n-1]<<"\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count()<< "ms"<< "\n";
    return 0;
}