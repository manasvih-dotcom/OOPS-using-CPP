/*PROBLEM STATEMENT: 
    Create a class Student that stores name, age, sex, height and weight.
    It has two member functions: readData() to take input from the keyboard and show() to display the object.
    Store Student objects in a binary file using write() and retrieve them using read(), then display them. */


#include <iostream>
#include <fstream>
using namespace std;

class Student {
    char name[50];
    int age;
    char sex;
    float height, weight;
public:
    void readData() {
        cout << "Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Age: ";
        cin >> age;
        cout << "Sex (M/F): ";
        cin >> sex;
        cout << "Height (cm): ";
        cin >> height;
        cout << "Weight (kg): ";
        cin >> weight;
    }

    void show() {
        cout << "Name   : " << name << endl;
        cout << "Age    : " << age << endl;
        cout << "Sex    : " << sex << endl;
        cout << "Height : " << height << " cm" << endl;
        cout << "Weight : " << weight << " kg" << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    int n;
    cout << "Number of students: ";
    cin >> n;

    Student s;
    ofstream fout("student.dat", ios::binary);
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << endl;
        s.readData();
        fout.write((char*)&s, sizeof(s));
    }
    fout.close();

    cout << "\nRetrieved Students\n\n";
    ifstream fin("student.dat", ios::binary);
    while (fin.read((char*)&s, sizeof(s)))
        s.show();
    fin.close();

    return 0;
}
