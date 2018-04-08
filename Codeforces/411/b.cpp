#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef long long ll;

int n;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	string ans = "b";
	for(int i = 1, j = 0, k = 0; i <n;i++){
		if(j < 2){
			ans+= "a";
			j++;
		}
		else if(j == 2 && k < 2){
			ans+="b";
			k++;
		}
		if(j == 2 && k == 2){
			j = k = 0;
		}
	}
	cout << ans << endl;

	return 0;
}