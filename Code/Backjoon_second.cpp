#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}

#pragma region 문제풀이

#pragma region 분할정복
/*
// 2630
int arr[129][129];
int white = 0, blue = 0;

void fc(int x, int y, int k) {
    bool cut = false;
    int first_color = arr[x][y];
    for (int i = x; i < x + k; i++)
    {
        for (int j = y; j < y + k; j++)
        {
            if (arr[i][j] != first_color)
            {
                cut = true;
                break;
            }
        }
    }
    if (cut)
    {
        fc(x, y, k / 2);
        fc(x, y + k / 2, k / 2);
        fc(x + k / 2, y, k / 2);
        fc(x + k / 2, y + k / 2, k / 2);
    }
    else
    {
        if (first_color == 1)
            blue++;
        else
            white++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    fc(0, 0, n);
    cout << white << '\n' << blue << '\n';

    return 0;
}
---------------------------------------
// 1992
string s;
int n;
int video[64][64];

void solve(int x, int y, int size) {
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (video[i][j] != video[x][y])
            {
                cout << "(";
                solve(x, y, size / 2);
                solve(x, y + size / 2, size / 2);
                solve(x + size / 2, y, size / 2);
                solve(x + size / 2, y + size / 2, size / 2);
                cout << ")";
                return;
            }
        }
    }

    cout << video[x][y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
            video[i][j] = s[j] - '0';
    }
    solve(0, 0, n);

    return 0;
}
---------------------------------------
// 1780
#include <algorithm>
#include <vector>
#include <cmath>

int result[3];
int map[2200][2200];

bool check(int x, int y, int k) {
    int start = map[x][y];
    for (int i = x; i < x + k; i++)
        for (int j = y; j < y + k; j++)
            if (start != map[i][j])
                return false;

    return true;
}

void divide(int row, int col, int num) {
    if (check(row, col, num))
        result[map[row][col]]++;
    else
    {
        int size = num / 3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                divide(row + size * i, col + size * j, size);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            input++;
            map[i][j] = input;
        }

    divide(0, 0, n);
    cout << result[0] << '\n' << result[1] << '\n' << result[2];

    return 0;
}
---------------------------------------
// 1629
long long a, b, c, k;

long long power(long long b) {
    if (b == 0) return 1;
    if (b == 1) return a % c;

    k = power(b / 2) % c;
    if (b % 2 == 0) return k * k % c;
    return k * k % c * a % c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    cout << power(b);

    return 0;
}
---------------------------------------
// 11401
#include <cmath>

long long n, k, a, b, half;
long long mod = 1000000007;

long long solve(int x) {
    if (x == 0) return 1;
    if (x % 2 == 1)return b * solve(x - 1) % mod;
    else
    {
        half = solve(x / 2);
        return half * half % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    a = 1;
    for (int i = n; i >= n - k + 1; i--)
        a = (a * i) % mod;

    b = 1;
    for (int i = 1; i <= k; i++)
        b = (b * i) % mod;

    b = solve(mod - 2);

    cout << a * b % mod;

    return 0;
}
---------------------------------------
// 2740
int pro1[101][101];
int pro2[101][101];
int res[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> pro1[i][j];

    cin >> m >> k;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            cin >> pro2[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < m; l++) {
                res[i][j] += pro1[i][l] * pro2[l][j];
            }
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
---------------------------------------
// 10830
long long n, b;
int arr[5][5];
int result[5][5];
int temp[5][5];

void solve(int v1[5][5], int v2[5][5]) {
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++)
                temp[i][j] += (v1[i][k] * v2[k][j]);
            temp[i][j] %= 1000;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            v1[i][j] = temp[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        result[i][i] = 1;
    }

    while (b) {
        if (b % 2 == 1)
            solve(result, arr);
        solve(arr, arr);
        b /= 2;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
---------------------------------------
// 11444
#include<vector>

typedef vector<vector<long long>> matrix;
const long long mod = 1000000007;

long long n;

matrix operator * (matrix& a, matrix& b)
{
    matrix c(2, vector<long long>(2));

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++)
                c[i][j] += a[i][k] * b[k][j];

            c[i][j] %= mod;
        }
    return c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    matrix ans = { {1,0}, {0,1} };
    matrix a = { {1,1}, {1,0} };

    while (n > 0)
    {
        if (n % 2 == 1)
            ans = ans * a;
        a = a * a;
        n /= 2;
    }

    cout << ans[0][1] << '\n';
}
---------------------------------------
// 6549
// 추후에 다시 풀어볼 것
---------------------------------------
*/
#pragma endregion

#pragma region 이분 탐색 단계
/*
// 1920

------------------------------------------
// 10816

------------------------------------------
// 1654

------------------------------------------
// 2805

------------------------------------------
// 2110

------------------------------------------
// 1300
long long n, k;

long long lessNum(long long mid) {
    long long cnt = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cnt += min(n, (long long)mid / i);
        if (i > mid) break;
    }
    return cnt;
}

void matrix() {
    long long lo = 1;
    long long hi = n * n;

    int res = 0;

    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        if (lessNum(mid) < k) lo = mid + 1;
        else
        {
            res = mid;
            hi = mid - 1;
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    matrix();

    return 0;
}
------------------------------------------
// 12015
#include <vector>
#include <algorithm>

int a;
vector<int> arr;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a;

    for (int i = 0; i < a; i++)
    {
        int input;
        cin >> input;

        if (arr.empty() || arr.back() < input)
            arr.push_back(input);
        else
            *lower_bound(arr.begin(), arr.end(), input) = input;
    }
    cout << arr.size();

    return 0;
}
------------------------------------------
*/
#pragma endregion

#pragma region 우선순위 큐
/*
// 11279
#include <vector>
#include <queue>


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    vector<int> result;
    cin >> n;

    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x != 0)
            q.push(x);
        else
        {
            if (q.empty())
                result.push_back(0);
            else
            {
                result.push_back(q.top());
                q.pop();
            }
        }
    }
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';

    return 0;
}
---------------------------------
// 1927
#include <queue>

int n;

priority_queue<int, vector<int>, greater<int>> p;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (temp == 0) {
            if (p.empty())
                cout << 0 << '\n';
            else
            {
                cout << p.top() << '\n';
                p.pop();
            }
        }
        else
            p.push(temp);
    }

    return 0;
}
---------------------------------
// 11286
#include <queue>
#include <cmath>

struct comp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b))
            return a > b;
        else
            return abs(a) > abs(b);
    }
};

void Solution(int n) {
    priority_queue<int, vector<int>, comp> pq;

    while (n--)
    {
        int command;
        cin >> command;

        if (command == 0)
        {
            if (pq.empty())
                cout << '0' << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(command);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    Solution(n);

    return 0;
}
---------------------------------
*/
#pragma endregion

#pragma endregion