#include <iostream>
using namespace std;

int main() {
    int length;
    cout << "Length: ";
    cin >> length;

    for (int i = 0; i < length; i++) {
        cout << "*";
    }
    cout << "\n";

    return 0;
}
