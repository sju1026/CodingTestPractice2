#include <iostream>
/*#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, pair<int, int>> T;

int V, E;
vector<T> v;
int parent[10000 + 1];
int ans;

int FindParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = FindParent(parent[x]);
}

void UnionParent(int a, int b) {
	a = FindParent(a);
	b = FindParent(b);
	parent[b] = a;
}

void main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c, {b, a} });
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= V; i++)
		parent[i] = i;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		T curEdge = v[i];
		int cost = curEdge.first;
		int now = curEdge.second.first;
		int next = curEdge.second.second;

		if (FindParent(now) == FindParent(next)) continue;

		UnionParent(now, next);
		ans += cost;

		if (++cnt == V - 1) break;
	}
	cout << ans << '\n';
}*/