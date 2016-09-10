#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo ((ll) 1) << 62
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define PI 3.14159265358979323846
#define roundAns(x,d) round((x)*pow(10,(d)))/pow(10,(d))
#define MAX 1010
int tc, n, m, s;
int dist[MAX];
vector<vector<int>> g;
void bfs() {
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : g[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 6;
				q.push(v);
			}
		}
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		g.clear(), g.resize(n + 1);
		memset(dist, -1, sizeof dist);
		int x, y;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			g[x].pb(y), g[y].pb(x);
		}
		scanf("%d", &s);
		bfs();
		for (int i = 1; i <= n; i++) {
			if (i == s)
				continue;
			else
				printf("%d%c", dist[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}
