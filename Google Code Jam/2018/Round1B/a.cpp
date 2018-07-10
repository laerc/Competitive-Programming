#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mk make_pair

typedef long long ll;
using namespace std;
const int N = 251;
int dp[N+1][N+1];
int v[N+1];
int t, n, l, sum;

int solve(int i, int j){
	if(i>=l+n-sum && j == 0){
		return 0;
	}
	if(i>=l+n-sum && j != 0){
		return -1;
	}

	if(dp[i][j] == -1){
		dp[i][j] = solve(i+1,j) + round((double(double(v[i]*1.0))/double(n*1.0))*100.0);
		for(int k = 1; k <= j; k++){
			double aux = round((double(double(v[i]*1.0+k*1.0))/double(n*1.0))*100.0);
			dp[i][j] = max(dp[i][j], solve(i+1,j-k)+int(aux));
		}
	}
	return dp[i][j];
}

int main () {

	scanf("%d", &t);
	for(int k = 1; k <= t; k++){
		sum = 0;
		scanf("%d %d", &n, &l);
		memset(v,0,sizeof v);
		for(int i = 0; i < l; i++){
			scanf("%d", v+i);
			sum+=v[i];
		}
		memset(dp,-1,sizeof dp);
		printf("Case #%d: %d\n", k,solve(0,n-sum));
	}

	return 0;
}