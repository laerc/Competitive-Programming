#include <bits/stdc++.h>

using namespace std;

bool test(vector<long long>& v, long long cur, long long w){
	for(int i = 0; i < v.size(); i++){
		cur += v[i];
		if(cur > w){
			return false;
		}
	}
	return true;
}

long long find_mini(vector<long long> v){
	long long mini = 0;
	long long cur = 0;
	for(int i = 0; i < v.size(); i++){
		cur += v[i];
		mini = min(mini,cur);
	}
	return -mini;
}

int main () {
	
	int n;
	long long w;
	bool ok = false;
	vector<long long> v;

	scanf("%d %lld", &n, &w);

	for(int i = 0; i < n; i++){
		long long x;
		scanf("%lld", &x);
		v.push_back(x);
	}

	long long left = find_mini(v);
	long long right = w+1;
	
	for(int i = 0; i < 100 && left < right; i++){
		long long mid = (left+right)/2LL;
		long long cur = mid;
		if(test(v,cur, w) == true){
			left = mid;
			ok = true;
		}
		else{
			right = mid;
		}
	}
	if(ok)
		printf("%lld\n", right-find_mini(v));
	else
		printf("%lld\n", 0LL);

	return 0;
}