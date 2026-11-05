/*PROBLEM STATEMENT: 
    Create a class SafeArray that stores integers in an array int arr[10].
    It has two member functions: set(index, value) to store a value at the given index, 
    and get(index) to return the value at the given index. 
    If the index is less than 0 or greater than or equal to 10, raise an exception.
    Handle the exception in main() and display an error message.*/

#include <iostream>
using namespace std;

class SafeArray {
    int arr[10];
public:
    SafeArray() {
        for (int i = 0; i < 10; i++)
            arr[i] = 0;
    }

    void set(int index, int value) {
        if (index < 0 || index >= 10)
            throw index;
        arr[index] = value;
    }

    int get(int index) {
        if (index < 0 || index >= 10)
            throw index;
        return arr[index];
    }
};

int main() {
    SafeArray a;

    try {
        a.set(2, 50);
        cout << "Value at index 2: " << a.get(2) << endl;

        a.set(10, 99);
        cout << "This line will not execute" << endl;
    }
    catch (int i) {
        cout << "Exception: Invalid index " << i << endl;
    }

    try {
        cout << "Value at index -1: " << a.get(-1) << endl;
    }
    catch (int i) {
        cout << "Exception: Invalid index " << i << endl;
    }

    return 0;
}
