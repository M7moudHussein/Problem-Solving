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
#define MAX 210
vector<vector<int> > g;
ll cap[MAX][MAX], currFlow;
int path[MAX];
bool visited[MAX];
void augment(int s, int x, ll minEdge) {
	if (x == s) {
		currFlow = minEdge;
		return;
	}
	minEdge = min(minEdge, cap[path[x]][x]);
	if (path[x] != -1) {
		augment(s, path[x], minEdge);
		cap[path[x]][x] -= currFlow;
		cap[x][path[x]] += currFlow;
	}
}
ll maxFlow(int s, int t) {
	ll ret = 0;
	while (true) {
		currFlow = 0;
		memset(visited, false, sizeof visited);
		memset(path, -1, sizeof path);
		queue<int> q;
		q.push(s);
		visited[s] = true;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (auto v : g[u]) {
				if (!visited[v] && cap[u][v]) {
					visited[v] = true, q.push(v), path[v] = u;
				}
			}
		}
		augment(s, t, INT_MAX);
		if (currFlow == 0)
			break;
		ret += currFlow;
	}
	return ret;
}

void reset(int n) {
	memset(cap, 0, sizeof cap);
	g.clear(), g.resize(n + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
//	freopen("in.txt", "r", stdin);
	int tc, n, m, temp;
	cin >> tc;
	while (tc--) {
		cin >> n;
		reset(n);
		for (int i = 1; i < n; i++) {
			cin >> m;
			for (int j = 0; j < m; j++) {
				cin >> temp;
				g[i].pb(temp), g[temp].pb(i);
				if (i == 1 || temp == n)
					cap[i][temp] = 1;
				else
					cap[i][temp] = INT_MAX;
			}
		}
		cout << maxFlow(1, n) << endl;
	}
	return 0;
}
