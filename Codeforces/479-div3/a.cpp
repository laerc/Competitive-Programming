#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
using namespace std;

ll n, k;

int main () {

	cin >> n >> k;
	for(int i = 0; i < k; i++){
		if(n%10 != 0){
			n--;
		}
		else{
			n/=10;
		}
	}
	cout << n << endl;

	return 0;
}