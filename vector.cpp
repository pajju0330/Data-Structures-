//_________________________________________________________//
#include <bits/stdc++.h>
#define pajju main
#define Prajwal ios_base::sync_with_stdio(false);
#define Shah cin.tie(NULL);
#define ll long long
#define vl vector<long long>
#define vi vector<int>
#define vp vector<pair<long long, long long>>
#define pb push_back
#define mp make_pair
#define mid(l, h) ((l + h) / 2)
#define f_ab(i, a, b) for (auto i = a; i < b; ++i)
#define f_rab(i, a, b) for (auto i = a; i >= b; --i)
#define mod 1'000'000'007
#define endl '\n'
#define ff first
#define ss second
#define pinf LLONG_MAX
#define ninf LLONG_MIN
//_______________________________________________________//

using namespace std;

int pajju()
{
    Prajwal Shah;
    vector<long long> v;                    // vector
    pair<long long, long long> p;           // pair
    map<long long, long long> m;            // map
    vector<pair<long long, long long>> vpr; //nested 2 STL containers
    vector<vector<int>>vvv; // nested vectors
    for (int i = 0; i < 10; i++)
    {
        vpr.push_back(make_pair(i, i + 1));
    }
    for (auto &&i : vpr)
    {
        cout << i.first << " " << i.second << '\n';
    }
    cout << "Using Maps\n";
    for (int i = 0; i < 10; i++)
    {
        m[vpr[i].first]++;
    }
    for (auto &&i : m)
    {
        cout << i.first << " " << i.second << '\n';
    }
    cout << "Using Vectors\n";
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for (auto &&i : v)
    {
        cout << i << "\n";
    }
    cout << endl;
    cout << "Finding Size\n";
    cout << "vector size: " << v.size() << "\n";
    cout << "map size: " << m.size() << "\n";
    cout << "vector pair size: " << vpr.size() << "\n";

    // reversing STL
    reverse(v.begin(), v.end());
    reverse(m.begin() , m.end());
    for (auto &&i : v) //auto automatically considers the datatype of the container
    {
        cout << i << "\n";
    }
    for (int i = 0; i < 3; i++)
    {
        vvv[i].push_back(1);
    }
    vector<long long> :: iterator i;
    


    r
    eturn 0;
}

/*
swayam 1
prajwal 2


map madhe kay asnar tula mahit nhi
string  , int, float
tr auto kay krta ki je pan ahe te swata samjhun ghete

*/