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
#define MAX 100000000
int n, m;
bool visited[MAX];
ll solve(int s) {
	queue<pair<ll, ll>> q;
	q.push(mp(s, 0));
	visited[s] = true;
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		if (u.F == m)
			return u.S;
		if (u.F < m && !visited[u.F * 2]) {
			visited[u.F * 2] = true;
			q.push(mp(u.F * 2, u.S + 1));
		}
		if (u.F - 1 > 0 && !visited[u.F - 1]) {
			visited[u.F - 1] = true;
			q.push(mp(u.F - 1, u.S + 1));
		}
	}
	return 0;
}
int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	printf("%lld\n", solve(n));
	return 0;
}
