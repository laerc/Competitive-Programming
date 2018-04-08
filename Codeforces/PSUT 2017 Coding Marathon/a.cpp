#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
const int inf = 0x3f3f3f3f;

int a, b, c;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c;
	int ans = min(b,c);
	b-=ans;
	c-=ans;
	ans += min(a/2,c);
	cout << ans << endl;
	return 0;
}