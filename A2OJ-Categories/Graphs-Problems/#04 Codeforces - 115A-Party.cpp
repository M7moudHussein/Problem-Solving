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
#define MAX 2010
int n, temp, ans;
int dist[MAX];
bool visited[MAX];
vector<vector<int> > g;
vector<int> roots;
void dfs(int s) {
	visited[s] = true;
	for (auto i : g[s]) {
		if (!visited[i]) {
			dist[i] = dist[s] + 1;
			ans = max(ans, dist[i]);
			dfs(i);
		}
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	memset(visited, false, sizeof visited);
	memset(dist, 0, sizeof dist);
	scanf("%d", &n);
	g.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		if (temp == -1) {
			roots.push_back(i);
			continue;
		}
		g[temp].push_back(i);
	}
	for (auto i : roots)
		dfs(i);
	printf("%d\n", ans + 1);
	return 0;
}
