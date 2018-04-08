#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fastio ios_base::sync_with_stdio(0)

typedef long long ll;

const int inf = 0x3f3f3f3f;

using namespace std;
int n, k;
const int N = 200;
string v[N];
string resp[N];
int nxt;

int main (){
	fastio;	
	cin >> n >> k;
	int j = 0;
	for(int i = 'A'; i <= 'Z'; i++,j++){
		v[j] = char(i);
	}
	for(int i = 'A'; i <= 'Z'; i++,j++){
		v[j] = char(i);
		v[j]+=char(i);
	}
	for(int i = 'A'; i <= 'Z'; i++,j++){
		v[j] = char(i);
		v[j]+=char(i);
		v[j]+=char(i);
	}
	for(int i = 'A'; i <= 'Z'; i++,j++){
		v[j] = char(i);
		v[j]+=char(i);
		v[j]+=char(i);
		v[j]+=char(i);
	}
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(i == 0){
			if(s == "YES"){
				for(int ii = 0; ii < k; ii++){
					resp[ii] = v[nxt];
					nxt++;
				}
			}
			else{
				for(int ii = 0; ii < k-1; ii++){
					resp[ii] = v[nxt];
					nxt++;
				}	
				resp[k-1] = v[0];
			}
		}
		else{
			if(s == "YES"){
				resp[k+i-1] = v[nxt];
				nxt++;
			}
			else{
				resp[k+i-1] = resp[i];
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << resp[i] << " ";
	}
	cout << endl;

	return 0;
}