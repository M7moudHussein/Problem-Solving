#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo ((ll) 1) << 62
#define max3(a,b,c) max((a),max((b),(c)))
#define MAX 100010
int n, m, temp;
vector<int> coins;
ll dp[255][55];
ll solve(int rem, int i) {
	if (rem == 0)
		return 1;
	if (i == m)
		return 0;
	if (dp[rem][i] != -1)
		return dp[rem][i];
	ll ret = 0;
	for (int j = 0; j <= (rem / coins[i]); j++) {
		ret += solve(rem - j * coins[i], i + 1);
	}
	return dp[rem][i] = ret;
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		coins.pb(temp);
	}
	sort(coins.begin(), coins.end(), greater<int>());
	printf("%lld\n", solve(n, 0));
	return 0;
}
