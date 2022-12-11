#include <iostream>
using namespace std;
void bubble_sort(int arr[], int size)
{
    for (int count = 0; count < size; count++)
    {
        for (int i = 0; i < size - count; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
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
    bubble_sort(arr, 6);
    display(arr, 6);
}
