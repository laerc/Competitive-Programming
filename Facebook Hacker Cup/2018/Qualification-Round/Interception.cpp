#include <bits/stdc++.h>

using namespace std;

int main () {
	int t;
	cin >> t;
	for(int k = 1; k <= t; k++){
		int n;
		vector<int> coef_p;
		cin >> n;
		for(int i = 0; i <= n; i++){
			int coef;
			cin >> coef;
			coef_p.push_back(coef);
		}
		cout << "Case #" << k << ": ";
		if(n%2 == 0)
			cout << "0\n";
		else
			cout << "1\n0.0\n";
	}

	return 0;
}