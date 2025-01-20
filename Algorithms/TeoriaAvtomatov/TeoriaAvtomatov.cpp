#include <iostream>
#include <windows.h>
#pragma warning (disable : 4996)
using namespace std;

int main()
{
    for (int i0 = 0; i0 < 2; i0++)
        for (int i1 = 0; i1 < 2; i1++)
            for (int i2 = 0; i2 < 2; i2++)
                for (int i3 = 0; i3 < 2; i3++)
                    for (int i4 = 0; i4 < 2; i4++)
                        if (i0 == i3) {//
                            cout << "0" << i0 << i1 << i2 << i3 << i4 << "0" << endl;
                            cout << "1" << i0 << i1 << i2 << i3 << i4 << "1" << endl;
                        }
}
