#include <bits/stdc++.h>

using namespace std;

int n, l, t;
map<string,int> contain;
string ans = "";
vector<set<char> > v;

bool solve(int i){
	if(i >= l){
		if(contain[ans] == 0){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		for(auto &x : v[i]){
			ans.push_back(x);
			if(solve(i+1)){
				return true;
			}
			ans.pop_back();
		}
		return false;
	}
}


int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;

	for(int k = 1; k <= t; k++){
		cin >> n >> l;

		for(int i = 0; i < l; i++){
			v.push_back(set<char> ());
		}

		for(int i = 0; i < n; i++){
			string s, tmp = "";
			cin >> s;
			
			for(int j = 0; j < s.size(); j++){
				tmp+=s[j];
				v[j].insert(s[j]);
				contain[tmp]++;
			}

		}

		ans = "";
		if(solve(0))
			cout << "Case #"<< k << ": " << ans << endl;
		else
			cout << "Case #"<< k << ": " << "-" << endl;
		contain.clear();
		v.clear();
	}


	return 0;
}