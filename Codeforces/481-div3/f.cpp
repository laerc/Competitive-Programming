#include <bits/stdc++.h>

using namespace std;

class Graph{
	int size;
	vector<vector<int> > quarrel_skill_adj;
public:
	Graph(int n){
		this->size = n;
		quarrel_skill_adj = vector<vector<int> > (this->size);
	}
	void add(int u, int u_skill, int v, int v_skill){
		quarrel_skill_adj[u].push_back(v_skill);
		quarrel_skill_adj[v].push_back(u_skill);
	}
	void sort_skills(){
		for(int i = 1; i < this->size; i++){
			if(quarrel_skill_adj[i].size() == 0) continue;
			sort(quarrel_skill_adj[i].begin(), quarrel_skill_adj[i].end());
		}
	}
	int find_how_many(int u, int u_skill){
		int total = 0;
		int pos = lower_bound(quarrel_skill_adj[u].begin(),quarrel_skill_adj[u].end(), u_skill)-quarrel_skill_adj[u].begin();
		return pos;
	}
};

int main () {

	int n, m;
	vector<int> skills;
	vector<int> sorted_skills;
	Graph *graph;
	
	scanf("%d %d", &n, &m);
	graph = new Graph(n+1);

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		skills.push_back(x);
		sorted_skills.push_back(x);
	}

	for(int i = 0; i < m; i++){
		int u,v;
		scanf("%d %d", &u, &v);
		graph->add(u,skills[u-1], v, skills[v-1]);
	}

	graph->sort_skills();
	sort(sorted_skills.begin(),sorted_skills.end());
	
	for(int i = 1; i <= n; i++){
		int x = skills[i-1];
		int total = 0;
		int pos = lower_bound(sorted_skills.begin(), sorted_skills.end(), x)-sorted_skills.begin();
		total = pos - graph->find_how_many(i,skills[i-1]);
		printf("%d\n", total);
	}

	return 0;
}