#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int empty_error = -999999;


	
int read_one_int();

void solve(int t);
void incorrect_test_case(int t);
void print_matrix(int a[], int n, int type);
void clockewise(int a[], int n);

int main(){
	
	int t = read_one_int();
	
	if(t == -999999){
		fout << "Empty input!\n";
		return 0;
	}
	cout << t << endl;
	for(int i = 1; i <= t; i++){
			solve(i);
	}
	return 0;
}

void solve(int t){
	int n = read_one_int();
	
	int *a = new int[n * n];
	
	for(int i = 0; i < n; i++){
		int current = 0;
		int j = 0;
		
		while(1){
			current = read_one_int();
			if(current == empty_error) break;
			a[i * n + j] = current;
		}
		n = min(n, j);
	}
	if(n <= 0){
		incorrect_test_case(t);
		return;
	}
	
	fout << "Test case: " << t << endl;
	
	print_matrix(a, n, 1);
	
	clockewise(a, n);
	
	print_matrix(a, n, 2);
	
	return;
	
}

// 0 0 -> 0 2
// 0 2 -> 2 2
// 2 2 -> 2 0
// 2 0 -> 0 0

void clockewise(int a[], int n){
	for(int i = 0; i < n / 2; i++){
		for(int j = i; j < n - 1 - i; j++){
			int t = a[i * n + j];
			a[i * n + j] = a[j * n + n - 1 - i];
			a[j * n + n - 1 - j] = a[(n-1-i) * n + n - 1 - j];
			a[(n-1-i) * n + n - 1 - j] = a[(n-1-j) * n + i];
			a[(n-1-j) * n + i] = t; 
		}
	}
	return;
}

int read_one_int(){
	/// -999999 = end of line
	
	char c;
	int x = 0;
	int res = 0;
	while(fin >> c){
	cout << c << " ";
		if(c == '\n'){
			res = empty_error;
			break;
		}
		if(c <= '9' and c >= '0'){
			x = 1;
			res = res * 10 + (c - '0');
		} else if(x) break;
	}
	if(!x) res = empty_error;
	return res;
}

void incorrect_test_case(int t){
	fout << "Test case number: " << t << " is incorrect\n\n";
}

void print_matrix(int a[], int n, int type){
cout << n << " " << type << endl;
	if(type == 1)fout << "\nPrimary:\n";
	else fout << "\nSecondary:\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) cout << a[i*n+j] << " ";
		cout << endl;
	}
	cout << endl;
}


