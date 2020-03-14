#include "main.h"
#include <iostream>

using namespace std;

bool boolator_a() {
    cout << "A" << endl;
    return true;
}

bool boolator_c() {
    cout << "C" << endl;
    return true;
}

int main() {
	boolator_a();
	boolator_b();
	boolator_c();
}
