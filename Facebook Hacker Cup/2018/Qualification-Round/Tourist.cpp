#include <bits/stdc++.h>

using namespace std;

class Solver{
	long long n,k,v;
	vector<string> arr;
public:
	vector<int> solve(){

		vector<int> resp;
		long long cur = (k*(v-1LL))%n;
		
		for(int i = 0; i < k; i++){
			resp.push_back(cur);
			cur = (cur + 1)%n;
		}
		sort(resp.begin(), resp.end());
		return resp;
	}
	Solver(int n, int k, long long v, vector<string> &arr){
		this->n = n;
		this->k = k;
		this->v = v;
		this->arr = arr;
	}

	string get_elem(int idx){
		return arr[idx];
	}
};

int main () {
	int t;
	cin >> t;
	for(int ii = 1; ii <= t; ii++){
		int n,k;
		long long v;
		vector<string> arr;
		vector<int> resp;
		Solver *solver;

		cin >> n >> k >> v;
		for(int i = 0; i < n; i++){
			string tmp;
			cin >> tmp;
			arr.push_back(tmp);
		}
		
		solver = new Solver(n,k,v,arr);
		
		resp = solver->solve();
		cout << "Case #" << ii << ": ";
		for(int i = 0; i < resp.size(); i++){
			int idx = resp[i];
			cout << solver->get_elem(idx) << (i == resp.size()-1 ? "" : " ");
		}
		cout << endl;
	}	

	return 0;
}