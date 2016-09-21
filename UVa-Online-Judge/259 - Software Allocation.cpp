#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
#define MAX 40
#define source  0
#define sink 37
vector<vector<int>> g;
int cap[MAX][MAX];
bool visited[MAX];
int parent[MAX];
int tempFlow;
void augment(int v, int minEdge) {
	if (v == source)
		tempFlow = minEdge;
	if (parent[v] != -1) {
		augment(parent[v], min(cap[parent[v]][v], minEdge));
		cap[parent[v]][v] -= tempFlow;
		cap[v][parent[v]] += tempFlow;
	}
}
int maxFlow() {
	int ret = 0;
	while (true) {
		queue<int> q;
		memset(visited, false, sizeof visited);
		memset(parent, -1, sizeof parent);
		tempFlow = 0;
		q.push(source);
		visited[source] = true;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == sink)
				break;
			for (int v : g[u]) {
				if (!visited[v] && cap[u][v] > 0) {
					visited[v] = true;
					parent[v] = u;
					q.push(v);
				}
			}
		}
		augment(sink, INT_MAX);
		if (tempFlow == 0)
			return ret;
		ret += tempFlow;
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	string temp;
	while (getline(cin, temp)) {
		memset(cap, 0, sizeof cap);
		int coundJobs = 0;
		g.clear();
		g.resize(MAX);
		do {
			int job = temp[0] - 'A' + 1;
			int rep = temp[1] - '0';
			coundJobs += rep;
			for (int i = 3; i < (int) temp.length() - 1; i++) {
				int compNumber = (temp[i] - '0') + 27;
				g[job].pb(compNumber);
				g[compNumber].pb(job);
				cap[job][compNumber] = INT_MAX;
			}
			g[0].pb(job);
			g[job].pb(0);
			cap[0][job] = rep;
			getline(cin, temp);
		} while (!temp.empty());
		for (int i = 27; i < 37; i++) {
			g[i].pb(37), g[37].pb(i);
			cap[i][37] = 1;
		}
		if (coundJobs > 10 || coundJobs != maxFlow()) {
			printf("!\n");
			continue;
		}
		char ans[20];
		bool jobCompleted = false;
		int k = 0;
		for (int i = 27; i < 37; i++) {
			jobCompleted = false;
			for (int j = 1; j <= 26; j++) {
				if (cap[i][j] > 0) {
					ans[k++] = (char) (('A' + j - 1));
					jobCompleted = true;
					break;
				}
			}
			if (!jobCompleted)
				ans[k++] = '_';
		}
		ans[k] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}
