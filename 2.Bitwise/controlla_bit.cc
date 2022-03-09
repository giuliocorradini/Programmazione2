#include <iostream>
using namespace std;

int main() {
    int x;
    int pos;

    cout << "Inserisci un numero x: ";
    cin >> x;

    cout << "In che posizione vuoi controllare? ";
    cin >> pos;

    if(x & (1<<pos))
        cout << "Settato" << endl;
    else
        cout << "Resettato" << endl;

    return 0;
}