#include <iostream>
using namespace std;
int quick_sort(int arr[], int p, int q)
{
    int pivot = p;
    int low = p;
    p = p + 1;
    while (p < q)
    {
        while (arr[p] <= arr[pivot])
        { // to check p
            p++;
        }
        while (arr[q] > arr[pivot])
        { // to check q
            q--;
        }
        if (p < q)
        {
            int temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
        }
    }
    if (p > q)
    {
        int temp = arr[low];
        arr[low] = arr[q];
        arr[q] = temp;
    }
    return q;
}
void initial_sort(int arr[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = quick_sort(arr, low, high);
        quick_sort(arr, low, pivot - 1);  // solves first half
        quick_sort(arr, pivot + 1, high); // solves second half
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main()
{
    int arr[8] = {35, 50, 15, 25, 80, 20, 90, 45};
    int size = 7;
    cout << "Before : ";
    display(arr, size);
    cout << endl
         << endl;
    cout << "After : ";
    initial_sort(arr, 0, size);
    display(arr, size);
}