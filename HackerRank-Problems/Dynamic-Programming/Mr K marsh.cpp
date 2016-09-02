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
int main() {
	ios_base::sync_with_stdio(0);
//	freopen("in.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	bool g[n][m];
	char temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> temp, g[i][j] = (temp == 'x');
	}
	int sum[n][m];
	memset(sum, 0, sizeof sum);
	for (int i = 0; i < m; i++)
		sum[0][i] = g[0][i];
	for (int i = 1; i < n; i++)
		for (int j = 0; j < m; j++)
			sum[i][j] = sum[i - 1][j] + g[i][j];
	int s, e, l, ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			l = INT_MIN;
			for (int k = 0; k < m; k++) {
				if (!(g[i][k] || g[j][k]) && sum[i][k] == sum[j][k]) {
					s = e = k;
					k++;
					while (k < m && !(g[i][k] || g[j][k])) {
						if (sum[i][k] == sum[j][k])
							e = k;
						k++;
					}
					l = max(l, e - s + 1);
				}
			}
			if (l > 1)
				ans = max(ans, ((j - i + 1) - 2) * 2 + l * 2);
		}
	}
	if (ans < 4)
		cout << "impossible\n" << endl;
	else
		cout << ans << endl;
	return 0;
}
