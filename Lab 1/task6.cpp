#include <iostream>
using namespace std;
struct CarForSale
{
    int model[5] = {2021, 2022, 2019, 2018, 2023};
    float mileage[5] = {12, 13.1, 14.2, 15.3, 16};
    int price[5] = {20222, 324324, 34253545, 64556435, 435435325};
    int km[5] = {42134, 324532, 53425, 54354, 54353};
};
int find(int model, int mileage, int price, int km)
{
    int index = 9;
    CarForSale car;
    for (int i = 0; i < 5; i++)
    {
        if (car.model[i] == model)
        {
            index = i;
            break;
        }
        if (car.price[i] == price)
        {
            index = i;
            break;
        }
        if (car.mileage[i] == mileage)
        {
            index = i;
            break;
        }
        if (car.km[i] == km)
        {
            index = i;
            break;
        }
    }
    return index;
}
int main()
{
    int model;
    float mileage;
    int price;
    int km;
    cout << "Enter model of car: ";
    cin >> model;
    cout << "Enter mileage of car: ";
    cin >> mileage;
    cout << "Enter price of car: ";
    cin >> price;
    cout << "Enter distance covered by car in km: ";
    cin >> km;
    CarForSale car;
    int index = find(model, mileage, price, km);
    if (index < 5)
    {
        cout << "\nCar Model: " << car.model[index] << endl;
        cout << "Car Mileage: " << car.mileage[index] << endl;
        cout << "Car Price: " << car.price[index] << endl;
        cout << "Car Km: " << car.km[index] << endl;
    }
    else
    {
        cout << "\nSorry Car not found" << endl;
    }
}