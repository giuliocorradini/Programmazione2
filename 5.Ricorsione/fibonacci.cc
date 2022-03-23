#include <iostream>
using namespace std;

int fibonacci(int n) {
    if(n == 1 || n == 0)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int userNumber;

    cout << "Inserisci un numero: ";
    cin >> userNumber;

    cout << "la sequenza di fibonacci al passo " << userNumber
         << " è " << fibonacci(userNumber) << endl;

    return 0;
}