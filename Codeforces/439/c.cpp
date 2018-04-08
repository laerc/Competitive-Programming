#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
const int N = 15000+10;
ll mod = 998244353LL;
ll ans = 0LL;
ll pot[N];

ll resto(ll a, ll b, ll c){
	ll resp = 0LL;

	if(a > 0 && b > 0 && c > 0){
		int mini = min(a,min(c,b));
		ll x = (3*mini - 1);
		
		if(a-mini>0)x++;
		if(b-mini>0)x++;
		if(c-mini>0)x++;
		
		resp = (((pot[x])%mod))%mod;		
	}
	else{
		int mini = min(a,min(a,b));
		
		a-=mini,b-=mini,c-=mini;

		if(a == 0){
			mini = min(b,c);
		}
		else if(b == 0){
			mini = min(a,c);
		}
		else if(c == 0){
			mini = min(b,a);
		}
		if(mini > 0)
			resp = (pot[mini]%mod);			
	}
	return resp;
}

void solve(ll a, ll b, ll c, ll k){
	if(!a || !b || !c)
		return;
	
	ans =  ((ans)%mod + (k*resto(a-1,b-1,c-1))%mod)%mod;
	solve(a-1,b-1,c-1,(k*8LL)%mod);
}

int main () {
	ios_base::sync_with_stdio(0);
	ll a, b, c;
	cin >> a >> b >> c;
	ll cur = 1LL;
	pot[0] = 1LL;

	for(ll i = 1; i < N; i++){
		cur = (cur*2LL)%mod;
		pot[i] = (cur)%mod;
		
	}
	solve(a,b,c,8LL);
	cout << resto(a,b,c) << endl;
	cout << ans << endl;
	cout << ((ans+resto(a,b,c))%mod)%mod << endl;

	return 0;
}