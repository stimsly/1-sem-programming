#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int empty_error = -999999;
const int nmax = 100;

	
int read_one_int(int &y);

void solve(int t);
void incorrect_test_case(int t);
void print_matrix(int a[], int n, int type);
void render_array(int a[], int n, int k);
void clockewise(int a[], int n);
void skip();

int main(){
	int y = 0;
	int t = read_one_int(y);
	if(!y) skip();
	if(t == -999999){
		fout << "Empty input!\n";
		return 0;
	}
	for(int i = 1; i <= t; i++){
			solve(i);
	}
	return 0;
}

void solve(int t){
	int y = 0;
	int n = read_one_int(y);
	int k = n;
	if(!y) skip();
	if(n <= 0 or n >= nmax){
		incorrect_test_case(t);
		return;
	}
	int *a = new int[n * n];
	
	fout << "Test case: #" << t << endl;
	
	fout << "Initial: \n";
	fout << n << endl;
	for(int i = 0; i < n; i++){
		int current = 0;
		int j = 0;
		y = 0;
		while(j < n){
			current = read_one_int(y);
			if(current == empty_error) break;
			a[i * n + j++] = current;
			fout << current << " ";
		}
		fout << endl;
		if(!y) skip();
		k = min(k, j);
	}
	
	render_array(a, n, k);
	n = k;
	
	if(n <= 0){
		incorrect_test_case(t);
		return;
	}
	
	print_matrix(a, n, 1);
	
	for(int i = 0; i < 3; i++)clockewise(a, n);
	
	print_matrix(a, n, 2);
	
	fout << "Succses\n\n";
	
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
			a[j * n + n - 1 - i] = a[(n-1-i) * n + n - 1 - j];
			a[(n-1-i) * n + n - 1 - j] = a[(n-1-j) * n + i];
			a[(n-1-j) * n + i] = t; 
		}
	}
	return;
}

void render_array(int a[], int n, int k){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++) a[i*k+j] = a[i*n+j];
	}
}

int read_one_int(int &y){
	/// -999999 = end of line
	
	char c;
	int x = 0;
	int res = 0;
	while(!fin.eof()){
		c = fin.get();
		if(c == '\n'){
			y = 1;
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
	fout << "Test case number: #" << t << " is incorrect\n\n";
}

void print_matrix(int a[], int n, int type){
	if(type == 1)fout << "\nPrimary:\n";
	else fout << "\nSecondary:\n";
	fout << n << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) fout << a[i*n+j] << " ";
		fout << endl;
	}
	fout << endl;
}

void skip(){
	char c;
	while(1){
		c = fin.get();
		if(c == '\n') break;
	}
}
