#include <iostream>
#include <string>
using namespace std;

void replaceSubstring(string &str, const string &oldSubstr, const string &newSubstr) {
    size_t pos = 0;
    while ((pos = str.find(oldSubstr, pos)) != string::npos) {
        str.replace(pos, oldSubstr.length(), newSubstr);
        pos += newSubstr.length(); // Move past the new substring
    }
}

int main() {
    const int SIZE = 5;
    string arr[SIZE];
    string oldSubstr, newSubstr;

    cout << "Enter 5 strings:\n";
    for (int i = 0; i < SIZE; i++) {
        getline(cin, arr[i]);
    }

    cout << "Enter the substring to replace: ";
    getline(cin, oldSubstr);
    cout << "Enter the new substring: ";
    getline(cin, newSubstr);

    for (int i = 0; i < SIZE; i++) {
        replaceSubstring(arr[i], oldSubstr, newSubstr);
    }

    cout << "\nStrings after replacement:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}

