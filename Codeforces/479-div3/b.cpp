#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
using namespace std;

int n;
string s;
string ans;
int maxi = 0;
map<string,int> cnt;

int main () {

	cin >> n >> s;
	for(int i = 0; i < n-1; i++){
		string tmp = "";
		tmp+=s[i];
		tmp+=s[i+1];
		cnt[tmp]++;
		if(cnt[tmp] > maxi){
			maxi = cnt[tmp];
			ans = tmp;
		}
	}
	cout << ans << endl;

	return 0;
}