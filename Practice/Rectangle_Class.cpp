#include <iostream>
using namespace std;

class Rect
{
    int length, breadth;

public:
    // Default constructor
    Rect()
    {
        length = 0;
        breadth = 0;
    }

    // Parameterised constructor
    Rect(int l, int b)
    {
        length = l;
        breadth = b;
    }

    void setLength(int l)
    {
        length = l;
    }

    void setBreadth(int b)
    {
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    int perimeter()
    {
        return 2 * (length + breadth);
    }

    void show()
    {
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

int main()
{
    // Two Rectangle objects using setters
    Rect r1, r2;

    r1.setLength(10);
    r1.setBreadth(5);

    r2.setLength(8);
    r2.setBreadth(4);

    cout << "Rectangle 1:" << endl;
    r1.show();

    cout << "\nRectangle 2:" << endl;
    r2.show();

    // Default constructor
    Rect r3;

    // Parameterised constructor
    Rect r4(12, 6);

    cout << "\nDefault Constructor Object:" << endl;
    r3.show();

    cout << "\nParameterised Constructor Object:" << endl;
    r4.show();

    return 0;
}
