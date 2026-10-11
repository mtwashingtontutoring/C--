#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Size: ";
    cin >> size;

    if (size % 2 == 0) {
        cout << "Error: size must be odd.\n";
        return 1;
    }

    int half = size / 2;

    // Top half, including the middle row
    for (int row = 0; row <= half; row++) {
        for (int i = 0; i < half - row; i++) {
            cout << " ";
        }
        for (int i = 0; i < 2 * row + 1; i++) {
            cout << "*";
        }
        cout << "\n";
    }

    // Bottom half
    for (int row = half - 1; row >= 0; row--) {
        for (int i = 0; i < half - row; i++) {
            cout << " ";
        }
        for (int i = 0; i < 2 * row + 1; i++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
