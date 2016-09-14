#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define oo ((ll) 1) << 62
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define MAX 50010

int dist[MAX], low[MAX], dfsNum[MAX], cnt, w, ret;
bool inStack[MAX], inCycle[MAX], notSource[MAX];
vector<vector<int>> g;
stack<int> myStack;
void tarjan(int s) {
	low[s] = dfsNum[s] = cnt++, inStack[s] = true;
	myStack.push(s);
	for (auto i : g[s])
		if (dfsNum[i] == -1)
			tarjan(i), low[s] = min(low[s], low[i]);
		else if (inStack[i])
			low[s] = min(low[s], dfsNum[i]);

	if (low[s] == dfsNum[s]) {
		vector<int> temp;
		int x = -1;
		while (x != s) {
			x = myStack.top(), myStack.pop(), inStack[x] = false;
			temp.pb(x);
		}
		if (temp.size() > 1) {
			for (auto i : temp)
				inCycle[i] = true, dist[i] = temp.size();
			w = temp.size();
		}
	}
}
void dfs(int s) {
	ret++;
	for (auto i : g[s]) {
		if (inCycle[i]) {
			ret += dist[i];
			return;
		}
		dfs(i);
	}
}
int main() {
//	freopen("in.txt", "r", stdin);

	int tc;
	int n;
	scanf("%d", &tc);
	for (int testCase = 1; testCase <= tc; testCase++) {
		scanf("%d", &n);

		g.clear(), g.resize(n + 1);
		memset(dist, 0, sizeof dist), memset(dfsNum, -1, sizeof dfsNum);
		memset(inStack, false, sizeof inStack), memset(inCycle, false, sizeof inCycle);
		memset(notSource, false, sizeof notSource);

		int u, v;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &u, &v);
			g[u].pb(v);
			notSource[v] = true;
		}

		int maxi = 0, ans = 1;
		for (int i = 1; i <= n; i++)
			if (!inStack[i]) {
				w = 0, tarjan(i);
				if (w > maxi)
					ans = i, maxi = w;
			}

		for (int i = 1; i <= n; i++)
			if (!notSource[i]) {
				ret = 0, dfs(i);
				if (ret > maxi)
					maxi = ret, ans = i;
			}

		printf("Case %d: %d\n", testCase, ans);
	}
	return 0;
}
