#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo ((ll) 1) << 62
#define max3(a,b,c) max((a),max((b),(c)))
int n, temp;
vector<ll> sum;
vector<int> h;
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		h.clear(), sum.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			h.pb(temp);
		}
		sort(h.begin(), h.end());
		sum.pb(h.front());
		for (int i = 1; i < n; i++)
			sum.pb(sum.back() + h[i]);
		ll ans = 0, s = 1;
		for (int i = 0; i < n; i++, s++) {
			ans = max(ans, s * (sum.back() - sum[i] + h[i]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}
