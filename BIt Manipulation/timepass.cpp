#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
#define ll long long int
#define maximum(a, b, c) ((max(a, b) > c) ? max(a, b) : c)
#define pajju main
using namespace std;

int isPrime(int num)
{
    bool flag = true;
    if (num == 1 || num == 0)
    {
        flag = false;
    }
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        return 1;
    }
    return 0;
}
int pajju()
{
    int n;
    bool ans = false;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i) == 1 && isPrime(n - i) == 1)
        {
            ans = true;
            break;
        }
    }
    if (ans)
    {
        printf("Yes we can express blah blah blah\n");
        return 0;
    }
    printf("We cant\n");
    return 0;
}