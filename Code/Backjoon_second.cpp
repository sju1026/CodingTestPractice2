#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

#pragma region 동적계획법2
/*
// 11066
#include <algorithm>
#include <limits.h>
using namespace std;
int t;
int dp[501][501];
int sum[501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            int a;
            cin >> a;
            sum[i] = sum[i - 1] + a;
        }

        for (int i = 1; i < k; i++) {
            for (int x = 1; x <= k - i; x++) {
                int y = x + i;
                dp[x][y] = INT_MAX;

                for (int mid = x; mid < y; mid++) {
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
                }
            }
        }
        cout << dp[1][k] << "\n";
    }
    return 0;
}
----------------------------------------
// 11049
#include <algorithm>
#include <climits>

int n;
const int max_n = 501;
int m[max_n][2];

int dp[max_n][max_n];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i < n + 1; i++)
    {
        cin >> m[i][0] >> m[i][1];
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; i + j < n + 1; j++)
        {
            dp[j][i + j] = INT_MAX;
            for (int k = j; k <= i+j; k++)
            {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + m[j][0] * m[k][1] * m[i + j][1]);
            }
        }

    cout << dp[1][n];
    return 0;
}
----------------------------------------
// 1520
const int max_n = 501;

int arr[max_n][max_n] = {};
int dp[max_n][max_n] = {};
bool visited[max_n][max_n] = { 0, };
int m, n;
int y_ar[4] = { 1, 0, -1, 0 };
int x_ar[4] = { 0, 1, 0, -1 };

int dfs(int cy, int cx) {
    if (cy == m && cx == n)
        return 1;
    if (visited[cy][cx])
        return dp[cy][cx];

    visited[cy][cx] = 1;
    for (int i = 0; i < 4; i++)
    {
        int next_y = cy + y_ar[i];
        int next_x = cx + x_ar[i];

        if (next_y > 0 && next_y <= m && next_x > 0 && next_x <= n)
            if (arr[cy][cx] > arr[next_y][next_x])
                dp[cy][cx] += dfs(next_y, next_x);
    }
    return dp[cy][cx];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    cout << dfs(1, 1) << '\n';

    return 0;
}
----------------------------------------
// 2629
int n, bead, x, weight[31];
bool dp[31][15001];

void solve(int i, int w) {
    if (i > n || dp[i][w]) return;
    dp[i][w] = true;
    solve(i + 1, w + weight[i]);
    solve(i + 1, abs(w - weight[i]));
    solve(i + 1, w);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    solve(0, 0);

    cin >> bead;

    for (int i = 0; i < bead; i++)
    {
        cin >> x;

        if (x > 15000) cout << "N ";
        else if (dp[n][x]) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}
----------------------------------------
// 2293
#include <vector>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> dp(k + 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = arr[i]; j <= k; j++)
            dp[j] += dp[j - arr[i]];

    cout << dp[k] << '\n';

    return 0;
}
----------------------------------------
// 7579
#include <algorithm>

int N, M;
int m[101] = { 0, };
int c[101] = { 0, };
int dp[101][10001] = { 0, };
int result = 1000000000;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> m[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (c[i] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
            else
                dp[i][j] = dp[i - 1][j];

            if (dp[i][j] >= M) result = min(result, j);
        }
    }


    cout << result << endl;

    return 0;
}
----------------------------------------

*/
#pragma endregion

#pragma region 스택2
/* // 9935
#include <string>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a;
    string b;
    string t = "";
    cin >> a >> b;
    int a_len = a.length();
    int b_len = b.length();
    for (int i = 0; i < a_len; i++)
    {
        t += a[i];
        if (t.length() >= b_len) {
            bool flag = true;
            for (int j = 0; j < b_len; j++)
            {
                if (t[t.length() - b_len + j] != b[j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                t.erase(t.end() - b_len, t.end());
            }
        }
    }
    if (t.empty())
        cout << "FRULA" << '\n';
    else
        cout << t << '\n';

    return 0;
}
----------------------------------
*/

/* // 17298
#include <algorithm>
#include <stack>

int n;
stack<int> s;
int ans[1000001];
int seq[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= seq[i])
            s.pop();

        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();

        s.push(seq[i]);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';

    return 0;
}
----------------------------------
*/

/*
// 17299
#include <vector>
#include <stack>
#define MAX 10000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<int> ngf(n + 1, -1);
    vector<int> cnt(MAX + 1, 0);
    stack<int> st;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    for (int i = 1; i < n + 1; i++)
    {
        while (!st.empty() && cnt[arr[st.top()]] < cnt[arr[i]])
        {
            ngf[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 1; i < n + 1; i++)
    {
        cout << ngf[i] << ' ';
    }
    cout << '\n';

    return 0;
}
----------------------------------
*/

/* // 1725
#include <algorithm>
#include <stack>

int n, ans, h[10000002];
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> h[i];

    s.push(0);

    for (int i = 1; i <= n + 1; i++)
    {
        while (!s.empty() && h[s.top()] > h[i])
        {
            int check = s.top();
            s.pop();
            ans = max(ans, h[check] * (i - s.top() - 1));
        }
        s.push(i);
    }
    cout << ans;

    return 0;
}
----------------------------------
*/

/* // 3015
#include <stack>


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int pn;
    cin >> pn;

    stack<pair<int, int>> st;
    int now, cnt_same_height = 0;
    long long cnt_pair = 0;

    for (int i = 0; i < pn; ++i) {
        cin >> now;

        cnt_same_height = 1;
        while (!st.empty() && st.top().first < now) {
            cnt_pair += st.top().second;
            st.pop();
        }

        if (!st.empty()) {
            if (st.top().first == now) {
                cnt_pair += st.top().second;
                cnt_same_height = (st.top().second + 1);
                if (st.size() > 1)
                    ++cnt_pair;

                st.pop();
            }
            else {
                ++cnt_pair;
            }
        }

        st.push(make_pair(now, cnt_same_height));
    }

    cout << cnt_pair << '\n';

    return 0;
}
----------------------------------
*/
#pragma endregion

#pragma region 문제 모음
/* // 24480 - 깊이우선탐색
#include <vector>
#include <algorithm>

int const max_n = 100001;

vector<int> graph[max_n];
bool visited[max_n] = { false };
int result[max_n] = { 0 };
int cnt = 0;

void dfs(int r) {
    if (visited[r])
        return;

    visited[r] = true;
    cnt++;
    result[r] = cnt;
    for (int i = 0; i < graph[r].size(); i++)
        dfs(graph[r][i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r, tempX, tempY;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        cin >> tempX >> tempY;
        graph[tempX].push_back(tempY);
        graph[tempY].push_back(tempX);
    }
    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end(), greater<int>());

    dfs(r);

    for (int i = 1; i <= n; i++)
        cout << result[i] << '\n';

    return 0;
}
--------------------------------------
*/

/* // 24445 - 너비 우선 탐색
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int const max_n = 100001;

vector<int> graph[max_n];
int visited[max_n] = { 0, };
int result[max_n];
int cnt = 0;

void bfs(int r) {
    queue<int> q;
    q.push(r);
    visited[r] = 1;
    cnt++;
    result[r] = cnt;
    while (!q.empty()) {
        int inq = q.front();

        q.pop();

        for (int i = 0; i < graph[inq].size(); i++) {
            int temp = graph[inq][i];
            if (!visited[temp]) {
                cnt++;
                result[temp] = cnt;
                q.push(temp);
                visited[temp] = 1;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<>());
    }
    bfs(r);
    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}
-------------------------
*/

/* // 1260 - DFS BFS
#include <queue>
#define MAX 1001

int n, m, v;
int map[MAX][MAX];
bool visited[MAX];
queue<int> q;

void reset() {
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
}

void DFS(int v) {
    visited[v] = true;
    cout << v << ' ';

    for (int i = 1; i <= n; i++)
        if (map[v][i] == 1 && visited[i] == 0)
            DFS(i);
}

void BFS(int v) {
    q.push(v);
    visited[v] = true;
    cout << v << ' ';

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int w = 1; w <= n; w++)
        {
            if (map[v][w] == 1 && visited[w] == 0) {
                q.push(w);
                visited[w] = true;
                cout << w << ' ';
            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    reset();
    DFS(v);

    cout << '\n';

    reset();
    BFS(v);

    return 0;
}
------------------------------
*/

/* // 2178 미로탐색
#include<iostream>
using namespace std;
#include <queue>
#define MAX 100

string map[MAX];
int dis[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n, m;
queue<pair<int, int>> q;

void bfs(int x, int y) {
    q.push(make_pair(x, y));
    dis[x][y] = 1;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m
                && dis[nx][ny] == 0 && map[nx][ny] == '1') {
                q.push(make_pair(nx, ny));
                dis[nx][ny] = dis[x][y] + 1;
            }
        }
    }
}
int main(void) {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> map[i];

    bfs(0, 0);

    cout << dis[n - 1][m - 1];
}
------------------------------
*/

/* // 1753 최단경로
#include <queue>
#include <vector>
#define INF 987654321
#define MAX 20010

int v, e, start;
int dist[MAX];
vector<pair<int, int>> vertex[MAX];

void Input() {
    cin >> v >> e >> start;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vertex[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= v; i++)
        dist[i] = INF;
}

void Solution() {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (pq.empty() == 0)
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        for (int i = 0; i < vertex[cur].size(); i++)
        {
            int next = vertex[cur][i].first;
            int nCost = vertex[cur][i].second;

            if (dist[next] > cost + nCost)
            {
                dist[next] = cost + nCost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

    for (int i = 1; i < v + 1; i++)
    {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}
------------------------------
*/

/* // 1504 - 특정한 최단 경로
#include<iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

const int INF = 987654321;

int n, e, v1, v2, res = INF;
int sToV1, sToV2, V1ToV2, V1ToN, V2ToN;
vector<pair<int, int>> v[801];
int dist[801];

void dijk(int start) {
    for (int i = 0; i <= n; i++)
        dist[i] = INF;
    dist[start] = 0;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0, start });
    while (!q.empty())
    {
        int cur = q.top().second;
        int curDist = q.top().first;
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int nextDist = v[cur][i].second;
            if (dist[next] > curDist + nextDist)
            {
                dist[next] = curDist + nextDist;
                q.push({ dist[next], next });
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a, c });
    }
    cin >> v1 >> v2;

    dijk(1);
    sToV1 = dist[v1];
    sToV2 = dist[v2];

    dijk(v1);
    V1ToV2 = dist[v2];
    V1ToN = dist[n];

    dijk(v2);
    V2ToN = dist[n];

    res = min(res, sToV1 + V1ToV2 + V2ToN);
    res = min(res, sToV2 + V1ToV2 + V1ToN);
    if (V1ToV2 == INF || res == INF)
        cout << -1;
    else
        cout << res;

    return 0;
}
------------------------------
*/

/* // 3273 두 수의 합
int num[100001];
int cnt[2000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        num[i] = temp;
        cnt[temp] = 1;
    }

    cin >> x;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (x - num[i] >= 0 && cnt[x - num[i]] != 0 && x - num[i] > num[i])
            sum += 1;
    }
    cout << sum;

    return 0;
}
------------------------------
*/

/* // 1806 부분합
int n, s;
cin >> n >> s;
vector<int> arr(n);
for (int i = 0; i < n; i++)
    cin >> arr[i];

int start = 0, end = 0, sum = 0, minLen = 0x7FFFFFF;
while (start <= end)
{
    if (sum >= s) {
        minLen = min(minLen, end - start);
        sum -= arr[start++];
    }
    else if (end == n)
        break;
    else
        sum += arr[end++];
}

if (minLen == 0x7FFFFFF)
    cout << 0 << '\n';
else
    cout << minLen << '\n';
------------------------------
*/

/* // 11779 최소비용 구하기 2
#include <vector>
#include <queue>

#define MAX 1010
#define INF 987654321

int n, m, start, End;
int dist[MAX];
int route[MAX];
vector<pair<int, int>> v[MAX];
vector<int> route_v;

void Input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
    cin >> start >> End;
}

void Solution() {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (pq.empty() == 0)
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i].first;
            int nCost = v[cur][i].second;

            if (dist[next] > cost + nCost)
            {
                route[next] = cur;
                dist[next] = cost + nCost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

    cout << dist[End] << '\n';
    int temp = End;
    while (temp)
    {
        route_v.push_back(temp);
        temp = route[temp];
    }
    cout << route_v.size() << '\n';
    for (int i = route_v.size() - 1; i >= 0; i--)
        cout << route_v[i] << ' ';
    cout << endl;
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}
------------------------------
*/

/* // 

------------------------------
*/

#pragma endregion

#pragma region 문제 모음 2
/* // 11725 트리의 부모 찾기
#include <vector>

#define MAX 100001

int n;
int arr[MAX];
bool visited[MAX];
vector<int> v[MAX];

void dfs(int k) {
    visited[k] = true;
    for (int i = 0; i < v[k].size(); i++)
    {
        int next = v[k][i];
        if (!visited[next])
        {
            arr[next] = k;
            dfs(next);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    for (int i = 2; i <= n; i++)
        cout << arr[i] << '\n';

    return 0;
}
------------------------------
*/

/* // 1167 트리의 지름
#include <vector>
#include <algorithm>
#include <queue>

int V, u, v, c;
int node, ans;
bool visit[100001];
vector<pair<int, int>> graph[100001];

void DFS(int x, int dist) {
    visit[x] = true;

    if (dist > ans)
    {
        ans = dist;
        node = x;
    }

    for (int i = 0; i < graph[x].size(); i++)
    {
        int next_node = graph[x][i].first;
        int next_dist = graph[x][i].second + dist;
        if (!visit[next_node])
        {
            visit[next_node] = true;
            DFS(next_node, next_dist);
            visit[next_node] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V;

    for (int i = 1; i <= V; i++) {
        cin >> u;
        while (true)
        {
            cin >> v;
            if (v == -1) break;
            cin >> c;
            graph[u].push_back({ v, c });
        }
    }

    DFS(1, 0);
    ans = 0;
    for (int i = 1; i <= V; i++)
        visit[i] = false;
    DFS(node, 0);
    cout << ans << '\n';

    return 0;
}
------------------------------
*/

/* // 1991 트리 순회 => 필수암기
int a[50][2];

void preorder(int n) {
    if (n == -1) return;
    cout << (char)(n + 'A');
    preorder(a[n][0]);
    preorder(a[n][1]);
}

void inorder(int n) {
    if (n == -1) return;
    inorder(a[n][0]);
    cout << (char)(n + 'A');
    inorder(a[n][1]);
}

void postorder(int n) {
    if (n == -1) return;
    postorder(a[n][0]);
    postorder(a[n][1]);
    cout << (char)(n + 'A');
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char x, y, z;
        cin >> x >> y >> z;
        x = x - 'A';
        if (y == '.')
            a[x][0] = -1;
        else
            a[x][0] = y - 'A';
        if (z == '.')
            a[x][1] = -1;
        else
            a[x][1] = z - 'A';
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);

    return 0;
}
------------------------------
*/

/* // 5639 이진 검색 트리
#include <vector>
#include <algorithm>

int n;
vector<int> v;

void go(int start, int end) {
    if (start >= end) return;
    if (start == end - 1) {
        cout << v[start] << '\n';
        return;
    }
    int idx = start + 1;
    while (idx < end)
    {
        if (v[start] < v[idx])
            break;
        idx++;
    }
    go(start + 1, idx);
    go(idx, end);
    cout << v[start] << '\n';
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> n)
    {
        v.push_back(n);
    }
    go(0, v.size());

    return 0;
}
------------------------------
*/

/* // 4803 트리
#include <vector>
#include <algorithm>

int n, m, u, v;
int ans, cnt;
bool visit[501];
vector<int> graph[501];

bool DFS(int x, int post_x) {
    visit[x] = true;

    for (int i = 0; i < graph[x].size(); i++)
    {
        if (graph[x][i] == post_x) continue;
        if (visit[graph[x][i]]) return false;
        if (DFS(graph[x][i], x) == false) return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        cnt++;
        ans = 0;
        for (int i = 1; i < 501; i++)
        {
            graph[i].clear();
            visit[i] = false;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i < n + 1; i++)
        {
            if (!visit[i])
                if (DFS(i, 0)) ans++;
        }

        cout << "Case " << cnt << ": ";
        if (ans > 1)
            cout << "A forest of " << ans << " trees." << '\n';
        else if (ans == 1)
            cout << "There is one tree." << '\n';
        else if (ans == 0)
            cout << "No trees." << '\n';
    }

    return 0;
}
------------------------------
*/

/* // 9342 - 상근이의 여행
#include <queue>
#include <vector>

vector<int> v[1001];
bool check[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    for (int t = 0; t < test; t++)
    {
        int node, edge, a, b;
        cin >> node >> edge;
        for (int i = 1; i < node + 1; i++)
        {
            v[i].clear();
            check[i] = false;
        }
        for (int i = 0; i < edge; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int result = 0;
        queue<int> q;
        q.push(1);
        check[1] = true;
        while (!q.empty()) {
            int cidx = q.front();
            q.pop();
            for (int i = 0; i < v[cidx].size(); i++)
            {
                int next = v[cidx][i];
                if (!check[next]) {
                    check[next] = true;
                    result++;
                    q.push(next);
                }
            }
        }
        cout << result << '\n';
    }

    return 0;
}
------------------------------
*/

/* // 4386 - 별자리 만들기
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

int n, m;
double u, v, x, y;
int parent[101];
double d, ans;
vector<pair<double, double>> star;
vector<tuple<double, int, int>> dist;

int find(int u) {
    if (parent[u] == u) return u;
    else return parent[u] = find(parent[u]);
}

bool union_node(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return false;
    else
    {
        parent[u] = v;
        return true;
    }
}

double Cal_dist(double x1, double y1, double x2, double y2) {
    double x_dist = pow(x1 - x2, 2);
    double y_dist = pow(y1 - y2, 2);

    return sqrt(x_dist + y_dist);
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    star.push_back({ 0, 0 });
    for (int i = 1; i < n + 1; i++)
    {
        cin >> x >> y;
        star.push_back({ x, y });
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            double r = Cal_dist(star[i].first, star[i].second, star[j].first, star[j].second);
            dist.push_back({ r, i , j });
        }
    }

    sort(dist.begin(), dist.end());

    for (int i = 0; i < dist.size(); i++) {
        x = get<1>(dist[i]);
        y = get<2>(dist[i]);
        d = get<0>(dist[i]);
        if (union_node(x, y))ans += d;
    }

    printf("%.2f", ans);

    return 0;
}
------------------------------
*/

/* // 15681 - 트리와 쿼리
#include <vector>

vector<int> v[100001];
bool visit[100001] = { false, };
int num[100001];
int node, query, s, e;

int dfs(int n) {
    if (num[n] != 0) return num[n];
    visit[n] = true;
    int ret = 1;
    for (int i = 0; i < v[n].size(); i++)
    {
        int next = v[n][i];
        if (visit[next]) continue;
        ret += dfs(next);
    }
    num[n] = ret;
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int root;
    cin >> node >> root >> query;
    for (int i = 0; i < node - 1; i++)
    {
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    num[root] = dfs(root);
    for (int i = 0; i < query; i++) {
        cin >> s;
        cout << num[s] << '\n';
    }

    return 0;
}
------------------------------
*/

/* // 2213 - 트리의 독립집합
#include <vector>
#include <algorithm>
#define MAX 100001

int n, a, b, x, ans1, ans2;
int v[MAX];
int dp[MAX][2];
bool visit[MAX];
vector<int> graph[MAX];
vector<int> ans;

void DFS(int now) {
    visit[now] = true;
    dp[now][1] = v[now];

    for (int child : graph[now]) {
        if (!visit[child]) {
            DFS(child);
            dp[now][0] += max(dp[child][0], dp[child][1]);
            dp[now][1] += dp[child][0];
        }
    }
}

void tracking(int prev, int now, int state) {
    if (state == 1) {
        ans.push_back(now);
        for (int child : graph[now]) {
            if (child == prev) continue;
            tracking(now, child, 0);
        }
    }
    else
    {
        for (int child : graph[now]) {
            if (child == prev) continue;
            if (dp[child][0] > dp[child][1])
                tracking(now, child, 0);
            else
                tracking(now, child, 1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1);

    ans1 = dp[1][0];
    ans2 = dp[1][1];

    if (ans1 > ans2) tracking(-1, 1, 0);
    else tracking(-1, 1, 1);

    cout << max(ans1, ans2) << '\n';

    sort(ans.begin(), ans.end());

    for (int x : ans)
        cout << x << ' ';

    return 0;
}
------------------------------
*/

/* // 2533 - 사회망서비스
#include <vector>
#define MAX 1000001

int n, parent;
vector<int> v[MAX];
int dp[MAX][2];
bool visit[MAX] = { false, };

void find(int x) {
    visit[x] = true;
    dp[x][0] = 1;
    for (int i = 0; i < v[x].size(); i++)
    {
        int child = v[x][i];
        if (visit[child]) continue;
        find(child);
        dp[x][1] += dp[child][0];
        dp[x][0] += min(dp[child][1], dp[child][0]);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int u, e;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> e;
        v[u].push_back(e);
        v[e].push_back(u);
    }

    find(1);
    cout << min(dp[1][0], dp[1][1]);

    return 0;
}
------------------------------
*/

/* // 1949 - 우수마을
#include <vector>
#include <algorithm>
#define MAX 1000001

int n, a, b;
int citizen[MAX];
int dp[MAX][2];
bool visit[MAX];
vector<int> v[MAX];

void DFS(int c) {
    visit[c] = true;

    dp[c][0] = 0;
    dp[c][1] = citizen[c];

    for (int next : v[c]) {
        if (!visit[next]) {
            DFS(next);
            dp[c][0] += max(dp[next][0], dp[next][1]);
            dp[c][1] += dp[next][0];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> citizen[i];

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);

    cout << max(dp[1][0], dp[1][1]);

    return 0;
}
------------------------------
*/

/* // 2252 - 줄 세우기
#include <vector>
#include <queue>
#define MAX 32001

vector<int> graph[MAX];
int inDegree[MAX];
int n, m;

void TopologicalSort(void) {
    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (!inDegree[i])
            q.push(i);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int i = 0; i < graph[cur].size(); i++)
        {
            inDegree[graph[cur][i]]--;
            if (!inDegree[graph[cur][i]])
                q.push(graph[cur][i]);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    TopologicalSort();

    return 0;
}
--------------------------------
*/

/* // 2042 - 구간 합 구하기
#define MAX 1000001

int n, m, k;
long long arr[MAX];

long long segTree[MAX * 4];

long long init(int start, int end, int nodeNum) {
    if (start == end)
        return segTree[nodeNum] = arr[start];

    int mid = (start + end) / 2;
    return segTree[nodeNum] = init(start, mid, nodeNum * 2) + init(mid + 1, end, nodeNum * 2 + 1);
}

long long subSum(int start, int end, int nodeNum, int left, int right) {
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return segTree[nodeNum];
    int mid = (start + end) / 2;
    return subSum(start, mid, nodeNum * 2, left, right) + subSum(mid + 1, end, nodeNum * 2 + 1, left, right);
}

void update(int start, int end, int nodeNum, int targetIdx, long long val) {
    if (targetIdx < start || end < targetIdx)
        return;

    segTree[nodeNum] += val;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, nodeNum * 2, targetIdx, val);
    update(mid + 1, end, nodeNum * 2 + 1, targetIdx, val);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    int num;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    init(0, n - 1, 1);

    long long a, b, c;
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            long long tmp = c - arr[b - 1];
            arr[b - 1] = c;
            update(0, n - 1, 1, b - 1, tmp);
        }
        else
        {
            cout << subSum(0, n - 1, 1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}
--------------------------------
*/

/* // 11505 - 구간 곱 구하기
#include <cmath>
#define MAX 1000001
#define MOD 1000000007

long long arr[1000001];
long long* segTree;

int n, m, k, height, a;
long long b, c, big, small;

long long init(int nodeNum, int start, int end) {
    if (start == end)
        return segTree[nodeNum] = arr[start];

    int mid = start + (end - start) / 2;
    return segTree[nodeNum] = (init(2 * nodeNum, start, mid) * init(2 * nodeNum + 1, mid + 1, end)) % MOD;
}

long long mul(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return segTree[node];
    int mid = start + (end - start) / 2;
    return (mul(node * 2, start, mid, left, right) * mul(node * 2 + 1, mid + 1, end, left, right)) % MOD;
}

long long update(int node, int start, int end, int idx, long long val) {
    if (idx > end || idx < start) return segTree[node];
    if (start == end) return segTree[node] = val;
    int mid = start + (end - start) / 2;
    return segTree[node] = (update(2 * node, start, mid, idx, val) * update(2 * node + 1, mid + 1, end, idx, val)) % MOD;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    height = ceil(log2(n));
    segTree = new long long[1 << (height + 1)];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    init(1, 0, n - 1);
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            arr[b - 1] = c;
            update(1, 0, n - 1, b - 1, c);
        }
        else
        {
            big = b > c ? b : c;
            small = b > c ? c : b;
            cout << mul(1, 0, n - 1, small - 1, big - 1) << '\n';
        }
    }

    return 0;
}
--------------------------------
*/

/* // 2357 - 최솟값과 최댓값
#include <cmath>
#define MAX 1000000001

long long* maxTree;
long long* minTree;
long long arr[100000];
int n, height, query, big, small, a, b;

int init(int node, int start, int end, bool maximum) {
    if (start == end)
    {
        if (maximum) return maxTree[node] = arr[start];
        else return minTree[node] = arr[start];
    }
    int mid = start + (end - start) / 2;
    if (maximum)
        return maxTree[node] = max(init(2 * node, start, mid, maximum), init(2 * node + 1, mid + 1, end, maximum));
    return minTree[node] = min(init(2 * node, start, mid, maximum), init(2 * node + 1, mid + 1, end, maximum));
}

int findVal(int node, int start, int end, int left, int right, bool maximum) {
    if (left > end || right < start) {
        if (maximum) return -MAX;
        return MAX;
    }
    if (left <= start && end <= right) {
        if (maximum) return maxTree[node];
        else return minTree[node];
    }
    int mid = start + (end - start) / 2;
    if (maximum) return max(findVal(node * 2, start, mid, left, right, maximum), findVal(node * 2 + 1, mid + 1, end, left, right, maximum));
    return min(findVal(node * 2, start, mid, left, right, maximum), findVal(node * 2 + 1, mid + 1, end, left, right, maximum));
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> query;
    height = ceil(log2(n));
    minTree = new long long[1 << (height + 1)];
    maxTree = new long long[1 << (height + 1)];

    for (int i = 0; i < (1 << (height + 1)); i++)
        minTree[i] = MAX;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    init(1, 0, n - 1, true);
    init(1, 0, n - 1, false);

    for (int i = 0; i < query; i++)
    {
        cin >> a >> b;
        big = a > b ? a : b;
        small = a > b ? b : a;
        cout << findVal(1, 0, n - 1, small - 1, big - 1, false) << " " << findVal(1, 0, n - 1, small - 1, big - 1, true) << "\n";
    }

    return 0;
}
--------------------------------
*/

/* // 1517 - 버블소트
#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 1000000001
using namespace std;

vector<pair<int, int>> Data; // first : value, second : index
vector<int> Tree;

void updateTree(int Node, int Begin, int End, int Index) {
    if (Begin == End) {
        Tree[Node] = 1;
        return;
    }
    int Mid = (Begin + End) / 2;
    if (Index <= Mid) updateTree(Node * 2, Begin, Mid, Index);
    else updateTree(Node * 2 + 1, Mid + 1, End, Index);
    Tree[Node] = Tree[Node * 2] + Tree[Node * 2 + 1];
}

int cntLess(int Node, int Begin, int End, int Left, int Right) {
    if (Left > End || Right < Begin) return 0;
    if (Left <= Begin && Right >= End) return Tree[Node];
    int Mid = (Begin + End) / 2;
    int leftCnt = cntLess(Node * 2, Begin, Mid, Left, Right);
    int rightCnt = cntLess(Node * 2 + 1, Mid + 1, End, Left, Right);
    return leftCnt + rightCnt;
}

int main() {
    int N, Value;
    long long Ans = 0;
    scanf("%d", &N);
    Tree.resize(N * 4 + 1);
    Data.push_back({ -INF, 0 });
    for (int i = 1; i <= N; i++) {
        scanf("%d", &Value);
        Data.push_back({ Value, i });
    }
    sort(Data.begin(), Data.end());
    for (int i = 1; i <= N; i++) {
        Ans += (long long)cntLess(1, 1, N, Data[i].second + 1, N);
        updateTree(1, 1, N, Data[i].second);
    }
    printf("%lld", Ans);
}
--------------------------------
*/
#pragma endregion

#pragma endregion