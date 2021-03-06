#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector<pair<int, int> > a[100020];
priority_queue<pair<int, int> > q;
int d[100020];
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
	}
	memset(d, 0x3f, sizeof d);
	d[s] = 0;
	q.push(make_pair(-d[s], s));
	while (q.size() > 0) {
		pair<int, int> u = q.top();
		q.pop();
		if (-u.first > d[u.second]) {
			continue;
		}
		for (int i = 0; i < a[u.second].size(); i++) {
			pair<int, int> e = a[u.second][i];
			if (d[e.first] > d[u.second] + e.second) {
				d[e.first] = d[u.second] + e.second;
				q.push(make_pair(-d[e.first], e.first));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d%c", d[i], i == n ? '\n' : ' ');
	}
	return 0;
}