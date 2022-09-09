//_________________________________________________________//
#include <bits/stdc++.h>
#define pajju             main
#define Prajwal           ios_base::sync_with_stdio(false);
#define Shah              cin.tie(NUint);
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
#define pinf              intONG_MAX
#define ninf              intONG_MIN
//_______________________________________________________//

using namespace std;


vector<int> nsr(stack<int>& st,vector<int>& res,vector<int>&a){
    while(!st.empty()) st.pop();
    int n = a.size();
    for(int i = n-1; i>=0 ;  i--){
        while(!st.empty() && st.top() >= a[i]) st.pop();
        if(st.empty())res.push_back(-1);
        else res.push_back(st.top());
        st.push(a[i]);
    }
    reverse(res.begin(),res.end());
    return res;
}
vector<int> ngr(stack<int>& st,vector<int>& res,vector<int>&a){
    while(!st.empty()) st.pop();
    int n = a.size();
    for(int i = n-1; i>=0 ;  i--){
        while(!st.empty() && st.top() <= a[i]) st.pop();
        if(st.empty())res.push_back(-1);
        else res.push_back(st.top());
        st.push(a[i]);
    }
    reverse(res.begin(),res.end());
    return res;
}

vector<int> nsl(stack<int>& st,vector<int>& res,vector<int>&a){
    while(!st.empty()) st.pop();
    int n = a.size();    
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && st.top () >= a[i]) st.pop();
        if(st.empty())res.push_back(-1);
        else res.push_back(st.top());
        st.push(a[i]);
    }
    return res;
}
vector<int> ngl(stack<int>& st,vector<int>& res,vector<int>&a){
    while(!st.empty()) st.pop();
    int n = a.size();    
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && st.top () <= a[i]) st.pop();
        if(st.empty())res.push_back(-1);
        else res.push_back(st.top());
        st.push(a[i]);
    }
    return res;
}

int pajju()
{
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>NGL;
    vector<int>NSL;
    vector<int>NGR;
    vector<int>NSR;
    stack<int>st;
    for(auto &i: a) cin>>i;
    //CALL YOUR DESIRED FUNCTION HERE
    return 0;
}

/*
6
1 5 6 3 2 4

-1 3 3 2 -1 -1 NSR
5 6 -1 4 4 -1 NGR
 -1 1 5 1 1 2  NSL
-1 -1 -1 6 3 6 NGL          

 */