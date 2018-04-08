#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+10;
int n;
int v[N];
int ans;
int cur;

int main () {
	cin >> n;
	for(int i = 0; i < 2*n; i++){
		int x;
		cin >> x;
		if(v[x] == 0){
			v[x] = 1;
			cur++;
		}
		else{
			v[x] = 0;
			cur--;
		}
		ans = max(ans,cur);
	}
	cout << ans << endl;

	return 0;
}