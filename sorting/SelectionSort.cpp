#include <iostream>
#define ll long long int
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void SelectionSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
            swap(&a[i], &a[min_index]);
        }
    }
}

int main()
{
    int arr[100];
    for (int i = 0; i < 5; i++)
    {
        cin>>arr[i];
    }
    printArray(arr ,5);
    SelectionSort(arr, 5);
    printArray(arr,5);
    return 0;
}