#include <iostream>
#include <stdexcept>
using namespace std;
class Pair
{
protected:
    int x, y;
public:
    Pair(int x_ = 0, int y_ = 0) : x(x_), y(y_){}
    void Set(int x_, int y_)
    {
        x = x_;
        y = y_;
        return;
    }
    int Prod()
    {
        return x * y;
    }
};
 
class Rectangle : protected Pair
{
public:
    Rectangle(int x_ = 1, int y_ = 1) : Pair(x_, y_)
    {
        if(x_ <= 0 || y_ <= 0) throw invalid_argument("аргументы должны быть больше нуля\n");
    }
    int Perimeter()
    {
        return 2 * ( x + y );
    }
    int Area()
    {
        return Prod();
    }
};
 
int main()
{
    Rectangle r(1, 3);
    cout << r.Perimeter();
    return 0;
}
