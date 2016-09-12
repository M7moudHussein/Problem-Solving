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
#define MAX
vector<int> parent;
int getParent(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = getParent(parent[x]);
}
bool areConnected(int x, int y) {
	x = getParent(x), y = getParent(y);
	if (x == y)
		return true;
	return false;
}
void connect(int x, int y) {
	if (areConnected(x, y))
		return;
	x = getParent(x), y = getParent(y);
	parent[x] = y;
}
int main() {
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int tc;
	scanf("%d", &tc);
	string s;
	char c;
	int n, a, b;
	bool newLine = false;
	int connected, notConnected;
	while (tc--) {
		scanf("\n%d\n", &n);
		if (newLine)
			printf("\n");
		newLine = true;
		parent.clear(), parent.resize(n + 1);
		connected = 0, notConnected = 0;
		for (int i = 0; i <= n; i++)
			parent[i] = i;
		while (true) {
			if (!getline(cin, s) || s.empty())
				break;
			sscanf(s.c_str(), "%c %d %d", &c, &a, &b);
			if (c == 'c')
				connect(a, b);
			else if (c == 'q')
				areConnected(a, b) ? connected++ : notConnected++;
		}
		printf("%d,%d\n", connected, notConnected);
	}
	return 0;
}
