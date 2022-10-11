#include <iostream>
using namespace std;
int main()
{
    int arr[2][10];
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = j + 1;
            arr[i + 1][j] = (j + 1) * (j + 1);
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}