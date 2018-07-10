#include <bits/stdc++.h>
#define left(p) (p << 1)
#define right(p) (p << 1|1)
#define N 1005000
#define INF 0x3f3f3f3f
 
typedef long long ll;
using namespace std;
 
ll st[2][4*N];
int n, t, tg;
ll x;
 
void modify(int father, int l, int r, int pos, ll v){
 
    if(pos < l || pos > r)
        return;
 
    if(l == r)
        st[tg][father] = v;
 
    else{
        int mid = (l+r) >> 1;
        modify(left(father), l, mid, pos, v);
        modify(right(father), mid+1, r, pos, v);
 
        st[tg][father] = max(st[tg][left(father)], st[tg][right(father)]);
    }
}
 
ll query(int p, int i, int j, int l, int r){
    if(i > r || j < l)
        return -1LL;
 
    if(i >= l && j <= r)
        return st[tg][p];
 
    else{
        int mid = (i+j) >> 1;
 
        ll a = query(left(p), i, mid, l, r);
        ll b = query(right(p), mid+1, j, l, r);
 		if(a > 6LL*x) a = -1LL;
 		if(b > 6LL*x) b = -1LL;
        return max(a, b);
    }
}

int main (){
	scanf("%d", &t);
	for(int k = 1; k <= t; k++){
		scanf("%d", &n);
		int maxi = 0;
		for(int i = 0; i < n; i++){
			ll tmp_wei = 0, tmp_stack;
			scanf("%lld", &x);
			tmp_wei = query(1,1,N,1,i+1);
			
			
			tg = 0;
			modify(1,1,N,i+1,x);
			tg = 1;
			modify(1,1,N,i+1,1);
		}
		memset(st,0,sizeof st);
	}

	return 0;
}