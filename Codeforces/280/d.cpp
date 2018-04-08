#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair

using namespace std;

const int N = 1e6+10;

int n;
int x,y;
int sum[N];
int v[N];
map<pair<int,int>,int> cnt;
map<pair<int,int>,int> idx;

int main () {
	ios_base::sync_with_stdio(0);
	cin >> n >> x >> y;
	for(int i = 1; i < x; i++){
		int gcd = __gcd(i,x);
		cnt[mp(i/gcd,-x/gcd)]++;
		idx[mp(i/gcd,-x/gcd)] = 1;
	}

	for(int i = 1; i < y; i++){
		int gcd = __gcd(i,y);
		cnt[mp(i/gcd,-y/gcd)]++;
		idx[mp(i/gcd,-y/gcd)] = 2;
	}
	int j = 1;
	for(map<pair<int,int>,int>:: iterator i = cnt.begin(); i != cnt.end(); i++,j++){
		int ii = i->se;
		if(ii == 2){
			v[j] = 3;
		}
		else{
			v[j] = idx[i->fi];
		}
		sum[j] = sum[j-1]+ii;
	}
	cout << j << endl;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a%(sum[j-1]+1) == 0 || a%(sum[j-1]+2) == 0){
			printf("Both\n");
			continue;
		}
		int pos = lower_bound(sum,sum+j,a%(sum[j-1]+1))-sum;
		if(v[pos] == 1){
			printf("Vanya\n");
		}
		else if(v[pos] == 2){
			printf("Vova\n");
		}
		else{
			printf("Both\n");
		}
	}
	return 0;
}
