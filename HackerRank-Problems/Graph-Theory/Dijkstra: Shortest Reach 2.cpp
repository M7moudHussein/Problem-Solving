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
#define MAX 3010
int tc, n, m, s;
ll dist[MAX];
vector<vector<pair<int, ll>>> g;
void dijkstra() {
	for (int i = 0; i < MAX; i++)
		dist[i] = oo;
	priority_queue<pair<ll, int>> pq;
	dist[s] = 0;
	pq.push(mp(0, s));
	while (!pq.empty()) {
		pair<ll, int> u = pq.top();
		u.F = -u.F, pq.pop();
		if (u.F > dist[u.S])
			continue;
		for (auto v : g[u.S]) {
			if (dist[u.S] + v.S < dist[v.F]) {
				dist[v.F] = dist[u.S] + v.S;
				pq.push(mp(-dist[v.F], v.F));
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
		int x, y;
		ll r;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %lld", &x, &y, &r);
			g[x].pb(mp(y, r)), g[y].pb(mp(x, r));
		}
		scanf("%d", &s);
		dijkstra();
		for (int i = 1; i <= n; i++) {
			if (i == s)
				continue;
			else if (dist[i] >= oo)
				printf("-1%c", i == n ? '\n' : ' ');
			else
				printf("%lld%c", dist[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}
