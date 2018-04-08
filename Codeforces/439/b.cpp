#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

ll a, b;
ll ans;
ll digit = 0LL;

int main () {
	cin >> a >> b;
	if(a == b){
		cout << ("1\n");
		return 0;
	}
	a++;
	digit = (a%10LL);
	for(ll i = a+1; i <= min(a+20LL,b); i++){
		digit = ((digit) * (i%10LL))%10LL;
	}
	cout << digit << endl;

	return 0;
}