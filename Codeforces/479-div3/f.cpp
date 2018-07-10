#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
int last = -1;
int maxi = 0;
int cur = 0;

unordered_map<int,int> occur;
unordered_map<int,int> sz;
unordered_map<int,int> prv;

vector<int> ans;

int main () {
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		occur[x] = i+1;

		if(sz[x] == 0) 
			sz[x] = 1;

		if(sz[x-1] > 0){
			sz[x] = sz[x-1] + 1;
			prv[x] = occur[x-1];
		}
		
		if(sz[x] > maxi){
			maxi = sz[x];
			last = x;
		}
	}
	
	int cur = occur[last];
	while(maxi > 1){
		ans.push_back(cur);
		cur = prv[last];
		last--;
		maxi--;
	}
	
	ans.push_back(occur[last]);
	reverse(ans.begin(),ans.end());
	
	printf("%d\n",int(ans.size()));
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}