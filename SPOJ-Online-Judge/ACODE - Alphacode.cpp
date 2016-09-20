#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
string s;
vector<short> seq;
ll dp[5500];
ll solve(int i) {
	if (i >= (int) seq.size())
		return 1;
	if (dp[i] != -1)
		return dp[i];
	ll c1 = 0, c2 = 0;
	if (seq[i] != 0)
		c1 = solve(i + 1);
	if (i + 1 < (int) seq.size() && seq[i] != 0
			&& seq[i] * 10 + seq[i + 1] <= 26)
		c2 = solve(i + 2);
	return dp[i] = c1 + c2;
}
int main() {
	ios_base::sync_with_stdio(0);
	while (true) {
		cin >> s;
		if (s == "0")
			break;
		memset(dp, -1, sizeof dp);
		seq.clear();
		for (int i = 0; i < (int) s.length(); i++) {
			seq.pb(s[i] - '0');
		}
		cout << solve(0) << endl;
	}
	return 0;
}
