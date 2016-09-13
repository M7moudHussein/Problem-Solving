#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define INF ((ll) 1) << 62
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define PI 3.14159265358979323846
#define roundAns(x,d) round((x)*pow(10,(d)))/pow(10,(d))
#define EPS 1e-8
#define MAX 120
char g[MAX][MAX];
char moves[50500];
int main() {
//	freopen("in.txt", "r", stdin);
	int n, m, s;
	while (true) {
		scanf("%d %d %d", &n, &m, &s);
		if (n == 0 && m == 0 && s == 0)
			break;
		for (int i = 0; i < n; i++)
			scanf("%s", g[i]);
		pair<int, int> startNode;
		scanf("%s", moves);
		bool brk = false;
		int direction = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char temp = g[i][j];
				if (g[i][j] != '#' && g[i][j] != '.' && g[i][j] != '*') {
					startNode = mp(i, j);
					if (temp == 'N')
						direction = 0;
					else if (temp == 'L')
						direction = 1;
					else if (temp == 'S')
						direction = 2;
					else
						direction = 3;
					brk = true;
					g[i][j] = '.';
					break;
				}
			}
			if (brk)
				break;
		}
		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { -1, 0, 1, 0 };
		int ans = 0;
		for (int i = 0; i < s; i++) {
			if (moves[i] == 'D')
				direction = (direction + 1) % 4;
			else if (moves[i] == 'E')
				direction = (direction - 1 + 4) % 4;
			else {
				int ny = startNode.F + dy[direction];
				int nx = startNode.S + dx[direction];
				if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
					if (g[ny][nx] == '.') {
						startNode.F = ny, startNode.S = nx;
					} else if (g[ny][nx] == '*') {
						g[ny][nx] = '.';
						ans++;
						startNode.F = ny, startNode.S = nx;
					} else
						continue;
				} else
					continue;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
