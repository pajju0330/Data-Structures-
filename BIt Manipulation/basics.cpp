#include <bits/stdc++.h>
#define ll long long int
#define maximum(a,b,c) ((max(a,b) > c)?max(a,b) : c)
#define pajju main
using namespace std; 
int pajju()
{
    ll x;  
    cin>>x;
    // for (int i = 31 ; i >= 0; i--) //10
    // {
    //     if(x & (1<<i)) cout<<1; 
    //     else cout<<0;
    // }
    // ll y = x|(1<<2);//1000-->1100--> 12 
    // ll z = x & ~(1<<2);//1000--> 8
    // ll a = x ^ (1<<2); 
    // cout<<y<<endl;
    // cout<<z<<endl;
    // cout<<a<<endl;
    // ll y = x & (x-1); //1000
    // ll y = x & -x; //1011-->11-->1010--> 0010-->1100-->0100-->4
    // ll y = x | (x-1); //1010 -->

    cout<<__builtin_parity(x)<<endl;
    return 0;
}