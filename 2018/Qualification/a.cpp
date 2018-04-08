#include <bits/stdc++.h>

using namespace std;

int t;
long long d;
string s;

long long solve(){
	long long dano = 0;
	long long cur = 1;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'C') cur*=2LL;
		else dano += cur;
	}	
	return dano;
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for(int k = 1; k <= t; k++){
		cin >> d;
		cin >> s;
		long long dano = 0;
		int ans = 0;

		dano = solve();

		while(dano > d){
			bool ok = false;
			for(int i = int(s.size())-1; i > 0; i--){
				if(s[i] == 'S' && s[i-1] == 'C'){
					char aux = s[i];
					s[i] = s[i-1];
					s[i-1] = aux;
					ok = true;
					break;
				}
			}
			if(!ok) break;
			dano = solve();
			ans++;
		}
		if(dano <= d){
			cout << "Case #" << k << ": " << ans << "\n";
		}
		else{
			cout << "Case #" << k << ": " << "IMPOSSIBLE" << "\n";	
		}
	}

	return 0;
}