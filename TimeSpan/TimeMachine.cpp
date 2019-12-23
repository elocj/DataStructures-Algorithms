//
// Created by Anthony Joo on 2019-01-18.
//

#include <iostream>
#include "TimeSpan.h"

using namespace std;

int main() {
    TimeSpan ti0;
    cout << "ti0: " << ti0 << endl;   // Testing the output operator <<
    TimeSpan ti1(3);
    cout << "ti1: " << ti1 << endl;
    TimeSpan ti2(2, 3);
    cout << "ti2: " << ti2 << endl;
    TimeSpan ti3 = ti2;    // Copy Constructor
    cout << "Testing copy constructor ti3 = ti2. ti3: " << ti3 << endl;

    // Testing !=
    if (ti1!=ti2)
    {
        cout << "Testing ti1!=ti2: objects are different." << endl;
    }
    // Testing ==
    if (ti1==ti1)
    {
        cout << "Testing ba1==ba1: objects are same" << endl;
    }

    // Testing +
    TimeSpan ti5 = ti1 + ti2;
    cout << "Testing TimeSpan ti5 = ti1 + ti2. " <<  ti5 << endl;
    // Testing -
    TimeSpan ti6 = ti2 - ti1;
    cout << "Testing TimeSpan ti5 = ti2 - ti1. " <<  ti6 << endl;
    // Testing +
    TimeSpan ti7(9, 8, 7);
    TimeSpan ti8(6, 5, 4);
    ti7 += ti8;
    cout << "Testing TimeSpan ti7 += ti8. " <<  ti7 << endl;
    TimeSpan ti9(9, 8, 7);
    TimeSpan ti10(6, 5, 4);
    ti9 -= ti10;
    cout << "Testing TimeSpan ti9 -= ti10. " <<  ti9 << endl;

    // Testing seconds
    TimeSpan ti4(1, 2, 3);
    cout << "Testing ti4.getSeconds(). Seconds: " << ti4.getSeconds() << endl;
    // Testing minutes
    cout << "Testing ti4.getMinutes(). Minutes: " << ti4.getMinutes() << endl;
    // Testing hours
    cout << "Testing ti4.getHours(). Hours: " << ti4.getHours() << endl;

    // Testing the rounding of non-integer hour values
    TimeSpan ti11(1.5, 4, -10);
    cout << "Testing non-integer hour values. " << ti11 << endl;

    // Testing the rounding of minute values that equal or surpass 60
    TimeSpan ti12(1, 70, 10);
    cout << "Testing minute values >= 60. " << ti12 << endl;

    // Testing the rounding of negative minute values
    TimeSpan ti13(1, -30, 10);
    cout << "Testing minute values < 0. " << ti13 << endl;

    // Testing the rounding of second values that equal or surpass 60
    TimeSpan ti14(1, 4, 70);
    cout << "Testing second values >= 60. " << ti14 << endl;

    // Testing the rounding of negative second values
    TimeSpan ti15(1, 4, -30);
    cout << "Testing second values < 0. " << ti15 << endl;

    // Testing >>
    cout << "Testing the input operator >>. " << endl;
    cin >> ti0;
    // Testing <<
    cout << "Testing the output operator <<. " << endl;
    cout << ti0 << endl;

    return 0;
}