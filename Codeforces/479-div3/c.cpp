#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
using namespace std;
vector<int> v;
int n, k;

int main () {

	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		v.pb(x);
	}
	sort(v.begin(),v.end());
	if(k == n){
		printf("%d\n", v[n-1]);
	}
	else if(k == 0){
		if(v[0] != 1){
			printf("%d\n", v[0]-1);
		}
		else{
			printf("%d\n", -1);	
		}
	}
	else{
		if(v[k-1] == v[k]){
			printf("-1\n");
		}
		else{
			printf("%d\n", v[k-1]);
		}
	}


	return 0;
}