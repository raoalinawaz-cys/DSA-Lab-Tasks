#include <iostream>
#define SIZE 10

using namespace std;
void Print(int *vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << vec[i];
        if (i < n - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int Hash(int key)
{
    return key % SIZE;
}

int LinearProbe(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;
    while (H[(idx + i) % SIZE] != 0)
    {
        i++;
    }
    return (idx + i) % SIZE;
}

void Insert(int H[], int key)
{
    int idx = Hash(key);

    if (H[idx] != 0)
    {
        idx = LinearProbe(H, key);
    }
    H[idx] = key;
}

int Search(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;
    while (H[(idx + i) % SIZE] != key)
    {
        i++;
        if (H[(idx + i) % SIZE] == 0)
        {
            return -1;
        }
    }
    return (idx + i) % SIZE;
}

int main()
{

    int data[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(data) / sizeof(data[0]);
    cout << "Data "
         << ": [";
    Print(data, n);

    int hashtable[10] = {0};
    for (int i = 0; i < n; i++)
    {
        Insert(hashtable, data[i]);
    }
    cout << "Hash Table "
         << ": [";
    Print(hashtable, SIZE);

    int index = Search(hashtable, 25);
    cout << "key found at: " << index << endl;

    index = Search(hashtable, 35);
    cout << "key found at: " << index << endl;

    return 0;
}