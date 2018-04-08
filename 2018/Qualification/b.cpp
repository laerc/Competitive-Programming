#include <bits/stdc++.h>

using namespace std;

int t;
int n;

int main () {
	scanf("%d", &t);

	for(int ii = 1; ii <= t; ii++){
		scanf("%d", &n);
		vector<int> a, b, v;
		for(int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			if(i%2 == 0){
				a.push_back(x);
			}
			else{
				b.push_back(x);
			}
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());	
		int idx = -1;
		int i = 0, j = 0;
		for(int k = 0; k < n; k++){
			if(k%2 == 0){
				v.push_back(a[i]);
				i++;
			}
			else{
				v.push_back(b[j]);
				j++;
			}
		}
		for(int i = 0; i < n-1; i++){
			if(v[i] > v[i+1]){
				idx = i;
				break;
			}
		}
		if(idx == -1){
			printf("Case #%d: OK", ii);
		}
		else{
			printf("Case #%d: %d", ii,idx);	
		}
		printf("\n");
	}

	return 0;
}