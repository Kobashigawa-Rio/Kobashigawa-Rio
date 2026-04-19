#include "pch.h"
#include <iostream>

using namespace System;
using namespace std;

int main()
{
    int opt;

    do {
        system("CLS");
        cout << "Select an option: ";
        cin >> opt;

        switch (opt) {
        case 1:
            cout << "Hello World" << endl;
            opt = 0;
            break;
        case 2:
            cout << "Hello World 2.0" << endl;
            opt = 0;
            break;
        default:
            break;
        }
        
        system("pause");
    } while (true);

    system("pause>0");
    return 0;
}
