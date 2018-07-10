#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
long long dp[N][4][1];
long long v[N];
int t, n;

long long solve(int toy, int toys, bool k){
	if(toy >= n) return 0;
	long long &x = dp[toy][toys][k];
	if(x == -1){
		if(k == 0){
			if(toys == 3)
				x = max(x,solve(toy+1, toys-1, 1));
			else if(toys == 0)
				x = max(x,solve(toy+1, toys+1, k) + v[toy]);
			else
				x = max(x,max(solve(toy+1, toys-1, 1), solve(toy+1, toys+1, 0) + v[toy]));
		}
		else{
			if(toys == 0) x = max(x, solve(toy+1,1,0)+v[toy]);
			else x = max(x, solve(toy+1, toys-1, 1));
		}
	}
	return x;
}

int main () {
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			
			for(int j = 0; j < 4; j++)
				dp[i][j][0] = dp[i][j][1] = -1;

			scanf("%lld", &v[i]);
		}
		printf("%lld\n",solve(0,0,0));
	}

	return 0;
} 