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
map<int, vector<int>> mapper;
int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int n, m;
	while (scanf("%d %d", &n, &m) == 2) {
		mapper.clear();
		int temp;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &temp);
			mapper[temp].pb(i);
		}
		int k, u;
		while (m--) {
			scanf("%d %d", &k, &u);
			if (mapper.count(u) && (int) mapper[u].size() >= k) {
				printf("%d\n", mapper[u][k - 1]);
			} else {
				printf("0\n");
			}
		}
	}
	return 0;
}
