#include <iostream>

using namespace std;

/*void main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	int a[10];

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int count = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] <= k)
		{
			count = count + k / a[i];
			k = k % a[i];
		}
		if (k == 0)
			break;
	}

	cout << count << '\n';
}*/