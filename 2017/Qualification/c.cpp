#include <bits/stdc++.h>

using namespace std;

int t;
int n, k;
int maxi, mini;

int main () {
	ios_base::sync_with_stdio(0);
	scanf("%d", &t);
	
	for(int j = 1; j <= t; j++){
		scanf("%d %d", &n, &k);
		if(n%2 == 0){
			maxi = n;
			for(int i = 0, ctrl = 0,ii = 0; i < k && (maxi > 0 || mini > 0); i++,ctrl--){
				if(ctrl == 0){
					mini = max(0,(maxi-1))/2;
					maxi = (maxi/2);
					ii++;
					ctrl += (1<<ii);
				}
			}
		}
		else{
			maxi = n/2;
			mini = n/2;
			for(int i = 1; i < k && (maxi > 0 || mini > 0); i++){
				if(i%2 == 1){
					mini = mini/2;
				}
				else{
					maxi = maxi/2;
				}
			}	
		}
		printf("Case #%d: %d %d\n",j,maxi,mini);
	}


	return 0;
}