#include <bits/stdc++.h>

using namespace std;

class Solver{
	int n;
	vector<int> v;
	int add_or_sub[3] = {0, 1, -1}; 
public:
	Solver(vector<int> v){
		this->n = v.size();
		this->v = v;
	}
	int solve(){
		if(n == 1){
			return 0;
		}
		int mini = INT_MAX;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				v[0]+=add_or_sub[i];
				v[1]+=add_or_sub[j];
				int cur = v[1]-v[0];
				int prv = v[1];
				int count = (i != 0?1:0) + (j != 0?1:0);
				bool ok = true;
				
				for(int k = 1; k < n-1; k++){
					ok = false;
					for(int l = 0; l < 3; l++){
						if(v[k+1]-prv+add_or_sub[l] == cur){
							count += (l != 0?1:0);
							prv = v[k+1]+add_or_sub[l];
							ok = true;
							break;
						}
					}
					if(ok == false) break;
				}
				
				if(ok == true) mini = min(mini,count);
				
				v[0]-=add_or_sub[i];
				v[1]-=add_or_sub[j];	
			}
		}
		return mini;
	}
};

int main () {
	int n;
	vector<int> v;
	Solver *solver;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	solver = new Solver(v);
	int ans = solver->solve();
	if(ans == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n",ans);

	return 0;
}