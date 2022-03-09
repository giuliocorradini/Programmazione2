/* le j cifre meno significative di i */

#include <iostream>
using namespace std;

int main() {
    unsigned int i, j, z;

    cin >> i >> j;

    z = i >> (32 - j);

    cout << z;

    return 0;
}