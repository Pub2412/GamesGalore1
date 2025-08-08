#include <iostream>
#include <string>
using namespace std;

// Function to sort characters in a string
void sortCharacters(string &str) {
    int length = str.length();
    // Simple bubble sort algorithm to sort characters
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                swap(str[j], str[j + 1]);
            }
        }
    }
}

int main() {
    const int SIZE = 5; // Number of strings to input
    string arr[SIZE];

    cout << "Enter " << SIZE << " strings:\n";
    for (int i = 0; i < SIZE; i++) {
        getline(cin, arr[i]); // Input strings from the user
    }

    // Sort characters in each string
    for (int i = 0; i < SIZE; i++) {
        sortCharacters(arr[i]);
    }

    // Output the sorted strings
    cout << "\nSorted strings:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}


