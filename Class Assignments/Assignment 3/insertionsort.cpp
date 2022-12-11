#include <iostream>
using namespace std;
void insertion_sort(int *array, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i;
        while (j > 0 && array[j - 1] > key)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}
int main()
{
    int arr[6] = {4, 3, 1, 7, 8, 0};
    cout << "Before : ";
    display(arr, 6);
    cout << endl;
    cout << "After : ";
    insertion_sort(arr, 6);
    display(arr, 6);
}
