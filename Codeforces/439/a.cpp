#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
const int N = 2010;
int v[N], u[N];
int n;
set<int> st;

int main () {
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		st.insert(v[i]);
	}
	for(int i = 0; i < n; i++){
		cin >> v[i];
		st.insert(v[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x = v[i]^v[j];
			if(st.count(x)) ans++;
		}
	}
	if(ans%2 == 0)
		printf("Karen\n");
	else
		printf("Koyomi\n");


	return 0;
}