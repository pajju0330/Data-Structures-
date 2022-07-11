#include <bits/stdc++.h>
#define ll long long int
using namespace std;
using namespace std::chrono;

int fibonacci(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}

int main()
{
    auto start = high_resolution_clock::now();
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibonacci(n, dp) << endl; // recursive
    // tabular approcch
    int prev = 1;
    int prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << prev << endl;
    cout << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count()<< "ms"<< "\n";
    return 0;
}