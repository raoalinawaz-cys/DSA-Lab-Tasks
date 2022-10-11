#include <iostream>
using namespace std;
struct Car
{
    int price;
    float mileage;
    int model;
};
void readdata(Car &c, int model, int mileage, int price)
{
    c.model = model;
    c.price = price;
    c.mileage = mileage;
};
void displaydata(Car &c)
{
    cout << "Model of car: " << c.model << endl;
    cout << "Mileage of car: " << c.mileage << endl;
    cout << "Price of car: " << c.price << endl;
}
int main()
{
    Car car1, car2;
    readdata(car1, 2020, 12, 200000);
    readdata(car2, 2022, 14, 9999999);
    cout << "Car 1: " << endl;
    displaydata(car1);
    cout << "Car 1: " << endl;
    displaydata(car2);
}