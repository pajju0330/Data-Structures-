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
int partition(int *a, int l, int h)
{
    int pivot = a[l];
    int i = l + 1;
    int j = h;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    } while (i < j);
    swap(&a[l], &a[j]);
    return j;
}

void quickSort(int *a, int l, int h)
{
    int partition_index;
    if (l < h)
    {
        partition_index = partition(a, l, h);
        quickSort(a, l, partition_index-1);  // sort left sub array
        quickSort(a, partition_index + 1, h); // sort right sub array
    }
}

int main()
{
    int arr[100];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    printArray(arr, 5);
    quickSort(arr, 0, 4);
    printArray(arr, 5);
    return 0;
}