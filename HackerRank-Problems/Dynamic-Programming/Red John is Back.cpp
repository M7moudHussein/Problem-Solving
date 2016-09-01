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
#define MAX 150
int tc, n;
ll dp[MAX][MAX];
ll solve(int i, int l) {
	if (l < 0)
		return 0;
	if (l == 0)
		return i == 0;
	if (dp[i][l] != -1)
		return dp[i][l];
	ll c1 = solve(i - 4, l - 4);
	ll c2 = solve(i - 1, l - 1);
	return dp[i][l] = c1 + c2;
}
vector<ll> primes;
bool isComplex[10000000];
void sieve() {
	memset(isComplex, false, sizeof isComplex);
	isComplex[0] = isComplex[1] = true;
	for (ll i = 2; i < 10000000; i++) {
		if (!isComplex[i]) {
			primes.pb(i);
			for (ll j = i * i; j < 10000000; j += i)
				isComplex[j] = true;
		}
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	sieve();
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		memset(dp, -1, sizeof dp);
		ll ret = solve(n, n);
		int ind = lower_bound(primes.begin(), primes.end(), ret) - primes.begin();
		if (primes[ind] == ret)
			printf("%d\n", ind + 1);
		else
			printf("%d\n", ind);
	}
	return 0;
}
