#include <iostream>
using namespace std;
void binary_search(int arr[], int size, int to_find)
{
    int low = 0;
    int high = size;
    int half = (low + high) / 2;
    if (arr[half] == to_find)
    {
        cout << "The number is found at index number : " << half << endl;
    }
    else
    {
        while (low != high + 1)
        {
            half = (low + high) / 2;
            if (arr[half] == to_find)
            {
                cout << "The number is found at index number : " << half << endl;
                break;
            }
            else if (arr[half] < to_find)
            {
                low++;
            }
            else
            {
                low--;
            }
        }
    }
}
void display(int arr[], int size)
{
    int i = 0;
    while (i < size)
    {
        cout << arr[i] << "\t";
        i++;
    }
    cout << endl;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 4;
    int to_find;
    cout << "Array : ";
    display(arr, size + 1);
    cout << "\n";
    cout << "Enter the number you want to find : ";
    cin >> to_find;
    cout << endl;
    binary_search(arr, size, to_find);
}