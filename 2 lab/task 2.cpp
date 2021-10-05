#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Author: Ignatiev Valerii Alekseevich 1309\n"
        << "Version 2.1.1\n"
        << "Start: 22.09.2021\n"
        << "End: 22.09.2021\n\n";

    double a, x;
    int znak = 1;
    cout << "Enter a[-20; 20][20d.6d]: ";
    cin >> a;
    cout << "\nEnter x[-20; 20][20d.6d]: ";
    cin >> x;

    cout << "Answer for x[20d.7d] = " << x << ", equals: ";
    if (!a) {
        if (!x) cout << x;
        else cout << "NaN";
        cout << "/n/n";
        return 0;
    }
    if (a < 0) {
        znak = -1;
        a *= -1;
    }
    x = fmod(x,  4 * a);
    
    if (x * a < 0) {
        x += 4 * a;
    }
    
    if (x < 2 * a) {
        cout << znak * sqrt(a * a - abs(x - a) * abs(x - a));
    }
    else if (x == 2 * a) {
        cout << "[ " << min(znak * -a, 0.0) << "; " << max(0.0, znak * -a) << " ]";
    }
    else if (x <= 3 * a) {
        cout << znak *  (-x + a) << endl;
    }
    else {
        cout << znak * ( 2 * x - 8 * a) << endl;
    }
    cout << "\n\n";
    return 0;
}
