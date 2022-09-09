#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int k = 31;
const int N = 1e5+7,m = 1e9+7;
vector<long long>powers(N);
int main()
{
    string s = "na";
    string t = "apnacolgena";
    int T = t.size(),S = s.size();
    vector<long long>h(T+1,0);
    powers[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        powers[i] =( k*powers[i-1])%m;
    }
    for(int i = 0;i<T;++i){
        h[i+1] = (h[i] + (t[i] - 'a' + 1)*powers[i])%m;
    }
    long long h_s = 0;
    for(int i = 0;i<S;++i){
        h_s = (h_s + (s[i] - 'a' + 1)*powers[i])%m;
    }
    for(int i = 0; i+S-1 < T;++i){
        long long curr_h = (h[i+S] - h[i] + m)%m;
        if(curr_h == (h_s*powers[i])%m){
            cout<<"found at index "<<i<<"\n";
        }
    }
    return 0;
}