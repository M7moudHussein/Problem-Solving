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
int n, temp;
vector<ll> students;
ll leftDp[MAX], rightDp[MAX];
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		students.pb(temp);
	}
	if (n == 1)
		printf("1\n"), exit(0);
	ll ans = 0;
	leftDp[0] = 1;
	for (int i = 1; i < n; i++) {
		leftDp[i] = 1;
		if (students[i] > students[i - 1])
			leftDp[i] = leftDp[i - 1] + 1;
	}
	rightDp[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		rightDp[i] = 1;
		if (students[i] > students[i + 1])
			rightDp[i] = rightDp[i + 1] + 1;
	}
	for (int i = 0; i < n; i++) {
		ans += max(leftDp[i], rightDp[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
