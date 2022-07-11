#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int get_bit(int n, int ind)
{
    return (n & (1 << ind) != 0);
}

int set_bit(int n, int ind)
{
    return (n | (1 << ind));
}

int clear_bit(int n, int ind)
{
    int mask = ~(1 << ind);
    return (n & mask);
}

int update_bit(int n, int ind, int val)
{
    int mask = ~(1 << ind);
    n = (n & mask);
    return (n | (val << ind));
}

bool is_2k(int n)
{
    return (n && !(n & n - 1));
}

int count_ones(int n)
{
    int count = 0;
    while (n)
    {
        n = n & n - 1;
        count++;
    }
    return count;
}

int subsets(int n, int arr[])
{
    for (int i = 0; i < (i << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << "\n";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << is_2k(n) << "\n";
    cout << count_ones << "\n";

    return 0;
}