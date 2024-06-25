#include <iostream>
#include <string>

using namespace std;

string convertPath(string path) {
    string convertedPath;

    for (char c : path) {
        if (c == '\\') {
            convertedPath += "\\\\";
        } else {
            convertedPath += c;
        }
    }

    return convertedPath;
}

int main () {
    string str;
    cout << "string: "; cin >> str;

    cout << convertPath(str) << endl;
}