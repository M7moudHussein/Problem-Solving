#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo ((ll) 1) << 62
ll n, temp;
vector<ll> arr;
ll kadnie() {
	ll ans = -oo, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		ans = max(ans, sum);
		if (sum < 0)
			sum = 0;
	}
	return ans;
}
int main() {
//	freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		arr.clear();
		cin >> n;
		ll mx = -oo;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			mx = max(mx, temp);
			arr.pb(temp);
		}
		ll ans = 0;
		cout << kadnie() << ' ';
		if (mx <= 0)
			cout << mx << endl;
		else {
			for (int i : arr)
				if (i > 0)
					ans += i;
			cout << ans << endl;
		}
	}
	return 0;
}
