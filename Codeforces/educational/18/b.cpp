#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int n, k;
vector<int> v;
vector<int> a;
vector<int> ans;

int main () {
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		v.pb(x);
	}
	for(int i = 0; i < n; i++) a.pb(i);

	for(int i = 0, cur = 0; i < k; i++){
		int sz = a.size();
		int j = v[i]%sz;
		int cnt = j;
		while(cnt--){
			cur = (cur+1)%sz;
		}
		cout << a[cur]+1 << endl;
		ans.pb(a[cur]);
		//cout << a[cur]+1 << " ";
		
		vector<int> aux;
		for(int j = 0; j < sz; j++){
			if(j != cur) aux.pb(a[j]);
		}
		cur = (cur+1)%sz;
		a.clear();a=aux;
		//cout << cur << endl;
	}

	return 0;
}