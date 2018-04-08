#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef long long ll;

string s;
ll n;
ll mod = (1e9)+7;
ll ans;

ll solve(ll b, ll exp){
	//cout << exp << endl;
	if(exp == 0){
		return 1LL;
	}
	if(exp%2LL == 0LL){
		//cout <<exp<<endl;
		ll aux = (solve(b,exp/2LL)%mod);
		return (aux*aux)%mod;
	}
	else{
		return (2LL*solve(b,exp-1))%mod;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i = 0; i < int(s.size()); i++){
		if(s[i] == 'a') n++;
		else ans = ((ans%mod) + ((solve(2LL,n)-1LL)%mod))%mod;
	}
	cout << ans%mod << endl;

	return 0;
}