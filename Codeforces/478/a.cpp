#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

int main () {
	int n;
	string s;
	map<vector<int> ,int> mapa;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		vector<int> count;
		
		for(int j = 0; j < 140; j++)
			count.push_back(0);

		for(int j = 0; j < s.size(); j++){
			count[s[j]]=1;
		}
		mapa[count]++;
	}
	cout << mapa.size() << endl;


	return 0;
}