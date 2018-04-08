#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair

using namespace std;

const int N = 1e5+10;
typedef long long ll;

ll dp[N];
ll v[N];
ll aux[N];
int prv[N];
int idx[N];
pair<ll,int> vs[N];
int n;
ll d;

class segmentTree{

	ll st[4*N];
	public:
	segmentTree(){
		memset(st,0,sizeof st);
	}
	void update(int p, int a, int b, int i, int val){
		if(a > b || i < a || i > b){
			return;
		}
		if(a == b){
			st[p] = i;
		}
		else{
			int mid = (a+b)/2;
			update(2*p,a,mid,i,val);
			update(2*p+1,mid+1,b,i,val);
			
			if(dp[st[2*p]] > dp[st[2*p+1]])
				st[p] = st[2*p];
			else
				st[p] = st[2*p+1];

			//st[p] = max(st[2*p],st[2*p+1]);
		}
	}
	ll query(int p, int a, int b, int i, int j){
		if(a > j || b < i) return -1;
		if(a >= i && b <= j){
			return st[p];
		}
		else{
			int mid = (a+b)/2;
			ll x = query(2*p,a,mid,i,j);
			ll y = query(2*p+1,mid+1,b,i,j);
			if(dp[x] > dp[y])
				return x;
			else
				return y;
		}
	}
};

int main () {
	ios_base::sync_with_stdio(0);
	scanf("%d %lld", &n, &d);

	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);
		vs[i] = mp(v[i],i);
	}
	sort(vs,vs+n);
	for(int i = 0; i < n; i++){
		idx[vs[i].se] = i;
		aux[i] = vs[i].fi;
	}

	ll ans = 0LL;
	dp[n] = 0;
	memset(prv,-1,sizeof prv);
	
	segmentTree *st = new segmentTree();
	int beg = -1;

	for(int i = n-1; i >= 0; i--){
		int j = idx[i];
		dp[j] = dp[j+1];
		ll d1 = aux[i]-d;
		ll d2 = aux[i]+d;

		int ii = lower_bound(aux,aux+n,d1)-aux;
		int jj = upper_bound(aux,aux+n,d2)-aux;
		
		if(aux[jj] > d2) jj = max(0,jj-1);

		if(ii > n || aux[ii] < d1) ii = min(n-1,ii+1);	

		dp[j] = max(dp[j],dp[st->query(1,0,N,ii,jj)]+1);

		ans = max(ans,dp[j]);
		
		if(ans == dp[j]) beg = j;
	
		prv[j] = st->query(1,0,N,ii,jj);
		st->update(1,0,N,j,dp[j]);
	}
	printf("%lld\n",ans);
	while(beg != -1){
		printf("%d ",vs[beg].se+1);
		beg = prv[beg];
	}
	printf("\n");

	return 0;
}