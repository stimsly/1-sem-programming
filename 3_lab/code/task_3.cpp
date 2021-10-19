#include <bits/stdc++.h>

using namespace std;

int count(long long a) {
    int k = 0;
    while (a) {
        a /= 10;
        k++;
    }
    return max(1, k);
}

int main() {
    

    cout << "Author: Ignatiev Valerii Alekseevich 1309\n"
        << "Version 3.1.1\n"
        << "Start: 19.10.2021\n"
        << "End: 19.10.2021\n\n";

    const double emin = 0.000001,
        emax = 1e10;

    cout << "  n  \n";
    cout << " ---\n";
    cout << " \\   (2i + 1)!(i)!\n";
    cout << " /   ------------- \n";
    cout << " ---     (3i)!\n";
    cout << "i = 1\n\n";


    double x;
    cout << "Enter x[-1e6, 1e6][7d.12d]: ";
    cin >> x;
    cout << endl;

    double x2 = x;

    ofstream fout("output.txt");
    fout << "  n  \n";
    fout << " ---\n";
    fout << " \\   (2i + 1)!(i)!\n";
    fout << " /   ------------- \n";
    fout << " ---     (3i)!\n";
    fout << "i = 1\n\n";

    double cur = 1, sum = 0;
    cout << "-----------------------------------------------------------\n";
    cout << "|Numb| Current value              | Sum                   |\n";
    cout << "-----------------------------------------------------------\n";
    fout << "-----------------------------------------------------------\n";
    fout << "|Numb| Current value              | Sum                   |\n";
    fout << "-----------------------------------------------------------\n";
    for (int i = 1; i <= 999; i++) {
        double k = (i + 2) * (i + 3);
        k /= (2.0 * i + 2);
        k /= (2.0 * i + 3);
        cur *= k;
        cur *= x;
        sum += cur;
        x *= x2;
        int d1 = 12 - count(cur);
        int d2 = 12 - count(sum);
        int d3 = 4 - count(i);
        if (cur < 0) d1--;
        if (sum < 0) d2--;
        printf("|%4d|", i);
        fout << "|";
        while (d3--) fout << " ";
        fout << i << "|";
        while (d1--) {
            cout << " ";
            fout << " ";
        }
        fout << fixed << setprecision(15) << cur << "|";
        printf("%.15f|", cur);
        while (d2--) {
            cout << " ";
            fout << " ";
        }
        printf("%.10f|\n", sum);
        fout << fixed << setprecision(10) << sum << "|\n";
        cout << "-----------------------------------------------------------\n";
        fout << "-----------------------------------------------------------\n";

        if (fabs(cur) <= emin) {
            cout << "\nCurrent value is less then emin.\n";
            fout << "\nCurrent value is less then emin.\n";
            break;
        }
        if (fabs(cur) >= emax) {
            cout << "\nCurrent value is bigger then emin.\n";
            fout << "\nCurrent value is bigger then emin.\n";
            break;
        }
        if (fabs(sum) >= emax) {
            cout << "\nSum is bigger then emin.\n";
            fout << "\nSum is bigger then emin.\n";
            break;
        }
       

    }


    fout.close();
    return 0;
}