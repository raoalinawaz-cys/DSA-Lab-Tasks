#include <iostream>
using namespace std;
struct Fruit
{
    string name;
    int price;
    int quantity;
};
void readdata(Fruit &f, string name, int price, int quantity)
{
    f.name = name;
    f.price = price;
    f.quantity = quantity;
}
int main()
{
    Fruit f1, f2, f3, f4, f5;
    readdata(f1, "banana", 50, 15);
    readdata(f2, "apple", 20, 18);
    readdata(f3, "guava", 40, 19);
    readdata(f4, "peach", 50, 12);
    readdata(f5, "grapes", 60, 11);
    int Grand_Total = 0;
    int c = 1;
    int choice;
    int quantity;
    do
    {
        cout << "1: Banana " << endl;
        cout << "2: Apple " << endl;
        cout << "3: Guava " << endl;
        cout << "4: Peach " << endl;
        cout << "5: Grapes " << endl;
        cout << "6: Exit " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter no of bananas " << endl;
            cin >> quantity;
            Grand_Total = Grand_Total + f1.price * quantity;
            break;
        }
        case 2:
        {
            cout << "Enter no of Apples " << endl;
            cin >> quantity;
            Grand_Total = Grand_Total + f2.price * quantity;
            break;
        }
        case 3:
        {
            cout << "Enter no of Guava " << endl;
            cin >> quantity;
            Grand_Total = Grand_Total + f3.price * quantity;
            break;
        }
        case 4:
        {
            cout << "Enter no of Peaches " << endl;
            cin >> quantity;
            Grand_Total = Grand_Total + f4.price * quantity;
            break;
        }
        case 5:
        {
            cout << "Enter no of Grapes " << endl;
            cin >> quantity;
            Grand_Total = Grand_Total + f5.price * quantity;
            break;
        }
        case 6:
            c = 0;
            break;
        default:
            cout << "Enter values between 1-6" << endl;
        }
    } while (c != 0);
    cout << "Grand Total is " << Grand_Total;
}
