#include <bits/stdc++.h>

using namespace std;

int n;

void solveWA(){
	if(n < 6){
		printf("-1\n");
	}
	else{
		printf("1 3\n");
		printf("1 2\n");
		printf("3 5\n");
		printf("2 4\n");
		printf("6 4\n");
		for(int i = 7; i <= n; i++){
			printf("3 %d\n", i);
		}
	}
}

void solveAC(){
	for(int i = 0; i < n-1; i++){
		printf("%d %d\n",i+1, i+2);
	}
}

int main () {
	scanf("%d", &n);
	solveWA();
	solveAC();

	return 0;
}