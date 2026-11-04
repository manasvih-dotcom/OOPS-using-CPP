#include <iostream>
using namespace std;

class LIST {
public:
    virtual void store(int x) = 0;
    virtual int retrieve() = 0;
};

class stack : public LIST {
    int arr[100];
    int top;
public:
    stack() { top = -1; }
    void store(int x) {
        if (top == 99) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }
    int retrieve() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top--];
    }
};

class queue : public LIST {
    int arr[100];
    int front, rear;
public:
    queue() { front = 0; rear = -1; }
    void store(int x) {
        if (rear == 99) {
            cout << "Queue overflow" << endl;
            return;
        }
        arr[++rear] = x;
    }
    int retrieve() {
        if (front > rear) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        return arr[front++];
    }
};

int main() {
    LIST *l;
    stack s;
    queue q;

    l = &s;
    l->store(10);
    l->store(20);
    l->store(30);
    cout << "Stack: ";
    for (int i = 0; i < 3; i++)
        cout << l->retrieve() << " ";
    cout << endl;

    l = &q;
    l->store(10);
    l->store(20);
    l->store(30);
    cout << "Queue: ";
    for (int i = 0; i < 3; i++)
        cout << l->retrieve() << " ";
    cout << endl;

    return 0;
}
