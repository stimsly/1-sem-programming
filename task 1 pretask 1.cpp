#include <bits/stdc++.h>
using namespace std;

// –2.4214 x^10–52532.43x^8+624.3x^6.
// x^6–x^5+2x^4–x^3.
// Autor: Ignatiev Valerii Alekseevich 1309
// data: 22.09.2021

int main() 
{
    cout << "Autor: Ignatiev Valerii Alekseevich 1309\n"
        << "Version 1.1.1\n"
        << "Start: 22.09.2021\n"
        << "End: 22.09.2021\n\n";

    cout << "First polynomial: -2.4214x^10-52532.43x^8+624.3x^6\n"
        << "Second polynomial: x^6-x^5+2x^4-x^3\n\n";

    double x;
    cout << "Enter x[-5; 5][d.7d]: ";
    cin >> x;

    if (x < -5. or x > 5.) {
        cout << "Oops wrong x";
        return 0;
    }

    double ans1 = ((-2.4214 * x * x - 52532.43) * x * x + 624.3) * x * x * x * x * x * x;
    double ans2 = (((x - 1) * x + 2) * x - 1) * x * x * x;

    cout << fixed << setprecision(8)
        << "\nAnswer for first polynomial[+-20d.8d]: " << ans1 << "\n"
        << "Answer for second polynomial[+-20d.8d]: " << ans2 << "\n"
        << "Total answer[+-20d.8d]: " << ans1 * ans2 << "\n\n";

    return 0;
}
