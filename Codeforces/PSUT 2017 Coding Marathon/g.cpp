#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int n, m;
string s;
set<int> st;
int r, g, b;''

void solve(int i){
	if(s[i-1] == 'R'){
		r--,b++;
	}
	else if(s[i-1] == 'G'){
		g--,r++;
	}
	else if(s[i-1] == 'B'){
		b--,g++;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		st.insert(i);
	}
	for(int i = 0; i < n; i++){
		if(s[i] == 'R')r++;
		if(s[i] == 'G')g++;
		if(s[i] == 'B')b++;
	}
	//cout << r << " " << g << " " << b << endl;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		set<int>::iterator j,k;
		j = st.lower_bound(x);
		k = st.upper_bound(y);
		vector<int> aux;
		//cout << "[" << x << ", " << y << "]: "; 

		for(set<int>::iterator it = j; it != k; it++){
			aux.pb(*it);
			solve(*it);
		}
		for(int j = 0; j < aux.size(); j++){
			st.erase(aux[j]);
		}

		cout << r << " " << g << " " << b << endl;
	}

	return 0;
}