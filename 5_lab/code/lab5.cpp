#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	ifstream fin("input1.txt");
	ofstream fout("output.txt");
	int t;
	fin >> t;
	while(t--){
			int n;
			fin >> n;
			int a[n][n];
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++) fin >> a[i][j];
			}
			
			
			
			for(int j = 0; j < n; j++){
				for(int i = n - 1; i >= 0; i--){
					fout << a[i][j] << " ";
					
				}
				fout << endl;
			}
			fout << endl;
		
			
	}
}

