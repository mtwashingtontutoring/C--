#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Size: ";
    cin >> size;

    for (int row = 0; row < size; row++) {
        int spaces = size - 1 - row;
        int stars = 2 * row + 1;

        for (int i = 0; i < spaces; i++) {
            cout << " ";
        }
        for (int i = 0; i < stars; i++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
