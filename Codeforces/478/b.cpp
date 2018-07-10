#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

vector<long long> v;

long long solve(int i){
	long long tot = (v[i]/14);
	long long rem = (v[i]%14);
	long long ans = 0;
	vector<long long> aux = v;
	aux[i] = 0;
	cout << tot << " " << rem << endl;
	for(int j = 0; j < 14; j++){
		int idx = (j+i+1)%14;
		aux[idx] += tot;
	}
	for(int j = 0; j < 14 && rem > 0; j++, rem--){
		int idx = (j+i+1)%14;
		aux[idx] += 1;
	}
	for(int j = 0; j < 14; j++){
		if(aux[j] % 2 == 0){
			ans += aux[j];
		}
		cout << aux[j] << " ";
	}
	cout << endl;
	return ans;
}

int main () {

	long long ans = 0;
	for(int i = 0; i < 14; i++){
		long long x;
		cin >> x;
		v.push_back(x);
	}
	for(int i = 0; i < 14; i++){
		if(v[i] > 0){
			ans = max(ans,solve(i));
		}
	}
	cout<< ans << endl;

	return 0;
}