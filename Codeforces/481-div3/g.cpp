#include <bits/stdc++.h>
#define mt make_tuple
#define pb push_back

using namespace std;

struct Order{
	bool operator()(const tuple<int,int,int>&a, const tuple<int,int,int>&b){
		if (get<0>(a) > get<0>(b)) return true;
		else if(get<0>(a) == get<0>(b) && get<1>(a) < get<1>(b)) return true;
		else return false;
	}
};

int main () {

	const int N = 101;
	int n, m;
	int ans[N];
	
	vector<tuple<int,int,int> > v[N];
	priority_queue<tuple<int,int,int>, vector<tuple<int,int,int> >, Order>pq;
	
	memset(ans,0,sizeof ans);
	
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		int give_questions, exam_day, prep_days;
		scanf("%d %d %d", & give_questions, &exam_day, &prep_days);
		v[give_questions].push_back(make_tuple(exam_day,prep_days,i+1));
		ans[exam_day] = m+1;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < v[i].size(); j++){
			pq.push(make_tuple(get<0>(v[i][j]), get<1>(v[i][j]), get<2>(v[i][j])));
		}
		if(ans[i] == 0){
			if(pq.size() > 0){
				tuple<int,int,int> top = pq.top(); 
				if(get<0>(top) < i){
					break;
				}
				else{
					pq.pop();
					ans[i] = get<2>(top);
					if(get<1>(top)-1 > 0){
						pq.push(make_tuple(get<0>(top), get<1>(top)-1, get<2>(top)));
					}
				}
			}
		}
	}
	if(pq.size() > 0){
		printf("-1\n");
	}
	else{
		for(int i = 1; i <= n; i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
	}

	return 0;
}