#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo ((ll) 1) << 62
#define intoo INT_MAX
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define PI 3.14159265358979323846
#define EPS 1e-8
#define isInteger(x) ((fabs((x)-round((x)))<EPS) ? true : false)
#define roundAns(x,d) round((x)*pow(10,(d)))/pow(10,(d))
#define MAX 200
ll mat[MAX][MAX];
void setMat(int n) {
	n += n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mat[i][j] += mat[i - 1][j];
}

ll maxSumRec(int n) {
	ll ans = 0;
	for (int i = 0; i <= 2 * n; i++)
		for (int j = i + 1; j <= 2 * n && j - i <= n; j++)
			for (int k = 1; k <= 2 * n; k++) {
				ll tempSum = 0;
				for (int h = k; h <= 2 * n && h - k + 1 <= n; h++) {
					tempSum += mat[j][h] - mat[i][h];
					ans = max(ans, tempSum);
					if (tempSum < 0)
						tempSum = 0;
				}
			}
	return ans;
}
int main() {
//	freopen("in.txt", "r", stdin);
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		ll temp, maxElement = LONG_LONG_MIN;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%lld", &temp);
				mat[i][j] = mat[i + n][j] = mat[i][j + n] = mat[i + n][j + n] = temp;
				maxElement = max(maxElement, temp);
			}
		}
		setMat(n);
		ll ans = maxSumRec(n);
		if (ans <= 0)
			printf("%lld\n", maxElement);
		else
			printf("%lld\n", ans);
	}
	return 0;
}
