#include <iostream>
#include <cstring>

using namespace std;

#include "tipo.h"

int compare(tipo_inf s1,tipo_inf s2) {
	return s1-s2;
}

void copy(tipo_inf& dest, tipo_inf source) {
	dest=source;
}

void print(tipo_inf inf) {
	cout<<inf;
}
