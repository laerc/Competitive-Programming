#include <bits/stdc++.h>

using namespace std;


int t;
int r,c,h,v;
int row[101], col[101];
int resp[101];
int tmp;
vector<string> arr;
bool ok = false;

void solveH(int x, int y){
	row[x] = 1;
	col[y] = 1;
	int cnt = 0;

	for(int i = x+1; i < r; i++){
		for(int j = 0; j <= y; j++){
			if(arr[i][j] == '@'){
				cnt++;
			}
		}
		if(cnt == tmp){
			row[i] = 1;
			cnt = 0;
		}
	}
	if(cnt != 0){
		ok = false;
	}
	else{
		row[r-1] = 1;
	}
}

void solveV(int x, int y){
	int cnt = 0;

	for(int i = y+1; i < c; i++){
		for(int j = 0; j <= x; j++){
			if(arr[j][i] == '@'){
				cnt++;
			}
		}
		if(cnt == tmp){
			col[i] = 1;
			cnt = 0;
		}
	}
	if(cnt != 0){
		ok = false;
	}
	else{
		col[c-1] = 1;
	}
}

void solve(){
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < 101; i++){
		cnt1+=row[i];
	}
	
	for(int i = 0; i < 101; i++){
		cnt2+=col[i];
	}
	
	if(cnt1 != h || cnt2 != v){
		ok = false;
	}

	memset(resp,0,sizeof resp);

	for(int i = 0; i < r; i++){
		int ii = 0;
		for(int j = 0; j < c; j++){
			if(arr[i][j] == '@'){
				resp[ii]++;
			}
			if(col[j] == 1)
				ii++;
		}
		if(row[i] == 1){
			if(ii != v) ok = false;
			for(int k = 0; k < ii; k++){
				if(resp[k] != tmp){
					//ok = false;
				}
				resp[k] = 0;
			}
		}
	}

}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;

	for(int k = 1; k <= t; k++){
		cin >> r >> c >> h >> v;
		tmp = 0;
		for(int i = 0; i < r; i++){
			string s;
			cin >> s;
			arr.push_back(s);
			for(int j = 0; j < c; j++){
				if(s[j] == '@')
					tmp++;
			}
		}
		ok = true;
		cout << "Case #" << k;
		
		if(tmp % ((v+1) * (h+1)) != 0){
			//cout << "\n" << tmp << endl;
			cout << ": IMPOSSIBLE\n";
			continue;
		}

		tmp = (tmp) / ((v+1) * (h+1));

		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				memset(row,0,sizeof row);
				memset(col,0,sizeof col);
				ok = true;
				solveV(i,j);
				solveH(i,j);
				solve();
				if(ok){
					break;
				}
			}
			if(ok) break;
		}
		
		if(ok){
			cout << ": POSSIBLE\n";
		}
		else{
			cout << ": IMPOSSIBLE\n";
		}
		arr.clear();
	}

	return 0;
}