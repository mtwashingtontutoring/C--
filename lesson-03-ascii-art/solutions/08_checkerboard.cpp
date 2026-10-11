#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Size: ";
    cin >> size;

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if ((row + col) % 2 == 0) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
