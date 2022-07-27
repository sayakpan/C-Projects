#include <iostream>
using namespace std;

class circle
{
private:
    float radius;

public:
    void setRadius(int x)
    {
        radius = x;
    }
    int getRadius()
    {
        return radius;
    }
    float getArea()
    {
        return 3.14 * radius * radius;
    }
};

class number
{
private:
    int number;

public:
    void setNumber(int x)
    {
        number = x;
    }
    int getNumber()
    {
        return number;
    }
    int getFactorial()
    {
        int fact = 1, n;
        n = number;
        while (n != 1)
        {
            fact = fact * n--;
        }
        return fact;
    }
};

int main()
{
    circle c;
    float x;
    cout << "\nEnter Radius = ";
    cin >> x;
    c.setRadius(x);

    cout << "\nRadius is = " << c.getRadius();
    cout << "\nArea is = " << c.getArea();

    number n;
    int y;
    cout << "\n\nEnter a Number = ";
    cin >> y;
    n.setNumber(y);

    cout << "\nNumber is = " << n.getNumber();
    cout << "\nFactorial is = " << n.getFactorial();
}