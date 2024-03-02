#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define MAX 26
using namespace std;

/*int n, cnt = 0;

int map[MAX][MAX];
bool chk[MAX][MAX];
vector<int> cntVec;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void DFS(int y, int x) {
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= n || ny < 0 || nx < 0)
			continue;
		if (chk[ny][nx] == false && map[ny][nx] == 1) {
			chk[ny][nx] = true;
			cnt += 1;
			DFS(ny, nx);
		}
	}
}

void main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int res = 0;
	cin >> n;
	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			chk[i][j] = false;

			if (str[j] == '1')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1 && chk[i][j] == false)
			{
				chk[i][j] = true;
				cnt = 1;
				DFS(i, j);
				cntVec.push_back(cnt);
				res++;
			}
		}
	}

	sort(cntVec.begin(), cntVec.end());
	cout << res << endl;

	for (int i = 0; i < cntVec.size(); i++)
	{
		cout << cntVec[i] << '\n';
	}
}*/