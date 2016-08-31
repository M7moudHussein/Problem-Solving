#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo ((ll) 1) << 62
#define max3(a,b,c) max((a),max((b),(c)))
#define MAX 16389
int n, temp;
//int dp[MAX][MAX];
map<pair<int, int>, int> dp;
vector<ll> arr;
vector<ll> sum;
pair<int, int> getMid(int l, int r) {
	pair<int, int> ret = mp(-1, -1);
	if ((sum[r] - sum[l] + arr[l]) % 2)
		return ret;
	int ind1 = lower_bound(sum.begin() + l, sum.begin() + r,
			(sum[r] - sum[l] + arr[l]) / 2 + sum[l] - arr[l]) - sum.begin();
	if (sum[ind1] - sum[l] + arr[l] == (sum[r] - sum[l] + arr[l]) / 2)
		ret = mp(ind1, ind1);
	else
		return ret;
	int ind2 = upper_bound(sum.begin() + l, sum.begin() + r,
			(sum[r] - sum[l] + arr[l]) / 2 + sum[l] - arr[l]) - sum.begin();
	if (sum[ind2] - sum[l] + arr[l] == (sum[r] - sum[l] + arr[l]) / 2)
		ret.S = ind2;
	return ret;
}
int solve(int L, int R) {
	pair<int, int> mid = getMid(L, R);
	if (mid.F == -1 || L >= R)
		return 0;
	if (dp.count(mp(L, R)))
		return dp[mp(L, R)];
	int ret = 0;
	ret = max(1 + solve(L, mid.F), 1 + solve(mid.F + 1, R));
	if (mid.S + 1 < n)
		ret = max3(ret, 1+solve(L, mid.S), 1 + solve(mid.S + 1, R));
	return dp[mp(L, R)] = ret;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		dp.clear();
		arr.clear(), sum.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			arr.pb(temp);
		}
		sum.pb(arr.front());
		for (int i = 1; i < n; i++) {
			sum.pb(sum.back() + arr[i]);
		}
		printf("%d\n", solve(0, n - 1));
	}
	return 0;
}
