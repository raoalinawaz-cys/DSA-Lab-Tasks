#include <iostream>
using namespace std;
void selection_sort(int arr[], int size)
{
    int minindex;
    for (int count = 0; count < size - 1; count++)
    {
        minindex = count;
        for (int i = count + 1; i < size; i++)
        {
            if (arr[i] < arr[minindex])
            {
                int temp = arr[i];
                arr[i] = arr[minindex];
                arr[minindex] = temp;
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
    selection_sort(arr, 6);
    display(arr, 6);
}
