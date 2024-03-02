#include <iostream>
#include <algorithm>
#define INF 987654321
#define ARR_SIZE 100 + 1

using namespace std;

int V, E;
int arr[ARR_SIZE][ARR_SIZE];
int from, to, weight;

void FloydWarshall() {
	for (int i = 1; i <= V; i++) // from vertex
		for (int j = 1; j <= V; j++) // to vertex
			for (int k = 1; k <= V; k++)
				if (arr[j][i] != INF && arr[i][k] != INF)
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
}

void main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			arr[i][j] = INF;

	for (int i = 0; i < E; i++) {
		cin >> from >> to >> weight;
		if (arr[from][to] > weight)
			arr[from][to] = weight;
	}

	FloydWarshall();
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j || arr[i][j] == INF)
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}