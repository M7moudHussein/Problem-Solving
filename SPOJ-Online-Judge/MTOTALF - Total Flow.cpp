#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define INF ((ll) 1) << 62
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define PI 3.14159265358979323846
#define EPS 1e-8
#define isInteger(x) ((fabs((x)-round((x)))<EPS) ? true : false)
#define roundAns(x,d) round((x)*pow(10,(d)))/pow(10,(d))
#define MAX 1000
vector<vector<int>> g;
int cap[MAX][MAX], parent[MAX], tempFlow;
bool visited[MAX];
void augment(int s, int t, int minEdge) {
	if (t == s) {
		tempFlow = minEdge;
		return;
	} else if (parent[t] != -1) {
		augment(s, parent[t], min(minEdge, cap[parent[t]][t]));
		cap[parent[t]][t] -= tempFlow, cap[t][parent[t]] += tempFlow;
	}
}
int maxFlow(int s, int t) {
	int ret = 0;
	while (true) {
		tempFlow = 0;
		memset(parent, -1, sizeof parent);
		memset(visited, false, sizeof visited);

		queue<int> q;
		q.push(s);
		visited[s] = true;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (auto i : g[u])
				if (cap[u][i] > 0 && !visited[i])
					visited[i] = true, q.push(i), parent[i] = u;
		}
		augment(s, t, INT_MAX);
		if (tempFlow == 0)
			break;
		ret += tempFlow;
	}
	return ret;
}
int main() {
	// freopen("in.txt", "r", stdin);
	int n;
	scanf("%d\n", &n);
	g.resize(1000);
	char a, b;
	int x, y, f;
	for (int i = 0; i < n; i++) {
		scanf("%c %c %d\n", &a, &b, &f);
		islower(a) ? x = a - 'a' + 1 : x = a - 'A' + 27;
		islower(b) ? y = b - 'a' + 1 : y = b - 'A' + 27;
		cap[x][y] += f, cap[y][x] += f;
		g[x].pb(y), g[y].pb(x);
	}
	int s = 27, t = 52;
	printf("%d\n", maxFlow(s, t));
	return 0;
}
