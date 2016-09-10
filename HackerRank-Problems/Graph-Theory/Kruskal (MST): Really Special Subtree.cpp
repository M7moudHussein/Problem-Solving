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
class edge {
public:
	int u = 0, v = 0;
	ll r = 0;
	edge(int u, int v, ll r) {
		this->u = u, this->v = v, this->r = r;
	}
	edge() {
	}
	bool operator<(const edge& e) {
		return this->r < e.r;
	}
};
vector<edge> edgeList;
int parent[MAX];
int findParent(int x) {
	return parent[x] == x ? x : parent[x] = findParent(parent[x]);
}
bool unionComp(int x, int y) {
	x = findParent(x), y = findParent(y);
	if (x == y)
		return false;
	parent[x] = y;
	return true;
}
ll kruskal() {
	for (int i = 0; i < MAX; i++)
		parent[i] = i;
	sort(edgeList.begin(), edgeList.end());
	ll ans = 0;
	for (auto i : edgeList) {
		if (unionComp(i.u, i.v)) {
			ans += i.r;
		}
	}
	return ans;
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	int x, y;
	ll r;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %lld", &x, &y, &r);
		edgeList.pb(edge(x, y, r));
	}
	scanf("%d", &s);
	printf("%lld\n", kruskal());
	return 0;
}
