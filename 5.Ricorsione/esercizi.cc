#include <iostream>
using namespace std;

void stampa_n_1(int n) {
    cout << n << endl;
    stampa_n_1(n-1);
}

void stampa_1_n(int n) {
    stampa_1_n(n-1);
    cout << n << endl;
}

int lunghezza(list l) {
    if(l == nullptr)
        return 0;

    return 1 + lunghezza(tail(l));
}



int main() {
    int n;

    cin >> n;
    stampa_n_1(n);

    cout << endl;

    stampa_1_n(n);

    return 0;
}