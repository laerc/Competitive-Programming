#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef long long ll;

string x,y;

int main () {
	cin >> x >> y;
	for(int i = 0; i < x.size(); i++){
		if(x[i] < y[i]){
			cout << -1 << endl;
			return 0;
		}	
	}
	cout << y << endl;

	return 0;
}