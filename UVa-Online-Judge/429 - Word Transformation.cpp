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
vector<vector<int>> g;
int dist[250];
bool visited[250];
int bfs(int s, int t) {
	memset(dist, 0, sizeof dist);
	memset(visited, false, sizeof visited);
	visited[s] = true;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == t)
			break;
		for (auto v : g[u]) {
			if (!visited[v]) {
				visited[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return dist[t];
}
int main() {
	ios::sync_with_stdio(0);
//	freopen("in.txt", "r", stdin);
	int tc;
	cin >> tc;
	string s, t;
	vector<string> dictionary;
	bool newLine = false;
	while (tc--) {
		if (newLine)
			cout << endl;
		newLine = true;
		dictionary.clear(), g.clear();
		g.resize(210);
		while (true) {
			cin >> s;
			if (s == "*")
				break;
			dictionary.pb(s);
		}
		for (int i = 0; i < (int) dictionary.size(); i++) {
			for (int j = i + 1; j < (int) dictionary.size(); j++) {
				if (i == j || dictionary[i].length() != dictionary[j].length())
					continue;
				int diff = 0;
				for (int k = 0; k < (int) dictionary[i].length(); k++) {
					if (dictionary[i][k] == dictionary[j][k])
						continue;
					if (diff == 0)
						diff++;
					else {
						diff = -1;
						break;
					}
				}
				if (diff == 1)
					g[i + 1].pb(j + 1), g[j + 1].pb(i + 1);
			}
		}
		cin.ignore();
		while (true) {
			getline(cin, s);
			if (s.empty())
				break;
			stringstream scanner(s);
			scanner >> s >> t;
			int source, target;
			for (int i = 0; i < (int) dictionary.size(); i++) {
				if (s == dictionary[i])
					source = i + 1;
				if (t == dictionary[i])
					target = i + 1;
			}
			cout << s << ' ' << t << ' ' << bfs(source, target) << endl;
		}
	}
	return 0;
}
