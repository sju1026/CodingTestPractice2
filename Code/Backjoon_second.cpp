#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#define MAX 1000001

typedef long long ll;
ll n, a[MAX], b[MAX], d[MAX], ans;

struct line {
    ll a, b;
    double s = 0;

    line(ll a, ll b, double s) : a(a), b(b), s(s) {}

    bool operator<(const line& l) const {
        return s < l.s;
    }
};

vector<line> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    v.emplace_back(b[0], 0, 0);

    for (int i = 1; i < n; i++) {
        line current(0, 0, a[i]);
        line l = *(upper_bound(v.begin(), v.end(), current) - 1);

        d[i] = l.a * a[i] + l.b;

        line nxt(b[i], d[i], 0);
        double crossPoint = 0;

        while (v.size())
        {
            line prv = v.back();
            crossPoint = (double)(prv.b - nxt.b) / (nxt.a - prv.a);
            if (crossPoint <= prv.s) v.pop_back();
            else
                break;
        }
        nxt.s = crossPoint;
        v.push_back(nxt);
    }

    cout << d[n - 1];

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

#pragma region 문제풀이 3
/* // 2170 - 선긋기
#include <algorithm>
#include <vector>

int n;
vector<pair<int, int>> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    int start = arr[0].first, end = arr[0].second;
    for (int i = 1; i < n; i++) {
        int s = arr[i].first, e = arr[i].second;
        if (end >= s) {
            if (end < e)
                end = e;
        }
        else {
            ans += end - start;
            start = s, end = e;
        }
    }
    ans += end - start;
    cout << ans << '\n';

    return 0;
}
------------------------------
*/

/* // 2836 - 수상택시
#include <algorithm>
#include <vector>

int n;
long long m;
long long result;
vector<pair<long long, long long >> people;

void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        long long from, to;
        cin >> from >> to;
        if (from < to)
            continue;
        people.push_back({ to, from });
    }

    sort(people.begin(), people.end());
}

void calc() {
    long long start = -1;
    long long last = -1;

    for (auto p : people) {
        if (last < p.first)
        {
            result += (last - start);
            start = p.first;
        }
        if (last < p.second) {
            last = p.second;
        }
    }
    result += (last - start);
    result *= 2;
    result += m;
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    calc();

    return 0;
}
------------------------------
*/

/* // 5419 - 북서풍
#define MAX_N 75001
#include <algorithm>
#include <vector>

int tree[MAX_N * 4];
vector<pair<int, int>> vec;
vector<int> y_vec;

void init(int now, int start, int end) {
    if (start > end) return;
    if (start == end)
    {
        tree[now] = 0;
        return;
    }
    tree[now] = 0;
    int mid = (start + end) / 2;
    init(now * 2, start, mid);
    init(now * 2 + 1, mid + 1, end);
}

void update(int now, int target, int start, int end) {
    if (target > end || target < start) return;
    if (start == end) {
        tree[now]++;
        return;
    }
    int mid = (start + end) / 2;
    update(now * 2, target, start, mid);
    update(now * 2 + 1, target, mid + 1, end);
    tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

int query(int now, int left, int right, int start, int end) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) {
        return tree[now];
    }
    int mid = (start + end) / 2;
    return (query(now * 2, left, right, start, mid) + query(now * 2 + 1, left, right, mid + 1, end));
}

bool cmp_x_y(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

bool cmp_y(int a, int b) {
    return a > b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vec.clear();
        y_vec.clear();
        init(1, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            vec.push_back({ x , y });
            y_vec.push_back(y);
        }

        long long ret = 0;
        sort(vec.begin(), vec.end(), cmp_x_y);
        sort(y_vec.begin(), y_vec.end(), cmp_y);
        for (int i = 0; i < vec.size(); i++)
        {
            int x = vec[i].first, y = vec[i].second;
            int index = upper_bound(y_vec.begin(), y_vec.end(), y, cmp_y) - y_vec.begin() - 1;
            ret += query(1, 0, index, 0, n - 1);
            update(1, index, 0, n - 1);
        }
        cout << ret << '\n';
    }

    return 0;
}
------------------------------
*/

/* // 7626 - 직사각형
#include <algorithm>
#include <vector>

#define MAXSIZE 400001

typedef pair<int, int> p;
typedef long long ll;

typedef struct vert {
    int x;
    p y;
    bool start;
} vert;

int n;
ll segtree[MAXSIZE * 4];
ll cnt[MAXSIZE * 4];
vector<vert> verts;
vector<int> ylist;

void update(int node, int start, int end, int l, int r, int val) {
    if (l > end || r < start) return;
    if (l <= start && end <= r)
        cnt[node] += val;
    else
    {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, val);
        update(node * 2 + 1, mid + 1, end, l, r, val);
    }

    if (cnt[node])
        segtree[node] = (ll)ylist[end] - ylist[start - 1];
    else
    {
        if (start == end) segtree[node] = 0;
        else
            segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
    }
}

ll get_answer() {
    ll ret = 0;
    int diff_x = 0, diff_y;
    for (int i = 0; i < verts.size(); i++)
    {
        if (i > 0) {
            diff_x = verts[i].x - verts[i - 1].x;
            ret += segtree[1] * diff_x;
        }
        int val = verts[i].start == true ? 1 : -1;
        int y1_idx = lower_bound(ylist.begin(), ylist.end(), verts[i].y.first) - ylist.begin();
        int y2_idx = lower_bound(ylist.begin(), ylist.end(), verts[i].y.second) - ylist.begin();
        update(1, 1, ylist.size(), y1_idx + 1, y2_idx, val);
    }
    return ret;
}

vert create_vert(int x, int y1, int y2, bool start) {
    vert temp;
    temp.x = x;
    temp.y.first = y1; temp.y.second = y2;
    temp.start = start;
    return temp;
}

bool cmp_vert(vert a, vert b) {
    return a.x < b.x;
}

void init() {
    int x1, x2, y1, y2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2 >> y1 >> y2;
        verts.push_back(create_vert(x1, y1 + 1, y2 + 1, true));
        verts.push_back(create_vert(x2, y1 + 1, y2 + 1, false));
        ylist.push_back(y1 + 1);
        ylist.push_back(y2 + 1);
    }

    sort(ylist.begin(), ylist.end());
    ylist.erase(unique(ylist.begin(), ylist.end()), ylist.end());
    sort(verts.begin(), verts.end(), cmp_vert);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    ll answer = get_answer();
    cout << answer << '\n';

    return 0;
}
------------------------------
*/

/* // 1708 - 블록 껍질
#include <algorithm>
#include <stack>
#include <vector>

struct pos {
    long long x, y;
};

vector <pos> v;
stack <pos> s;

long long ccw(pos a, pos b, pos c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

bool compare(pos a, pos b) {
    long long cc = ccw(v[0], a, b);

    if (cc) return cc > 0;
    else if (a.y != b.y)
        return a.y < b.y;
    else
        return a.x < b.x;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    v.resize(t);
    for (int i = 0; i < t; i++)
        cin >> v[i].x >> v[i].y;

    for (int i = 1; i < t; i++) {
        if (v[i].y < v[0].y || (v[i].y == v[0].y && v[i].x < v[0].x)) {

            long long temp = v[0].x;
            v[0].x = v[i].x;
            v[i].x = temp;

            temp = v[0].y;
            v[0].y = v[i].y;
            v[i].y = temp;
        }
    }

    sort(v.begin() + 1, v.end(), compare);

    s.push(v[0]);
    s.push(v[1]);

    for (int i = 2; i < t; i++) {
        while (s.size() >= 2) {
            pos top2 = s.top();
            s.pop();

            pos top1 = s.top();
            if (ccw(top1, top2, v[i]) > 0) {
                s.push(top2);
                break;
            }
        }
        s.push(v[i]);
    }

    cout << s.size();

    return 0;
}
------------------------------
*/

/* // 3679 - 단순 다각형
#include <algorithm>
#include <cmath>

struct D {
    int i, x, y;
};

D d[2020], mi;
int ccw(D a, D b, D c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool cmp(D a, D b) {
    int c = ccw(mi, a, b);
    if (c == 0)
        return abs(a.x - mi.x) + abs(a.y - mi.y) < abs(b.x - mi.x) + abs(b.y - mi.y);
    if (c > 0)
        return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c, idx;
    cin >> c;
    while (c--)
    {
        int n;
        cin >> n;
        mi = { -1, 99999, 99999 };
        for (int i = 0; i < n; i++)
        {
            cin >> d[i].x >> d[i].y;
            d[i].i = i;
            if (mi.y > d[i].y || (mi.y == d[i].y && mi.x > d[i].x)) {
                mi = { i, d[i].x, d[i].y };
                idx = i;
            }
        }
        swap(d[0], d[idx]);
        sort(d + 1, d + n, cmp);
        int l;
        for (l = n - 2; l > 0; l--) if (ccw(d[0], d[l], d[n - 1]) != 0) break;
        l++;
        for (int i = l; i < (n + l + 1) / 2; i++) swap(d[i], d[n - i + l - 1]);
        for (int i = 0; i < n; i++) cout << d[i].i << ' ';
        cout << '\n';
    }

    return 0;
}
------------------------------

/* // 

------------------------------

/* //

------------------------------
*/

/* // 11376 - 열혈강호 2
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 1003

vector<int> adj[MAX];
bool check[MAX];
int d[MAX];

bool dfs(int cur) {
    for (int nxt : adj[cur]) {
        if (check[nxt]) continue;
        check[nxt] = true;
        if (d[nxt] == 0 || dfs(d[nxt])) {
            d[nxt] = cur;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, S, num;
    int cnt = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        while (S--) {
            cin >> num;
            adj[i].push_back(num);
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 2; j++) {
            fill(check, check + MAX, false);
            if (dfs(i)) cnt++;
        }
    }
    cout << cnt << "\n";
}
------------------------------
*/

/* // 1867 - 돌맹이 제거
#include <vector>
#include <string.h>

int n, k, ans;
bool visited[501];
int bm[501];
vector<vector<int>> grid(501);

bool DFS(int row) {
    if (visited[row])
        return false;
    visited[row] = true;

    for (int i = 0; i < grid[row].size(); i++)
    {
        int column = grid[row][i];
        if (bm[column] == 0 || DFS(bm[column])) {
            bm[column] = row;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        grid[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited, false, n + 1);
        if (DFS(i))
            ans++;
    }
    cout << ans << '\n';

    return 0;
}
------------------------------
*/

/* // 11378 - 열혈강호 4
#include <vector>
#include <cstring>

const int MAX = 1e3 + 1;

int n, m, k;
vector<int> works[MAX];
int worker2work[MAX], work2worker[MAX];
bool visited[MAX];

bool func(int worker) {
    for (int workNum : works[worker]) {
        if (visited[workNum])
            continue;
        visited[workNum] = true;
        if (work2worker[workNum] == -1 || func(work2worker[workNum])) {
            worker2work[worker] = workNum;
            work2worker[workNum] = worker;

            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        int cnt;
        cin >> cnt;

        for (int j = 0; j < cnt; j++)
        {
            int work;
            cin >> work;

            works[i].push_back(work - 1);
        }
    }

    memset(worker2work, -1, sizeof(worker2work));
    memset(work2worker, -1, sizeof(work2worker));

    int result = 0;

    for (int worker = 0; worker < n; worker++) {
        if (worker2work[worker] == -1) {
            memset(visited, false, sizeof(visited));
            if (func(worker))
                result++;
        }
    }

    int points = 0;
    while (1)
    {
        bool flag = false;
        for (int worker = 0; worker < n && points < k; worker++)
        {
            memset(visited, false, sizeof(visited));
            if (func(worker))
            {
                result++;
                flag = true;
                points++;
                break;
            }
        }
        if (flag == false)
        {
            break;
        }
    }

    cout << result << '\n';

    return 0;
}
------------------------------
*/

/* // 2365 - 숫자판 만들기
#include <vector>
#include <queue>
#include <cstring>

int c[111][111];
int f[111][111];
int bias = 50;
int n;
vector<int> g[111];
int par[111];

int a[55], b[55];
int asum, bsum;

int s = 101, t = 102;

void init(int x) {
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j + bias] = x;
        }
    }
}

bool chk(int x) {
    init(x);
    int res = 0;
    while (1) {
        memset(par, -1, sizeof par);
        queue<int> q; q.push(s);
        while (q.size()) {
            int now = q.front(); q.pop();
            for (auto nxt : g[now]) {
                if (par[nxt] == -1 && c[now][nxt] - f[now][nxt] > 0) {
                    par[nxt] = now; q.push(nxt);
                }
            }
        }
        int flow = 1e9 + 7;
        if (par[t] == -1) break;
        for (int i = t; i != s; i = par[i]) {
            int a = par[i], b = i;
            flow = min(flow, c[a][b] - f[a][b]);
        }
        res += flow;
        for (int i = t; i != s; i = par[i]) {
            int a = par[i], b = i;
            f[a][b] += flow; f[b][a] -= flow;
        }
    }
    return asum == bsum && asum == res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], asum += a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], bsum += b[i];
    for (int i = 1; i <= n; i++) {
        g[s].push_back(i);
        c[s][i] = a[i];
        c[i + bias][t] = b[i];
        g[i + bias].push_back(t);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i].push_back(j + bias);
            g[j + bias].push_back(i);
        }
    }

    int l = 0, r = 10000;
    int ans = -1;
    while (l <= r) {
        int m = l + r >> 1;
        if (chk(m)) {
            ans = m; r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    cout << ans << "\n";
    chk(ans);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f[i][j + bias] << " ";
        }
        cout << "\n";
    }
}
------------------------------
*/

/* // 11408 - 열혈강호 5
#include <vector>
#include <queue>

const int SOURCE = 800, SINK = 801, MAX = 802, MAX_VALUE = 987654321;
int N, M, totalCost = 0, jobDone = 0;

vector<int> map[MAX];
int job[MAX][MAX] = { 0 };
int flow[MAX][MAX] = { 0 };
int cost[MAX][MAX] = { 0 };

int lastIdx[MAX];
int dist[MAX] = { 0 };
bool inQueue[MAX] = { false };

queue<int> q;

void init() {
    fill(lastIdx, lastIdx + MAX, -1);
    fill(dist, dist + MAX, MAX_VALUE);
    q.push(SOURCE);
    inQueue[SOURCE] = true;
    dist[SOURCE] = 0;
}

bool spfa() {
    init();

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        inQueue[now] = false;

        for (int next : map[now]) {
            int tempSum = dist[now] + cost[now][next];
            if (job[now][next] > flow[now][next] && dist[next] > tempSum) {
                dist[next] = tempSum;
                lastIdx[next] = now;

                if (!inQueue[next]) {
                    inQueue[next] = true;
                    q.push(next);
                }
            }
        }
    }
    return dist[SINK] != MAX_VALUE;
}

int findMinFlow() {
    int minFlow = MAX_VALUE;
    for (int now = SINK; now != SOURCE; now = lastIdx[now]) {
        minFlow = min(minFlow, job[lastIdx[now]][now] - flow[lastIdx[now]][now]);
    }
    return minFlow;
}

int update(int minFlow) {
    int allSum = 0;
    for (int now = SINK; now != SOURCE; now = lastIdx[now]) {
        allSum += cost[lastIdx[now]][now];
        flow[lastIdx[now]][now]++;
        flow[now][lastIdx[now]]--;
    }
    return allSum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int size, jobType, fee;
    for (int people = 0; people < N; people++) {
        job[SOURCE][people] = 1;
        map[SOURCE].push_back(people);
        map[people].push_back(SOURCE);

        cin >> size;
        for (int i = 0; i < size; i++) {
            cin >> jobType >> fee;
            jobType += N - 1;

            map[people].push_back(jobType);
            map[jobType].push_back(people);

            cost[people][jobType] = fee;
            cost[jobType][people] = -fee;

            job[people][jobType] = MAX_VALUE;
        }
    }

    for (int jobType = N; jobType < N + M; jobType++) {
        job[jobType][SINK] = 1;
        map[jobType].push_back(SINK);
        map[SINK].push_back(jobType);
    }

    while (spfa()) {
        jobDone++;
        totalCost += update(findMinFlow());
    }

    cout << jobDone << '\n';
    cout << totalCost << '\n';

    return 0;
}
------------------------------
*/

/* // 13261 - 탈옥
using ll = long long;

ll dp[805][8005];
ll c[8005];
ll pre[8005];
int l, g;

ll f(ll i, ll j) {
    return(i - j) * (pre[i] - pre[j]);
}

void solve(int lev, int s, int e, int optl, int optr) {
    if (s > e) return;
    int mid = (s + e) >> 1;
    int opt = -1;
    ll& ans = dp[lev][mid];

    for (int i = optl; i < min(mid, optr); ++i) {
        ll val = dp[lev - 1][i] + (mid - i) * (pre[mid] - pre[i]);
        if (opt == -1 || ans > val) {
            opt = i;
            ans = val;
        }
    }
    solve(lev, s, mid - 1, optl, opt + 1);
    solve(lev, mid + 1, e, opt, optr);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> g;
    if (g >= l)
        g = l;
    for (int i = 1; i <= l; ++i)
        cin >> c[i];
    for (int i = 1; i <= l; ++i)
        pre[i] = pre[i - 1] + c[i];
    for (int i = 1; i <= l; ++i)
        dp[1][i] = pre[i] * i;
    for (int i = 2; i <= g; ++i)
        solve(i, 1, l, 0, l);

    cout << dp[g][l] << '\n';

    return 0;
}
------------------------------
*/

/* // 13263 - 나무 자르기
#include <algorithm>
#include <vector>
#define MAX 1000001

typedef long long ll;
ll n, a[MAX], b[MAX], d[MAX], ans;

struct line {
    ll a, b;
    double s = 0;

    line(ll a, ll b, double s) : a(a), b(b), s(s) {}

    bool operator<(const line& l) const {
        return s < l.s;
    }
};

vector<line> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    v.emplace_back(b[0], 0, 0);

    for (int i = 1; i < n; i++) {
        line current(0, 0, a[i]);
        line l = *(upper_bound(v.begin(), v.end(), current) - 1);

        d[i] = l.a * a[i] + l.b;

        line nxt(b[i], d[i], 0);
        double crossPoint = 0;

        while (v.size())
        {
            line prv = v.back();
            crossPoint = (double)(prv.b - nxt.b) / (nxt.a - prv.a);
            if (crossPoint <= prv.s) v.pop_back();
            else
                break;
        }
        nxt.s = crossPoint;
        v.push_back(nxt);
    }

    cout << d[n - 1];

    return 0;
}
------------------------------
*/

/* //

------------------------------
*/

#pragma endregion
