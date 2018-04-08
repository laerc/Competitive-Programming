#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fastio ios_base::sync_with_stdio(0)

typedef long long ll;

const int inf = 0x3f3f3f3f;

using namespace std;

ll a, b;

int main (){
	cin >> a >> b;
	int ans = 0;
	while(a <= b){
		a*=3;
		b*=2;
		ans++;
	}
	cout << ans << endl;

	return 0;
}