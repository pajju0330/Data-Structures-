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

const int N = 1e5 + 2;
int a[N], tree[4 * N];

void build(int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        a[st] = val;
        tree[node] = val;
        return;
    }
    int mid = (st + en) / 2;
    if(idx<= mid) update(2*node,st,mid,idx,val);
    else (2*node,mid+1,en,idx,val);
    tree[node] = max(tree[2*node],tree[2*node+1]);
}

int query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return INT_MIN;
    if (st >= l && en <= r)
        return tree[node];
    int mid = (st + en) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);
    return max(q1, q2);
}

int pajju()
{
    Prajwal Shah;
    ll t,n;
    cin>>t;
    while(t--)
    {
    }
    return 0;
}