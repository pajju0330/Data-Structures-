#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long int
#define maximum(a,b,c) ((max(a,b) > c)?max(a,b) : c)
#define pajju main
using namespace std;


void insertionSort(int *arr , int n)
{
    int key , j;
    for (int i = 1; i <= n-1; i++)
    {
        key = arr[i];
        j = i-1;
        while (arr[j] > key && j>=0  )
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int pajju()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    insertionSort(a,n);
    printArray(a,n);   
    return 0;
}