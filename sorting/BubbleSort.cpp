#include <iostream>
#define ll long long int
using namespace std;

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(int arr[], int n) //7 11 9 2 17 4 
{
    int i, j;
    int isSorted = 0;
    for (i = 0; i < n - 1; i++) // passes
    {
        isSorted = 1;
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted == 1)
        {
            return;
        }
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


int main()
{
    int n ;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    bubbleSort(a, n);
    printArray(a,n);
    return 0;
}