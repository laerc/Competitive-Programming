#include <bits/stdc++.h>

using namespace std;
const int N = 101, M = 6*1001;
int dp[N][M];
int v[N];
int n, t;

int solve(int i, int w){
	if(i >= n){
		return 0;
	}
	if(w >= M){
		return 0;
	}
	int &x = dp[i][w];
	if(x == -1){
		x = solve(i+1, w);
		if(v[i]*6 >= w){
			x = max(x, solve(i+1, w+v[i])+1);
		}

	}
	return x;
}

int main () {
	scanf("%d", &t);
	for(int k = 1; k <= t; k++){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", v+i);
		}
		memset(dp,-1,sizeof dp);
		printf("Case #%d: %d\n",k,solve(0,0));
	}

	return 0;
}