#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//Binary Exponential

/*
allows to calculate a power n in O(logn)
it's easy to calculate a to power 2 raised numbers like a^2,a^4,a^8....coz they are direct square of previous
so convert any number to that form and calculate
3^13 = 3^(1101)2 = 3^8.3^4.3^1
therefore
1) if n==0 a^n = 1
2)if n%2 == 0 a^n = (a^(n/2))^2
3)if n%2 == 1 a^n = (a^(n-1/2))^2
*/

ll binpow(ll a, ll n){
    ll ans = 1;
    while(n>0){
        if(n&1) ans = ans*a;
        a = a*a;
        n>>=1;
    }
    return ans;
}

//Euclidean Algo for GCD

/*
when one number is 0 the GCD is by defination the other number.
when both are non zero,substract smaller from larger until one becomes 0;
if we observe care 'a and b' if a is larger a remains larger for atleast [a/b] times.
so to speed up a-b is changed with a - [a/b]b = a%b..
so gcd of 'a' and 'b' is gcd of 'a' and 'a%b' until one becomes 0
TC = O(logmin(a,b))
*/

ll gcd(ll a, ll b){
    return b?gcd(b,a%b):a;
}

ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}

//Extended Euclidean Algo for GCD

/*
    a.x + b.y = gcd(a,b);
    to find x y
    after some calculations (refer cp-algorithms.com)

    x = y1;
    y = x1 - y1*(a/b);

    where we assume x1,y1 to be some coeff for (b,a%b)
    i.e bx1 + (a%b).y1 = g
*/

//Fermit test (probably prime)

/*
Fermat's little theorom:
    if n is a prime number then for every a where, 1 < a < n-1;
    a^n-1 % n = 1 !!!

This is correct for every prime number
but error in returning true/false for composite exists.
*/

bool FermatPrime(int n, int iter=10) {
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (binpow(a, n - 1) != (1%n))
            return false;
    }
    return true;
}

//Millar Robin test

/*
Millar-Robin
it returns false if n is composite and true is n is probably prime.
k determines the accuracy level

bool isPrime(int n, int k)
1)handle both cases for n<3
2)if n is even return false
3)find an odd number d such that d*(2^r) = n-1 (where n is odd and r > 0)
4)do following k times
    if millerTest(n,d) ==  false return false
5)return true
*/
bool miillerTest(int d, int n)
{
    int a = 2 + rand() % (n - 4);
    int x = binpow(a, d);
 
    if (x == 1  || x == n-1)
       return true;
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)     return false;
        if (x == n-1)   return true;
    }
    return false;
}

int main()
{
   return 0;
}