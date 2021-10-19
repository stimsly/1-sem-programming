#include <bits/stdc++.h>
using namespace std;

// –2.4214 x^10–52532.43x^8+624.3x^6.
// x^6–x^5+2x^4–x^3.
// Autor: Ignatiev Valerii Alekseevich 1309
// data: 22.09.2021

double k1[12] = {0,0,0,0,0,0,624.3,0,-52532.43,0,-2.4214};
double k2[8] = { 0,0,0,-1,2,-1,1};

int main()
{
    cout << "Autor: Ignatiev Valerii Alekseevich 1309\n"
        << "Version 1.1.1\n"
        << "Start: 22.09.2021\n"
        << "End: 22.09.2021\n\n";

    cout << "First polynomial: -2.4214x^10-52532.43x^8+624.3x^6\n"
        << "Second polynomial: x^6-x^5+2x^4-x^3\n\n";

    double x;
    cout << "Enter x[-5; 5][+-d.9d]: ";
    cin >> x;
    
    if (x < -5 or x > 5) {
        cout << "Oops wrong x\n";
        return 0;
    }

    cout << "\nCalculations of the first polynomial:\n";
    cout << fixed << setprecision(11);
    double pi = 0;
    for (int i = 10; i >= 0; i--) {
        pi = pi * x + k1[i];
        cout << "On step " << 10 - i + 1 << " p[+-20d.11d] equals: " << pi << "\n";
    }

    cout << "\nCalculations of the second polynomial:\n";
    cout << fixed << setprecision(11);
    double pi2 = 0;
    for (int i = 6; i >= 0; i--) {
        pi2 = pi2 * x + k2[i];
        cout << "On step " << 6 - i + 1 << " p[+-20d.11d] equals: " << pi2 << "\n";
    }

    cout << fixed << setprecision(12)
        << "\nAnswer for first polynomial[+-20d.12d]: " << pi << "\n"
        << "Answer for second polynomial[+-20d.12d]: " << pi2 << "\n"
        << "Total answer[+-20d.12d]: " << pi * pi2 << "\n\n";

    return 0;
}
