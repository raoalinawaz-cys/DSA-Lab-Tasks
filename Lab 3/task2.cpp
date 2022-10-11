/*
Create a class called fraction.Its two members of type int should be called num and denum.Write a program that prompts the user to enter to fractions and then computes and displays the
sum of the fractions entered by user as a fraction.
By RAO ALI NAWAZ
*/
#include <iostream>
using namespace std;
class fraction
{
public:
    int num;
    int denum;
    void read();
    friend ostream &operator<<(ostream &out, fraction f);
    friend fraction operator+(fraction f1, fraction f2);
};
void fraction::read()
{
    cout << "Enter Fraction: ";
    scanf("%d/%d", &num, &denum);
}
ostream &operator<<(ostream &out, fraction f)
{
    out << f.num << "/" << f.denum << endl;
    return out;
}
fraction operator+(fraction f1, fraction f2)
{
    fraction temp;
    int temp_denum = 0;
    if (f1.denum == f2.denum)
    {
        temp.num = f1.num + f2.num;
        temp.denum = f1.denum;
    }
    else
    {
        int b, d;
        b = f1.denum;
        d = f2.denum;
        int total = 1;
        int i = 8;
        while (b != 1 || d != 1)
        {
            if (b % 2 == 0 || d % 2 == 0)
            {
                if (b % 2 == 0)
                {
                    b = b / 2;
                }
                if (d % 2 == 0)
                {
                    d = d / 2;
                }
                total = total * 2;
            }
            else if (b % 3 == 0 || d % 3 == 0)
            {
                if (b % 3 == 0)
                {
                    b = b / 3;
                }
                if (d % 3 == 0)
                {
                    d = d / 3;
                }
                total = total * 3;
            }
            else if (b % 5 == 0 || d % 5 == 0)
            {
                if (b % 5 == 0)
                {
                    b = b / 5;
                }
                if (d % 5 == 0)
                {
                    d = d / 5;
                }
                total = total * 5;
            }
            else if (b % 7 == 0 || d % 7 == 0)
            {
                if (b % 7 == 0)
                {
                    b = b / 7;
                }
                if (d % 7 == 0)
                {
                    d = d / 7;
                }
                total = total * 7;
            }
            else if (b % i == 0 || d % i == 0)
            {
                if (b % i == 0)
                {
                    b = b / i;
                }
                if (d % i == 0)
                {
                    d = d / i;
                }
                total = total * i;
            }
            i++;
        }
        temp.denum = total;
        temp.num = f1.num * (total / f1.denum) + f2.num * (total / f2.denum);
    }
    return temp;
}
int main()
{
    fraction f1, f2;
    cout << "Enter values for fraction 1: " << endl;
    f1.read();
    cout << "Enter values for fraction 2: " << endl;
    f2.read();
    cout << endl
         << "Sum of two fractions is :";
    cout << f1 + f2 << endl;
}
