#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int a[N];
int n;

void f() {
    ifstream fin("input.txt");

    cout << "Author: Ignatiev Valerii Alekseevich 1309\n"
        << "Version 4.1.1\n"
        << "Start: 26.10.2021\n"
        << "End: 26.10.2021\n\n";

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
    ofstream fout2("output2.txt");
    n = min(n, i);
    i = 0;

    for (int i2 = 0; i2 < n; i2++) {
        if (a[i2]) {
            a[i++] = a[i2];
        }
    }

    n = min(n, i);
    i = 0;

    cout << "Current size: " << n << "\nArray: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    if (!n) cout << "NaN";


    fout << "Current size: " << n << "\nArray: ";
    for (int i = 0; i < n; i++) fout << a[i] << " ";
    if (!n) fout << "NaN";
    fout.close();
}

void s() {
    cout << "Author: Ignatiev Valerii Alekseevich 1309\n"
        << "Version 4.1.1\n"
        << "Start: 26.10.2021\n"
        << "End: 26.10.2021\n\n";

    int* a;
    ifstream fin("input.txt");
    int c = 0;
    while (!fin.eof()) {
        int a;
        fin >> a;
        c++;
    }
    
    fin.close();
    ifstream fin2("input.txt");

    a = (int*)malloc(c * (sizeof(int)));

    for (int i = 0; i < c; i++) fin2 >> *(a + i);
    int n = 0;
    fin2.close();
    for (int i = 0; i < c; i++) {
        if (*(a + i)) {
            *(a + n++) = *(a + i);

        }
    }

    cout << "Current size: " << n << "\nArray: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    if (!n) cout << "NaN";

    ofstream fout("output.txt");
    fout << "Current size: " << n << "\nArray: ";
    for (int i = 0; i < n; i++) fout << a[i] << " ";
    if (!n) fout << "NaN";
    fout.close();

    free(a);
}

int main() {
    
    s();
    return 0;
}
