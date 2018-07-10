#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, q;
	int cur = 0;
	long long sum = 0LL;
	long long prv = 1LL;

	vector<long long> a;
	
	scanf("%d %d", &n, &q);

	for(int i = 0; i < n; i++){
		long long x;
		scanf("%lld", &x);
		a.push_back(x);
	}
	for(int i = 0; i < q; i++){
		long long x;
		scanf("%lld", &x);
		while(sum < x){
			prv = sum;
			sum+=a[cur];
			cur++;
		}
		printf("%d %lld\n", cur, x-prv);
	}


	return 0;
}