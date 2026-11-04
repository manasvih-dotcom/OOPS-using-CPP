/*  PROBLEM STATEMENT: 
    Remove whitespace characters (space, horizontal tab, vertical tab, line feed, new line, carriage return) from a text file 
    and write the result to another file. */

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream fin("sample.txt");
    ofstream fout("output.txt");

    if (!fin) {
        cout << "Error!" << endl;
        return 1;
    }

    if (!fout) {
        cout << "Error!" << endl;
        return 1;
    }

    char letter;

    while (fin.get(letter)) {
        if (!isspace((unsigned char)letter)) {
            fout.put(letter);
        }
    }

    cout << "Whitespace characters removed!" << endl;
    fin.close();
    fout.close();

    return 0;
}
