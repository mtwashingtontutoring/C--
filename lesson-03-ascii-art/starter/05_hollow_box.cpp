// Problem 5 - Hollow box
// Read a width and height and print only the border.
//
// Width: 6
// Height: 4
// +----+
// |    |
// |    |
// +----+

#include <iostream>
using namespace std;

int main() {
    int width;
    int height;
    cout << "Width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;

    // TODO: for each (row, col), decide which character to print:
    //   corner -> '+'
    //   top or bottom edge -> '-'
    //   left or right edge -> '|'
    //   inside -> ' '

    return 0;
}
