#include <iostream>
using namespace std;
void sequential_search(int arr[], int size, int to_find)
{
    int i = 0;
    while (i <= size)
    {
        if (arr[i] == to_find)
        {
            cout << "The number is present at index number : " << i << endl;
            break;
        }
        else
        {
            i++;
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
    int size = 5;
    int to_find;
    cout << "Array : ";
    display(arr, size);
    cout << "\n";
    cout << "Enter the number you want to find : ";
    cin >> to_find;
    cout << endl;
    sequential_search(arr, size, to_find);
}
