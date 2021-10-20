#include <bits/stdc++.h>

using namespace std;

int main() {


    cout << "Author: Ignatiev Valerii Alekseevich 1309\n"
        << "Version 3.1.1\n"
        << "Start: 19.10.2021\n"
        << "End: 19.10.2021\n\n";

    double emin = 0.000001,
        emax = 1e200;

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
    cout << "Enter emin: ";
    cin >> emin;
    cout << endl;
    double x2 = x;

    ofstream fout("output.txt");
    fout << "  n  \n";
    fout << " ---\n";
    fout << " \\   (2i + 1)!(i)!\n";
    fout << " /   ------------- \n";
    fout << " ---     (3i)!\n";
    fout << "i = 1\n\n";

    double cur = 1, sum = 1;
    cout << "-----------------------------------------------------------------------\n";
    cout << "| Numb| Current value                | Sum                            |\n";
    cout << "-----------------------------------------------------------------------\n";
    fout << "-----------------------------------------------------------------------\n";
    fout << "| Numb| Current value                | Sum                            |\n";
    fout << "-----------------------------------------------------------------------\n";
    for (long long i = 1; i <= 999; i++) {
        if (i == 999) {
            cout << "Out of i\n";
            fout << "Out of i\n";
            break;
        }
        if (fabs(cur) <= emin) {
            cout << "\nCurrent value is less then emin.\n";
            fout << "\nCurrent value is less then emin.\n";
            break;
        }
        if (fabs(cur) >= emax) {
            cout << "\nCurrent value is bigger then emax.\n";
            fout << "\nCurrent value is bigger then emax.\n";
            break;
        }
        if (fabs(sum) >= emax) {
            cout << "\nSum is bigger then emax.\n";
            fout << "\nSum is bigger then emax.\n";
            break;
        }
        cout << "|" << left << scientific << setw(5) << i << "|"
            << setw(30) << setprecision(20) << cur << "|"
            << setw(32) << setprecision(20) << sum << "|\n";
        cout << "-----------------------------------------------------------------------\n";
        fout << "|" << left << scientific << setw(5) << i << "|"
            << setw(30) << setprecision(20) << cur << "|"
            << setw(32) << setprecision(20) << sum << "|\n";
        fout << "-----------------------------------------------------------------------\n";
        if (i % 10 == 0) {

            cout << "| Numb| Current value                | Sum                            |\n";
            cout << "-----------------------------------------------------------------------\n";
        }
        double k = (2.0 * i + 2) * (2.0 * i + 3);
        k /= (3.0 * i + 1);
        k /= (3.0 * i + 2);
        k /= 3.0;
        cur *= k;
        cur *= x;
        sum += cur;
        x *= x2;
        
       
    }


    fout.close();
    return 0;
}