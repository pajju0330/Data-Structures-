//_________________________________________________________//
#include <bits/stdc++.h>
#define pajju             main
#define Prajwal           ios_base::sync_with_stdio(false);
#define Shah              cin.tie(NULL);
#define ll                long long
#define vl                vector<long long>
#define vi                vector<int>
#define vp                vector<pair<long long , long long>>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define f_ab(i, a, b)     for (auto i = a; i < b; ++i)
#define f_rab(i, a, b)    for (auto i = a; i >= b; --i)
#define mod               1'000'000'007
#define endl              '\n'
#define ff                first
#define ss                second
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN
//_______________________________________________________//

using namespace std;

int matrix_paths(int i , int j)
{
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    ll up = matrix_paths(i,j-1);
    ll left = matrix_paths(i-1,j);
    return up+left;
}



int pajju()
{
    Prajwal Shah;
    ll n ,m;
    cin>>n>>m;
    cout<<matrix_paths(n-1,m-1);
    return 0;
}