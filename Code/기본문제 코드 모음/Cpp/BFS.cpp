#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX 500

using namespace std;

/*int n, m;
int map[MAX][MAX] = { 0, };
bool chk[MAX][MAX] = { 0, };

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;
vector<int> v;
int s = 1;

void BFS(int y, int x) {
	chk[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (map[ny][nx] == 1 && chk[ny][nx] == 0) {
				chk[ny][nx] = true;
				s++;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

bool Compare(int i, int j) {
	return i > j;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1 && chk[i][j] == 0) {
				BFS(i, j);
				v.push_back(s);
				cnt++;
				s = 1;
			}
		}
	}

	sort(v.begin(), v.end(), Compare);

	cout << cnt << endl;

	if (cnt == 0)
		cout << 0 << endl;
	else
		cout << v[0] << endl;
}*/