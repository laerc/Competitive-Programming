#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 2*int(1e5)+10;
int soma[N];
int rev[N];
string s;
int n;
int ans;
int c;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin >> s){
		memset(soma,0,sizeof soma);
		ans = 0;
		c = 0;
		n = int(s.size());
		for(int i = 0; i < n-1; i++){
			if(i>0) soma[i]=soma[i-1];
			if(s[i+1] == ')' && s[i] == ':')
				soma[i]++;
			//cout << soma[i] << " ";
			ans = max(ans,soma[i]);
		}
		if(n>1)soma[n-1]=soma[n-2];
		for(int i = 0; i < n; i++){
			if(i < n-1 && s[i] == '(' && s[i+1] == ':'){
				c++;
				int aux = 0;
				if(i!=0){
					if(s[0] == ':'){
						aux = soma[int(n-1)]-soma[int(i)];
					}
					else{
						aux = soma[int(n-1)]-soma[int(i+1)];
					}
				}

				ans = max(ans,aux+c);
			}
			else if(s[0] == ':' && s[i] == ')'){
				int aux = 0;
				if(s[0] == ':'){
					aux = soma[int(n-1)]-soma[int(i)];
				}
				else{
					aux = soma[int(n-1)]-soma[int(i+1)];
				}
				ans = max(ans,aux+c+1);	
			}
		}
		cout << ans << endl;
	}
	return 0;
}