#include <bits/stdc++.h>

using namespace std;

const int N = 100;
double a[N];
int n;

int main() {
cout << "Author: Ignatiev Valerii Alekseevich 1309\n"
        << "Version 4.1.1\n"
        << "Start: 19.10.2021\n"
        << "End: 19.10.2021\n\n";
    ifstream fin("input.txt");

    if (!fin.is_open()) {
        cout << "Cannot open file";
        return 0;
    }

    fin >> n;
    n = max(0, min(n,N));


    for (int i = 0; i < n; i++) {
        if (fin.eof()) {
            n = i;
            break;
        }
        fin >> a[i];
    }
    fin.close();

    int n2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            a[n2++] = a[i];
        }
    }

    ofstream fout("output.txt");


    fout << "Now n equals " << n2 << endl;
    fout << "Array: ";
    if (n2 == 0) fout << "NaN";


    for (int i = 0; i < n2; i++) {
        fout << a[i] << " ";
    }
    fout << "\n\n";
    fout.close();
    return 0;
}