#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Size: ";
    cin >> size;

    for (int row = 0; row < size; row++) {
        for (int col = 0; col <= row; col++) {
            cout << "*";
        }
        cout << "\n";
    }

    // Variation: upside down
    cout << "\n";
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size - row; col++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
