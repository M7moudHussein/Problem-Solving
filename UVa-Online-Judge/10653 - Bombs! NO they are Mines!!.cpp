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
#define MAX 1000
bool g[MAX][MAX];
int dist[MAX][MAX];
char dx[] = { 0, 0, 1, -1 };
char dy[] = { 1, -1, 0, 0 };
int n, R, C;
int bfs(pii s, pii t) {
	memset(dist, -1, sizeof dist);
	dist[s.F][s.S] = 0;
	queue<pii> q;
	q.push(mp(s.F, s.S));
	while (!q.empty()) {
		pii u = q.front();
		if (u.F == t.F && u.S == t.S)
			break;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nF = u.F + dx[i];
			int nS = u.S + dy[i];
			if (nF < 0 || nF >= R || nS < 0 || nS >= C)
				continue;
			if (!g[nF][nS] && dist[nF][nS] == -1) {
				dist[nF][nS] = dist[u.F][u.S] + 1;
				q.push(mp(nF, nS));
			}
		}
	}
	return dist[t.F][t.S];
}
int main() {
//	freopen("in.txt", "r", stdin);
	while (true) {
		memset(g, false, sizeof g);
		int currRows;
		scanf("%d %d", &R, &C);
		if (R == 0 && C == 0)
			break;
		int rows, rowNum;
		scanf("%d", &rows);
		int temp;
		for (int i = 0; i < rows; i++) {
			scanf("%d", &rowNum);
			scanf("%d", &currRows);
			for (int j = 0; j < currRows; j++) {
				scanf("%d", &temp);
				g[rowNum][temp] = true;
			}
		}
		pii s, t;
		scanf("%d %d", &s.F, &s.S);
		scanf("%d %d", &t.F, &t.S);
		printf("%d\n", bfs(s, t));
	}
	return 0;
}
