#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
ll b1,q,l,m;
vector<ll> v;
ll ans;

int main () {
	scanf("%lld %lld %lld %lld", &b1, &q, &l, &m);
	for(int i = 0; i < m; i++){
		ll x;
		scanf("%lld", &x);
		v.pb(x);
	}
	sort(v.begin(),v.end());
	for(ll i = b1, k = 0; abs(i) <= l && k <= 1e5+2; i*=q, k++){
		int pos = lower_bound(v.begin(),v.end(),i)-v.begin();
		if(pos >= m || i != v[pos]){
			ans++;
		}
	}
	if((ans >= 1e3)){
		printf("inf\n");
	}
	else{
		printf("%lld\n",ans);
	}


	return 0;
}