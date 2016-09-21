#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo ((ll) 1) << 62
#define intoo INT_MAX
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define PI 3.14159265358979323846
#define EPS 1e-8
#define isInteger(x) ((fabs((x)-round((x)))<EPS) ? true : false)
#define roundAns(x,d) round((x)*pow(10,(d)))/pow(10,(d))
#define MAX 1010
int s, t;
vector<vector<int>> g;
int cap[MAX][MAX];
int parent[MAX];
bool visited[MAX];
int tempFlow;
void augment(int v, int minEdge) {
	if (v == s) {
		tempFlow = minEdge;
		return;
	}
	if (parent[v] != -1) {
		augment(parent[v], min(minEdge, cap[parent[v]][v]));
		cap[parent[v]][v] -= tempFlow;
		cap[v][parent[v]] += tempFlow;
	}
}
int maxFlow() {
	int ret = 0;
	while (true) {
		memset(parent, -1, sizeof parent);
		memset(visited, false, sizeof visited);
		tempFlow = 0;
		queue<int> q;
		q.push(s);
		visited[s] = true;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (auto v : g[u]) {
				if (!visited[v] && cap[u][v] > 0) {
					visited[v] = true;
					parent[v] = u;
					q.push(v);
				}
			}
		}
		augment(t, INT_MAX);
		if (tempFlow == 0)
			return ret;
		ret += tempFlow;
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	int tc = 1;
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		g.resize(n + 1);
		memset(cap, 0, sizeof cap);
		int c;
		scanf("%d %d %d", &s, &t, &c);
		int x, y, w;
		for (int i = 0; i < c; i++) {
			scanf("%d %d %d", &x, &y, &w);
			g[x].pb(y), g[y].pb(x);
			cap[x][y] += w;
			cap[y][x] += w;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", tc++, maxFlow());
	}
	return 0;
}
