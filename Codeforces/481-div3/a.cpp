#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	vector<int> v;
	vector<int> ans;
	set<int> st;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	reverse(v.begin(),v.end());
	for(int i = 0; i < n; i++){
		if(st.find(v[i]) == st.end()){
			ans.push_back(v[i]);
		}
		st.insert(v[i]);
	}
	reverse(ans.begin(),ans.end());
	printf("%d\n", int(ans.size()));
	for(int i = 0; i < ans.size() ; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");


	return 0;
}