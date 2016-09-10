#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo ((ll) 1) << 40
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define PI 3.14159265358979323846
#define roundAns(x,d) round((x)*pow(10,(d)))/pow(10,(d))
#define MAX 410
int n, m;
ll g[MAX][MAX];
void floydWarshall() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
void reset() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			g[i][j] = oo;
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	int x, y;
	ll r;
	reset();
	for (int i = 0; i < m; i++) {
		scanf("%d %d %lld", &x, &y, &r);
		g[x][y] = r;
	}
	for (int i = 0; i < MAX; i++)
		g[i][i] = 0;
	floydWarshall();
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &x, &y);
		printf("%lld\n", g[x][y] >= oo ? -1 : g[x][y]);
	}
	return 0;
}
