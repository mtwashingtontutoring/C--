#include <iostream>
using namespace std;

int main() {
    int height;
    cout << "Height: ";
    cin >> height;

    int center = height - 1;

    // Star on top
    for (int i = 0; i < center; i++) {
        cout << " ";
    }
    cout << "^\n";

    // Branches
    for (int row = 0; row < height; row++) {
        for (int i = 0; i < center - row; i++) {
            cout << " ";
        }
        for (int i = 0; i < 2 * row + 1; i++) {
            cout << "*";
        }
        cout << "\n";
    }

    // Trunk
    for (int row = 0; row < 2; row++) {
        for (int i = 0; i < center; i++) {
            cout << " ";
        }
        cout << "|\n";
    }

    return 0;
}
