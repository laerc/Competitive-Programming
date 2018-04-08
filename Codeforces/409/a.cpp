#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef long long ll;
const int N = 123;
string s;
int ans;
int cnt[N];

int main () {
	cin >> s;
	
	for(int i = 0; i < int(s.size())-1; i++){
		if(s[i] == 'V' and s[i+1] == 'K'){ cnt[i]++,cnt[i+1]++,ans++;}
	}
	for(int i = 0; i < int(s.size())-1; i++){
		if(s[i] != 'V' and s[i+1] == 'K' and !cnt[i] and !cnt[i+1]) {ans++;break;}
		if(s[i] == 'V' and s[i+1] != 'K'  and !cnt[i] and !cnt[i+1]) {ans++;break;}		
	}
	cout << ans << endl;

	return 0;
}