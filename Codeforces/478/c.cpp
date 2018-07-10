#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
const int N = 200010;
int n, q;
long long cur = 0LL;
int war;
vector<long long> sum;
vector<long long> a;
vector<long long> k;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.pb(x);
	}

	sum.pb(0LL);
	cur = 0LL;
	war = 0;
	for(int i = 1; i <= n; i++){
		long long val = sum[i-1] + a[i-1];
		sum.push_back(val);
	}

	for(int i = 0; i < q; i++){
		long long int x;
		cin >> x;
		cur+=x;
		int pos = lower_bound(sum.begin(), sum.end(), cur)-sum.begin();
		if(pos > n || (pos == n && sum[pos] == cur)){
			war = n;
			cur = 0LL;
		}
		else{
			if(sum[pos] > cur) pos--;
			war = n-pos;
		}
		cout << war << endl;
	}

	return 0;
}