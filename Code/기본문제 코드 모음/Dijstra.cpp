#include <iostream>
/*#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int INF = 98765432;
int dp[20003];
vector<pair<int, int>> v[20003];

void Dijstra(int st) {
	memset(dp, INF, sizeof(dp));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, st });
	dp[st] = 0;

	while (!pq.empty())
	{
		int x = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < v[x].size(); i++)
		{
			int nx = v[x][i].first;
			int ncost = cost + v[x][i].second;

			if (dp[nx] > ncost) {
				pq.push({ ncost, nx });
				dp[nx] = ncost;
			}
		}
	}
}

void main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int V, E, K;
	cin >> V >> E >> K;
	int a1, a2, a3;
	for (int i = 0; i < E; i++)
	{
		cin >> a1 >> a2 >> a3;
		v[a1].push_back({ a2, a3 });
	}
	Dijstra(K);
	for (int i = 1; i < V + 1; i++)
	{
		if (dp[i] < INF)
			cout << dp[i] << '\n';
		else
			cout << "INF" << '\n';
	}
}*/