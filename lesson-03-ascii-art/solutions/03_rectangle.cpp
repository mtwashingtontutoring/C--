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
            cout << "#";
        }
        cout << "\n";
    }

    return 0;
}
