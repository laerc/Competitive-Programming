#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;

using namespace std;
double eps = 1e-10;
ll n, a, b;
ll ans;
vector<ll> coord_x;
vector<ll> vel_x;
vector<ll> vel_y;
map<ll,

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b;
	for(int i = 0; i < n; i++){
		ll x, vx, vy;
		cin >> x >> vx >> vy;
		coord_x.pb(x);
		vel_x.pb(vx);
		vel_y.pb(vy);
	}
	for(int i = 0; i < n; i++){
		
	}
	cout << ans << endl;

	return 0;
}