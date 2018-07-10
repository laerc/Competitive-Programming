#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 2e5+10;
int n, m;
vector<int> v[N];
int visit[N];
int ans;
int all;

void dfs(int u, int prev){
	visit[u] = 1;
	if(v[u].size() != 2){
		all = 0;
		visit[u] = 2;
		return;
	}
	for(int i = 0; i < v[u].size(); i++){
		int adj = v[u][i];
		if(visit[adj] == 0){
			dfs(adj, u);
		}
		else if(visit[adj] == 1 && adj != prev){
			if(all == 1){
				ans++;
			}
		}
	}
	visit[u] = 2;
} 

int main () {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}
	for(int i = 1; i <= n; i++){
		if(!visit[i]){
			all = 1;
			dfs(i, i);
		}
	}
	printf("%d\n",ans);


	return 0;
}