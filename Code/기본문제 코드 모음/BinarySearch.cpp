#include <iostream>
#include <algorithm>
/*#define MAX 10010

using namespace std;

int n, m;
int nums[MAX] = { };
int target[MAX] = { };

void BinarySearch(int st, int en, int target) {
	if (st == en) {
		if (nums[st] == target) 
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return;
	}

	int mid = (st + en) / 2;

	if (nums[mid] < target)
		BinarySearch(mid + 1, en, target);
	else
		BinarySearch(st, mid, target);
}

void main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums, nums + n);

	cin >> m;
	for (int i = 0; i < n; i++)
		cin >> target[i];

	for (int i = 0; i < n; i++)
		BinarySearch(0, n - 1, target[i]);
}*/