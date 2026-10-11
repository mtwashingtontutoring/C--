#include <iostream>
using namespace std;

int main() {
    int width;
    int height;
    cout << "Width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            bool topOrBottom = (row == 0 || row == height - 1);
            bool leftOrRight = (col == 0 || col == width - 1);

            if (topOrBottom && leftOrRight) {
                cout << "+";
            } else if (topOrBottom) {
                cout << "-";
            } else if (leftOrRight) {
                cout << "|";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
