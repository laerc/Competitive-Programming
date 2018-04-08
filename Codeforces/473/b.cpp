#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+2;
int n, m, k;
string v[N];
int cost[N];
int group[N];
int mini[N];
int inf = 0x3f3f3f3f;
map<string,int> idx;
ll ans;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> m;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		idx[v[i]] = i;
	}

	for(int i = 0; i < n; i++)
		cin >> cost[i];

	memset(mini,inf,sizeof mini);

	for(int i = 0; i < k; i++){
		int sz;
		cin >> sz;
		for(int j = 0; j < sz; j++){
			int x;
			cin >> x;
			x--;
			group[x] = i;
			mini[i] = min(mini[i],cost[x]);
		}
	}
	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		int x = idx[s];
		ans += (1LL*mini[group[x]]);
	}

	cout << ans << endl;

	return 0;
}