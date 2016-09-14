#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo ((ll) 1) << 62
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define MAX 120
bool grid[MAX][MAX];
bool visited[MAX][MAX];
int degrees[MAX][MAX];
int r, c, n, m;
bool isValid(int y, int x) {
	if (y >= r || x >= c || y < 0 || x < 0)
		return false;
	return !grid[y][x];
}
void solve() {
	queue<pii> q;
	q.push(mp(0, 0));
	int dx[] = { n, n, -n, -n, m, m, -m, -m };
	int dy[] = { m, -m, m, -m, n, -n, n, -n };
	visited[0][0] = true;
	while (!q.empty()) {
		pii u = q.front();
		q.pop();
		set<pii> temp;
		for (int i = 0; i < 8; i++) {
			if (isValid(u.F + dy[i], u.S + dx[i])) {
				temp.insert(mp(u.F + dy[i], u.S + dx[i]));
			}
		}
		for (auto i : temp) {
			degrees[u.F][u.S]++;
			if (!visited[i.F][i.S]) {
				visited[i.F][i.S] = true;
				q.push(i);
			}
		}
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	int tc;
	int w;
	int x, y;
	scanf("%d", &tc);
	for (int testCase = 1; testCase <= tc; testCase++) {
		memset(grid, false, sizeof grid);
		memset(visited, false, sizeof visited);
		memset(degrees, 0, sizeof degrees);

		scanf("%d %d %d %d", &r, &c, &n, &m);
		scanf("%d", &w);
		while (w--) {
			scanf("%d %d", &y, &x);
			grid[y][x] = true;
		}
		solve();
		int odds = 0, evens = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (visited[i][j])
					degrees[i][j] & 1 ? odds++ : evens++;
		printf("Case %d: %d %d\n", testCase, evens, odds);
	}
	return 0;
}
