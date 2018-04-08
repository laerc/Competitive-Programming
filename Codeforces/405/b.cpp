#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fastio ios_base::sync_with_stdio(0)

typedef long long ll;

const int inf = 0x3f3f3f3f;

using namespace std;
const int N = 2e5+10;
vector<int> v[N];
int n, m;
int k;
int cmp[N],hm[N];
bool ok = true;

void dfs(int u, int prv){
	cmp[u] = k;
	hm[k]++;
	for(int i = 0; i < v[u].size(); i++){
		int adj = v[u][i];
		if(!cmp[adj]){
			dfs(adj,u);
		}
	}
}

int main (){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}
	k = 1;
	for(int i = 1; i <= n; i++){
		if(!cmp[i]){
			dfs(i,i);
			k++;
		}
	}
	for(int i = 1; i <= n; i++){
		if(int(v[i].size()) != hm[cmp[i]]-1){
			printf("NO\n");
			return 0;	
		}
	}
	printf("YES\n");

	return 0;
}