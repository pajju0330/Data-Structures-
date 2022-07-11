#include<iostream>
#include<cmath>
#include<cstring>
#include <stdio.h>
#define ll long long int
#define maximum(a,b,c) ((max(a,b) > c)?max(a,b) : c)
#define pajju main
using namespace std;

int humming_distance(string a, string b) //normal approach
{
    int d = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if(a[i] >= b[i]) d++;
    }
    return d;
}

int hamming(int a, int b)
{
    return __builtin_popcount(a^b);
}
int pajju()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a ,b;
    cin>>a>>b;
    cout<<hamming(stoi(a),stoi(b))<<endl;

    return 0;
}