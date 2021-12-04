#include <bits/stdc++.h>

using namespace std;

const int N = 100;
double a[N];
int n;

void f1() {
    ifstream fin("input.txt");

    cout << "Author: Dmitrii Kostuk 1309\n"
        << "Version 4.1.1\n"
        << "Start: 22.11.2021\n"
        << "End: 22.11.2021\n\n";

    if (!fin.is_open()) {
        cout << "Error while loading file...";
        return;
    }

    fin >> n;
    n = max(0, min(n, N));

    int i = 0;
    while (1) {
        if (!fin.eof() and i < n) {
            fin >> a[i++];
        }
        else break;
    }

    fin.close();
    ofstream fout("output.txt");

    n = min(n, i);

    double ans = 1;

    fout << "Current size: " << n << "\nArray: ";
    for (int i = 0; i < n; i++) fout << a[i] << " ";
    if (!n) fout << "Array is empty!";
    fout << endl;

    for (int i2 = 1; i2 < n; i2 += 2) {
        ans *= a[i2];
    }

    fout << "Answer is: ";
    if (n < 2) fout << "Nan";
    else fout << ans;
}

void f2() {
    ifstream fin("input.txt");

    cout << "Author: Dmitrii Kostuk 1309\n"
        << "Version 4.1.1\n"
        << "Start: 22.11.2021\n"
        << "End: 22.11.2021\n\n";

    if (!fin.is_open()) {
        cout << "Error while loading file...";
        return;
    }

    int c = 0;
    while (!fin.eof()) {
        double a;
        fin >> a;
        c++;
    }

    fin.close();
    ifstream fin2("input.txt");

    double* a = new double[c];

    for (int i = 0; i < c; i++) fin2 >> *(a + i);


    fin2.close();
    ofstream fout("output.txt");

    double ans = 1;

    fout << "Current size: " << c << "\nArray: ";
    for (int i = 0; i < c; i++) fout << a[i] << " ";
    if (!c) fout << "Array is empty!";
    fout << endl;

    for (int i2 = 1; i2 < c; i2 += 2) {
        ans *= a[i2];
    }

    fout << "Answer is: ";
    if (c < 2) fout << "Nan";
    else fout << ans;

    delete[] a;
}

int main() {

    f2();
    return 0;
}