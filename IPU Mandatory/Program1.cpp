/*    PROBLEM STATEMENT:
        Implement constructor overloading in a Complex class
        and perform addition of complex numbers.*/


#include <iostream>
using namespace std;

class Complex {
    float real, img;

public:
    Complex() {
        real = 0;
        img = 0;
    }

    Complex(float r) {
        real = r;
        img = 0;
    }

    Complex(float r, float i) {
        real = r;
        img = i;
    }

    Complex add(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }

    void show() {
        cout << real << " + " << img << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);
    Complex c3;

    c3 = c1.add(c2);

    c1.show();
    c2.show();
    c3.show();

    return 0;
}
