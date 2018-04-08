#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
const int N = 1e5+10;
int n;
ll inf = 1e16;
ll v[N];
ll dp[N][3][2];

ll solve(int i, int j, int k){
	if(i >= n-1 && j != 0){
		return 0;
	}
	if(i >= n-1 && j == 0){
		return -inf;
	}
	ll &x = dp[i][j][k];
	//cout << i << endl;
	if(x == -1){
		if(j == 2){
			x = solve(i+1,j,k);
		}
		if(j == 1){
			ll a = (k == 0? 1 : -1);
			x = max(solve(i+1,1,!k)+abs(v[i]-v[i+1])*a,solve(i+1,2,k));
		}
		if(j == 0){
			x = max(solve(i+1,1,!k)+abs(v[i]-v[i+1]),solve(i+1,0,k));
		}
	}
	return x;
}

int main () {
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);
	}
	memset(dp,-1,sizeof dp);
	printf("%lld\n",solve(0,0,0));
	return 0;
}