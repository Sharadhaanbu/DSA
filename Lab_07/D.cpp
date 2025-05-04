#include <iostream>
using namespace std;

string processString(const string &input) {
    char result[input.length()]; // Character array for efficient in-place modification
    int j = 0; // Write index

    for (char ch : input) {
        if (ch == '+') {
            if (j > 0) {
                j--; // "Remove" the last character logically
            }
        } else {
            result[j] = ch; // Store valid character
            j++;
        }
    }

    return string(result, j); // Construct final string from character array
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string output = processString(input);
    cout << "Processed Output: " << output << endl;

    return 0;
}
