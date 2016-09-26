#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
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
#define MAX 2500
vector<vector<int>> g;
int dist[MAX];
int countBooms[MAX];
int n;
pair<int, int> bfs(int s) {
	memset(dist, -1, sizeof dist);
	memset(countBooms, 0, sizeof countBooms);
	int maxBoom = 0, boomDay = INT_MAX;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : g[u])
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1, q.push(v);
				countBooms[dist[v]]++;
				if (maxBoom < countBooms[dist[v]]) {
					maxBoom = countBooms[dist[v]];
					boomDay = dist[v];
				}
				if (maxBoom == countBooms[dist[v]])
					boomDay = min(boomDay, dist[v]);

			}
	}
	return mp(maxBoom, boomDay);
}
int main() {
//	freopen("in.txt", "r", stdin);
	int m, v, tc;
	scanf("%d", &n);
	g.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &v);
			g[i].pb(v);
		}
	}
	int s;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &s);
		if (g[s].size() == 0)
			printf("0\n");
		else {
			pair<int, int> ans = bfs(s);
			printf("%d %d\n", ans.F, ans.S);
		}
	}
	return 0;
}
