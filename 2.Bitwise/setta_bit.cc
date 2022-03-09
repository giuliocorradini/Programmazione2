#include <iostream>
using namespace std;

int main() {
    unsigned int x, n;
    
    cin >> x >> n;

    x |= (1 << n);

    cout << x;

    return 0;
}