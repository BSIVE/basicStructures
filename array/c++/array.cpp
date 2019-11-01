
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int odds[] = { 1, 3, 5, 7, 9 };

    for (int i = 0; i < sizeof(odds) / sizeof(int); i++) {
        cout << "  odds[" << i << "] = " << odds[i] << endl;
    }
}

// array.cpp
