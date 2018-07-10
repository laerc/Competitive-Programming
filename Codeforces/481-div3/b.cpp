#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	int count = 0;
	int ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		char letter;
		scanf(" %c", &letter);
		if(letter == 'x'){
			count++;
		}
		else{
			count = 0;
		}
		if(count >= 3){
			ans++;
		}
	}
	printf("%d\n", ans);


	return 0;
}