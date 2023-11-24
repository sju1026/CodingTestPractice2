#include<iostream>
using namespace std;

int main(void) {
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

/* //

------------------------------
*/
#pragma endregion

#pragma endregion