#include <iostream>
using namespace std;

class CalcLength
{
public:
    virtual double Calc(double radius)
    {
        return 2 * 3.1415 * radius;
    }
};

class CalcArea : public CalcLength
{
public:
    double Calc(double radius) override
    {
        return 3.1415 * radius * radius;
    }
};

class CalcVolume : public CalcArea
{
public:
    double Calc(double radius) override
    {
        return 4.0 / 3 * 3.1415 * radius * radius * radius;
    }
};

void ShowResult(CalcLength* p, double radius)
{
    double res = p->Calc(radius); 
    cout << "Result = " << res << endl;
}

void main()
{
    CalcLength* p = nullptr;

    CalcLength obj1;
    CalcArea obj2;
    CalcVolume obj3;

    int num;
    cout << "Enter number of function (1-3): ";
    cin >> num;

    if ((num < 1) || (num > 3))
        return;

    double radius;
    cout << "radius = ";
    cin >> radius;


    if (num == 1) p = &obj1;
    if (num == 2) p = &obj2;
    if (num == 3) p = &obj3;

    ShowResult(p, radius);


    if (num == 1) ShowResult(&obj1, radius);
    if (num == 2) ShowResult(&obj2, radius);
    if (num == 3) ShowResult(&obj3, radius);
}