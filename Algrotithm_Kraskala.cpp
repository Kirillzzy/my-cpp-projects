#include <bits/stdc++.h>	


using namespace std;

typedef long long ll;

const int N = 200000;
int parent[N];
int rang[N];

void make_set (int v) {
	parent[v] = v;
	rang[v] = 0;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rang[a] < rang[b])
			swap (a, b);
		parent[b] = a;
		if (rang[a] == rang[b])
			++rang[a];
	}
}

struct edge{
	int a, b, c;
};

bool comp(edge a, edge b){
	return a.c < b.c;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<edge>g;
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edge e;
		e.a = a;
		e.b = b;
		e.c = c;
		g.push_back(e);
		if(i <= n && i != 0){
			make_set(i);
		}
	}
	sort(g.begin(), g.end(), comp);
	int cost = 0;
	for(int i = 1; i <= n; i++){
		make_set(i);
	}

	for(int i = 0; i < g.size(); i++){
		if(find_set(g[i].a) != find_set(g[i].b)){
			union_sets(g[i].a, g[i].b);
			cost += g[i].c;
		}
	}
	cout << cost << endl;
	return 0;
}
