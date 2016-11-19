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
#define MAX 105
#define INF 1000000
int g[MAX][MAX];
unordered_set<int> nodes;
double solve(int maxNode) {
	double ret = 0;
	for (int i = 1; i <= maxNode; i++) {
		for (int j = 1; j <= maxNode; j++) {
			for (int k = 1; k <= maxNode; k++) {
				g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
			}
		}
	}
	for (int i = 1; i <= maxNode; i++) {
		for (int j = 1; j <= maxNode; j++) {
			if (g[i][j] < g[0][1]) {
				ret += g[i][j];
			}
		}
	}
	return ret / (nodes.size() * (nodes.size() - 1));
}
void reset(int maxNode) {
	maxNode = 0;
	nodes.clear();
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			g[i][j] = (i == j) ? 0 : INF;
}
int main() {
//	freopen("in.txt", "r", stdin);
	int x, y, maxNode;
	int tc = 1;
	while (true) {
		reset(maxNode);
		scanf("%d %d", &x, &y);
		maxNode = max3(maxNode, x, y);
		if (x + y == 0)
			break;
		nodes.insert(x), nodes.insert(y);
		g[x][y] = 1;
		while (true) {
			scanf("%d %d", &x, &y);
			if (x + y == 0)
				break;
			maxNode = max3(maxNode, x, y);
			nodes.insert(x), nodes.insert(y);
			g[x][y] = 1;
		}
		printf("Case %d: average length between pages = %0.3lf clicks\n", tc++,
				solve(maxNode));
	}
	return 0;
}
