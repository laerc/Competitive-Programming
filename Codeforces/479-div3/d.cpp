#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef unsigned long long ll;
using namespace std;

map<ll,int> v;
vector<ll> arr;
int n;

bool solve(int idx){
	ll cur = arr[idx];
	vector<ll> pos_ans;
	pos_ans.pb(cur);
	map<ll,int> aux = v;

	for(int i = 0; i < n-1; i++){
		if(cur%3LL == 0LL){
			if(aux[cur/3LL] >= aux[2LL*cur] && aux[cur/3LL] > 0){
				cur/=3LL;
				pos_ans.pb(cur);
				aux[cur]--;
			}
			else if(aux[cur/3LL] < aux[2LL*cur] && aux[cur*2LL] > 0){
				cur*=2LL;
				pos_ans.pb(cur);
				aux[cur]--;
			}
			else{
				return false;
			}
		}
		else{
			cur*=2LL;
			if(aux[cur] > 0){
				pos_ans.pb(cur);
				aux[cur]--;
			}
			else{
				return false;
			}
		}
	}
	for(int i = 0; i < pos_ans.size(); i++){
		printf("%lld ", pos_ans[i]);
	}
	printf("\n");
	return true;
}

int main () {

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		ll x;
		scanf("%lld", &x);
		v[x]++;
		arr.pb(x);
	}
	for(int i = 0; i < n; i++){
		if(solve(i)){
			break;
		}
	}

	return 0;
}