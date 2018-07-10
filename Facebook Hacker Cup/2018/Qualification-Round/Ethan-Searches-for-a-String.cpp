#include <bits/stdc++.h>

using namespace std;

bool solve(string &A, string &B){
	int i = 0, j = 0;
	
	while(j < B.size()){
		if(i >= A.size())
			return true;
		if(A[i] == B[j])
			i++,j++;
		else if(i == 0)
			j++;
		else
			i = 0;
	}

	if(i >= A.size())
		return true;

	return false;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;

	for(int k = 1; k <= t; k++){
		bool break_ethan_algorithm = false;
		int str_size;
		string A, B;
		cin >> A;

		str_size = A.size();

		cout << "Case #" << k << ": ";
		for(int i = 0; i < str_size; i++){
			B = A.substr(0,i+1) + A;
			if(!solve(A,B)){
				cout << B;
				break_ethan_algorithm = true;
				break;
			}
		}
		if(!break_ethan_algorithm)
			cout << "Impossible";
		cout << "\n";
	}

	return 0;
}