#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair

using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll n, p, a[N], b[N];
double ans;
double eps = 1e-9;
ll sa,sb;

bool f(long double mid){
	long double charge = mid*(p)*1.0;
	for(int i = 0; i < n; i++){
		long double x = max((long double)0.0,(long double)(a[i]*1.0*mid*1.0-b[i]*1.0));
		charge-=x;
	}
	return charge>=0.0;
}

int main () {
	scanf("%lld %lld", &n, &p);
	bool ok = true;
	ans = 1e12;
	for(int i = 0; i < n; i++){
		scanf("%lld %lld", a+i,b+i);
		sa+=a[i];
		sb+=b[i];
		if(p >= a[i]){
			continue;
		}
		else{
			ok = false;
			ans = min(ans,-double(double(b[i])/double(p-a[i])));
		}
	}
	if(ok){
		printf("-1\n");
	}
	else{
		printf("%lf\n",ans);
	}
	return 0;

	
	long double l = 0, r = 1e9;
	for(int k = 0; k < 300 && l <= r; k++){
		long double mid = (l+r)/2.0;
		if(f(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
	}

	printf("%.12Lf\n",l);

	return 0;
}