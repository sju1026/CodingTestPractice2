#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {

    return 0;
}

// 문제별 순서대로
#pragma region 문제 풀이
#pragma region arithmetic / condition 
/*int a, b;
cin >> a;
cin >> b;
printf("%.9f\n", (double)a / b);
---------------------------------
int a, b;
cin >> a;
cin >> b;

cout << a + b << endl;
cout << a - b << endl;
cout << a * b << endl;
cout << a / b << endl;
cout << a % b << endl;
-------------------------------
string id;
cin >> id;

id += "??!";
cout << id;
--------------------------------
int a;
int b;
int c;

cin >> a;
cin >> b;
cin >> c;

cout << (a + b) % c << endl;
cout << ((a % c) + (b % c)) % c << endl;
cout << (a * b) % c << endl;
cout << ((a % c) * (b % c)) % c << endl;
--------------------------------
cout << a * (b % 10) << endl;
cout << a * (b % 100 / 10) << endl;
cout << a * (b / 100) << endl;
cout << a * b << endl;
--------------------------------
long a,b,c;

cin >> a >> b >> c;

cout << a + b + c << endl;
--------------------------------
cout << "\\    /\\" << endl;
cout << " )  ( ')" << endl;
cout << "(  /  )" << endl;
cout << " \\(__)|" << endl;
--------------------------------
cout << "|\\_/|" << endl;
cout << "|q p|   /}" << endl;
cout << "( 0 )\"\"\"\\" << endl;
cout << "|\"^\"`    |" << endl;
cout << "||_/=\\\\__|" << endl;
--------------------------------
int a;

cin >> a ;

if (a <= 100 && a >= 90)
    cout << "A";
else if (a < 90 && a >= 80)
    cout << "B";
else if (a < 80 && a >= 70)
    cout << "C";
else if (a < 70 && a >= 60)
    cout << "D";
else
    cout << "F";
--------------------------------
if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
    cout << 1 << endl;
else
    cout << 0 << endl;
--------------------------------
if (a > 0 && b > 0)
    cout << 1;
else if (a < 0 && b > 0)
    cout << 2;
else if (a < 0 && b < 0)
    cout << 3;
else if (a > 0 && b < 0)
    cout << 4;
--------------------------------
int totalMin = 60 * a + b;
totalMin += c;

int h = (totalMin / 60) % 24;
int m = totalMin % 60;

cout << h << " " << m << endl;
--------------------------------
if (a != b && b != c && a != c) {
    int max;
    if (a > b) {
        if (c > a)
            max = c;
        else
            max = a;
    }
    else {
        if (c > b)
            max = c;
        else
            max = b;
    }
    cout << max * 100;
}
else {
    if (a == b && a == c)
        cout << 10000 + a * 1000;
    else {
        if (a == b || a == c)
            cout << 1000 + a * 100;
        else
            cout << 1000 + b * 100;
    }
}*/
#pragma endregion

#pragma region Repeat
/*--------------------------------
for (int i = 1; i < 10; i++) {
    cout << ("%d", n) << " * " << ("%d", i) << " = " << (n * i) << endl;
}
--------------------------------
int n, a, b;
cin >> n;

for (int i = 0; i < n; i++) {
    cin >> a >> b;
    cout << a + b << "\n";
}
--------------------------------
int n;
int sum = 0;
cin >> n;

for (int i = 1; i < n + 1; i++) {
    sum += i;
}
cout << sum << endl;
--------------------------------
int n, a, b;
    int sum;
    int ssum = 0;
    cin >> sum;
    cin >> n;

    for (int i = 1; i < n + 1; i++) {
        cin >> a >> b;
        ssum += a * b;
    }
    if (sum == ssum)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
--------------------------------
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n, a, b;
cin >> n;

for (int i = 1; i < n + 1; i++) {
    cin >> a >> b;
    cout << "Case #" << i << ": " << a + b << "\n";
}
--------------------------------
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n;

    for (int i = 1; i < n + 1; i++) {
        cin >> a >> b;
        cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n";
    }
--------------------------------
int n;
cin >> n;

for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < n - i; j++)
        cout << " ";
    for (int j = 0; j < i; j++)
        cout << "*";
    cout << "\n";
}
--------------------------------
int a, b;

while (true) {
    cin >> a >> b;
    cout << a + b << "\n";
}
--------------------------------
int a, b;

while (!(cin >> a >> b).fail()) {
    cout << a + b << "\n";
}
*/
#pragma endregion

#pragma region array
/*
int n, x;
int arr[101];

cin >> n;

for (int i = 0; i < n; i++)
    cin >> arr[i];
cin >> x;

int count = 0;

for (int i = 0; i < n; i++)
{
    if (arr[i] == x)
        count++;
}
cout << count;
--------------------------------
int n, x;

cin >> n >> x;

int arr[10000];

for (int i = 0; i < n; i++)
    cin >> arr[i];

for (int i = 0; i < n; i++)
{
    if (arr[i] < x)
        cout << arr[i] << " ";
}
--------------------------------
ios_base::sync_with_stdio(0);

int n;
cin >> n;

int arr[1000001];

for (int i = 0; i < n; i++)
    cin >> arr[i];

int min = 0;
int max = 0;

for (int i = 0; i < n; i++)
{
    if (arr[i] < arr[i + 1])
        max = arr[i + 1];

    else if (arr[i] > arr[i + 1])
        min = arr[i];
}
cout << min << " " << max;

return 0;
--------------------------------
ios_base::sync_with_stdio(0);

int n;
cin >> n;

int min = 1000001;
int max = -1000001;

int input;

for (int i = 0; i < n; i++) {
    cin >> input;

    if (input < min)
        min = input;
    if (input > max)
        max = input;
}

cout << min << " " << max;

return 0;
--------------------------------
ios_base::sync_with_stdio(0);

int max = -1;
int index = 0;
int arr[9];

for (int i = 0; i < 9; i++)
    cin >> arr[i];

for (int i = 0; i < 9; i++)
{
    if (arr[i] > max) {
        max = arr[i];
        index = i;
    }
}
cout << max << "\n" << index + 1;

return 0;
--------------------------------
ios_base::sync_with_stdio(0);

int n, m;
int arr[101] = { 0, };
int a, b, c;

cin >> n >> m;

for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    for (int k = a; k <= b; k++)
        arr[k] = c;
}
for (int i = 1; i <= n; i++)
    cout << arr[i] << ' ';

return 0;
--------------------------------
ios_base::sync_with_stdio(0);

int arr[100];

int a, b, c, d, temp;
cin >> a >> b;

for (int i = 0; i < a; i++)
    arr[i] = i + 1;
for (int i = 0; i < b; i++)
{
    cin >> c >> d;
    temp = arr[c - 1];
    arr[c - 1] = arr[d - 1];
    arr[d - 1] = temp;
}
for (int i = 0; i < a; i++)
    cout << arr[i] << " ";

return 0;
--------------------------------
ios_base::sync_with_stdio(0);

int arr[31] = { 0, };
int a;

for (int i = 0; i < 28; i++)
{
    cin >> a;
    arr[a] = 1;
}

for (int i = 1; i < 30 + 1; i++)
{
    if (!arr[i])
    {
        cout << i << "\n";
    }
}
--------------------------------
int count[42] = {};

int v;

for (int i = 0; i < 10; i++)
{
    cin >> v;
    count[v % 42]++;
}

int result = 0;

for (int v : count) {
    if (v > 0)
        result++;
}
cout << result;
--------------------------------
int n;

cin >> n;
int arr[1000] = { };
int max = -1;
double result = 0;

for (int i = 0; i < n; i++)
{
    cin >> arr[i];
    if (arr[i] > max)
        max = arr[i];
    result += arr[i];
}
result = (result / max * 100) / n;
cout << result << "\n";
--------------------------------
*/
#pragma endregion

#pragma region String
/*
string s;
int i;

cin >> s >> i;

cout << s[i - 1];
--------------------------------
string s;

cin >> s;

cout << s.length();
--------------------------------
string s;
int num;

cin >> num;

for (int i = 0; i < num; i++)
{
cin >> s;
int index = s.length();
cout << s[0] << s[index - 1] << "\n";
}
--------------------------------
char s;

cin >> s;
cout << int(s);
--------------------------------
int count;
char ch;

cin >> count;

int sum = 0;

for (int i = 0; i < count; i++)
{
    cin >> ch;
    sum += ch - 48;
}
cout << sum;
--------------------------------
int arr[26] = { 0, };

string s;

cin >> s;

for (char i = 'a'; i < 'z'+1; i++)
{
    cout << (int)s.find(i) << " ";
}
--------------------------------
int t;
cin >> t;
for (int i = 0; i < t; i++)
{
    int r;
    string p;
    cin >> r;
    cin >> p;

    for (int j = 0; j < p.length(); j++)
    {
        for (int k = 0; k < r; k++)
        {
            cout << p[j];
        }
    }
    cout << "\n";
}
--------------------------------
string s;
int count = 1;

getline(cin, s);

if (s.length() == 1 && s[0] == ' ') {
    cout << 0;
    return 0;
}

for (int i = 1; i < s.length() - 1; i++)
{
    if (s[i] == ' ')
        count++;
}

cout << count;
--------------------------------
string a, b;
cin >> a >> b;

string bigger;

for (int i = 2; i >= 0; i--) {
    if (a[i] > b[i]) {
        bigger = a;
        break;
    }
    else if (a[i] < b[i]) {
        bigger = b;
        break;
    }
}

cout << bigger[2] << bigger[1] << bigger[0];
--------------------------------
int timer = 0;
string s;

cin >> s;

for (int i = 0; i < s.size(); i++) {
    timer += ((int)s[i] - 65) / 3 + 3;

    if (s[i] == 'S' || s[i] == 'V' || s[i] == 'Y' || s[i] == 'Z')
        timer--;
}

cout << timer;
--------------------------------

*/
#pragma endregion

#pragma region Hard
/*
cout << "         ,r'\"7" << "\n";
cout << "r`-_   ,'  ,/" << "\n";
cout << " \\. \". L_r\'" << "\n";
cout << "   `~\\/" << "\n";
cout << "      |" << "\n";
cout << "      |" << "\n";
--------------------------------
int king = 1;
int queen = 1;
int rook = 2;
int bishop = 2;
int knight = 2;
int pawn = 8;

int _king, _queen, _rook, _bishop, _knight, _pawn;

cin >> _king;
cin >> _queen;
cin >> _rook;
cin >> _bishop;
cin >> _knight;
cin >> _pawn;

cout << king - _king << " ";
cout << queen - _queen << " ";
cout << rook - _rook << " ";
cout << bishop - _bishop << " ";
cout << knight - _knight << " ";
cout << pawn - _pawn;
--------------------------------
int num;

cin >> num;

for (int i = 1; i <= num ; i++)
{
for (int j = 0; j < num - i; j++)
    cout << " ";
for (int k = 0; k < 2 * i - 1; k++)
    cout << "*";
cout << "\n";
}

for (int i = 1; i < num; i++)
{
for (int j = 0; j < i; j++)
    cout << " ";
for (int k = 0; k < 2 * num - (2 * i + 1); k++)
    cout << "*";
cout << "\n";
}
--------------------------------
string name;
cin >> name;

int len = name.length();

int cnt = 0;

for (int i = 0; i < len / 2; i++) {
    if (name[i] != name[name.length() - 1 - i]) {
        cout << '0' << "\n";
        return 0;
    }
}
cout << "1";
--------------------------------
int cnt[26] = { 0, };
int max = -1;
char res;

string s;

cin >> s;

for (int i = 0; i < s.length(); i++)
{
    if (s[i] >= 'a' && s[i] <= 'z')
        s[i] = s[i] - 'a' + 'A';

    if (++cnt[s[i] - 'A'] > max)
    {
        max = cnt[s[i] - 'A'];
        res = s[i];
    }
}

int check = 0;

for (int i = 0; i < 26; i++)
    if (max == cnt[i])
        check++;

if (check == 1) cout << res;
else cout << "?";
--------------------------------

--------------------------------
int num;
string word;
int count = 0;

cin >> num;
for (int i = 0; i < num; i++)
{
    cin >> word;

    bool alphabet[26] = { false, };
    alphabet[(int)(word[0]) - 97] = true;

    for (int i = 1; i < word.size(); i++)
    {
        if (word[i] == word[i - 1])
        {
            continue;
        }

        else if (word[i] != word[i - 1] && alphabet[(int)(word[i]) - 97] == true)
        {
            count++;
            break;
        }

        else
            alphabet[(int)(word[i]) - 97] = true;
    }
}
cout << num - count;
--------------------------------
string name;
double avg = 0;
float sumGrade = 0;
double score[20];
float grade[20];
string input;

for (int i = 0; i < 20; i++)
{
    cin >> name >> grade[i] >> input;
    if (input == "A+")
        score[i] = 4.5;
    else if (input == "A0")
        score[i] = 4.0;
    else if (input == "B+")
        score[i] = 3.5;
    else if (input == "B0")
        score[i] = 3.0;
    else if (input == "C+")
        score[i] = 2.5;
    else if (input == "C0")
        score[i] = 2.0;
    else if (input == "D+")
        score[i] = 1.5;
    else if (input == "D0")
        score[i] = 1.0;
    else if (input == "F")
        score[i] = 0.0;
    else if (input == "P") {
        score[i] = 0.0;
        grade[i] = 0;
    }

    avg += (score[i] * grade[i]);
    sumGrade += grade[i];
}

avg = avg / sumGrade;
cout << avg;
--------------------------------
*/
#pragma endregion

#pragma region Matrix
/*
int row, column;
int a[101][101], b[101][101];

cin >> row >> column;
for (int i = 1; i <= row; i++)
{
    for (int j = 1; j <= column; j++)
        cin >> a[i][j];
}

for (int i = 1; i <= row; i++)
{
    for (int j = 1; j <= column; j++)
        cin >> b[i][j];
}

for (int i = 1; i <= row; i++)
{
    for (int j = 1; j <= column; j++)
        cout << a[i][j] + b[i][j] << ' ';
    cout << "\n";
}
--------------------------------
int a, x, y;
int max = -1;

for (int i = 1; i <= 9; i++)
{
    for (int k = 1; k <= 9; k++)
    {
        cin >> a;

        if (max <= a) {
            max = a;
            x = i;
            y = k;
        }
    }
}

cout << max << "\n";
cout << x << ' ' << y;
--------------------------------
string word[5];

for (int i = 0; i < 5; i++)
    cin >> word[i];

for (int i = 0; i < 15; i++)
{
    for (int j = 0; j < 5; j++)
    {
        if (i < word[j].size())
        {
            cout << word[j][i];
        }
    }
}
cout << endl;
--------------------------------
int a[100][100] = { 0 };

int n, x, y, cnt = 0;
cin >> n;

while (n--)
{
    cin >> x >> y;
    for (int i = y; i < y + 10; i++) {
        for (int j = x; j < x + 10; j++) {
            if (a[i][j])
                continue;
            a[i][j] = 1;
            cnt++;
        }
    }
}

cout << cnt;
--------------------------------
*/
#pragma endregion

#pragma region Basic Math
/*
int b;
int res = 0;
string n;
cin >> n >> b;

for (int i = 0; i < n.length(); i++)
{
if ('0' <= n[i] && n[i] <= '9')
{
    res = res * b + (n[i] - '0');
}
else
    res = res * b + (n[i] - 'A' + 10);
}

cout << res;
--------------------------------
int n, b;
cin >> n >> b;

string result = " ";

while (n > 0)
{
    int r = n % b;

    if (r < 10)
        result += (char)(r + '0');
    else
        result += (char)(r - 10 + 'A');

    n /= b;
}
reverse(result.begin(), result.end());

cout << result;
--------------------------------
int qua, dim, nic, pen;
int cnt;

cin >> cnt;
int* num = new int[cnt];

for (int i = 0; i < cnt; i++)
{
    cin >> num[i];
    qua = num[i] / 25;
    pen = num[i] % 25;
    dim = pen / 10;
    pen %= 10;
    nic = pen / 5;
    pen %= 5;

    cout << qua << " " << dim << " " << nic << " " << pen << "\n";

}
--------------------------------
int num;

cin >> num;

int i = 0;

for (int sum = 2; sum <= num; i++)
    sum += 6 * i;

if (num == 1)
    i = 1;

cout << i;
--------------------------------
int v, a, b;

    cin >> a >> b >> v;

    int day = 1;

    day += (v - a) / (a - b);
    if ((v-a)%(a-b) != 0)
        day++;
    if (a >= v)
        cout << "1";
    else
        cout << day;
--------------------------------
*/
#pragma endregion

#pragma region Multiple
/*
int a, b;

while (true)
{
cin >> a >> b;

if (a == 0 && b == 0)
{
    break;
}

if (b % a == 0)
{
    cout << "factor" << "\n";
}
else if (a % b == 0)
{
    cout << "multiple" << "\n";
}
else
{
    cout << "neither" << "\n";
}
}
--------------------------------
int arr[10000] = { 10000 }, N, K, cnt = 0, p = 0;
cin >> N >> K;
for (int i = 1; i < 10000; i++)
{
    if (i > N)
        break;
    if (N % i == 0)//약수라면
    {
        cnt++;
        arr[p++] = i;
    }
}
if (cnt < K)
    cout << "0";
else
    cout << arr[K - 1];
--------------------------------
int n = 0;
while (1)
{
vector<int>measure;
int sum = 0;
int n;
cin >> n;
if (n == -1)
    break;
for (int i = 1; i < n; i++)
    if (n % i == 0)
        measure.push_back(i);
for (int i = 0; i < measure.size(); i++)
    sum += measure[i];
if (n == sum)
{
    cout << n << " = ";
    for (int i = 0; i < measure.size(); i++)
    {
        if (i == measure.size() - 1)
            cout << measure[i];
        else
            cout << measure[i] << " + ";
    }
    cout << '\n';
}
else
    cout << n << " is NOT perfect.\n";
}
--------------------------------
int n, result = 0;

cin >> n;

int temp, cnt = 0;

for (int i = 0; i < n; i++)
{
cin >> temp;
for (int div = 1; div <= temp; div++)
{
    if (temp % div == 0)
        cnt++;
}
if (cnt == 2)
    result++;
cnt = 0;
}
cout << result << "\n";
--------------------------------
int m, n;
int sum = 0, min = -1, cnt = 0;
cin >> m >> n;

for (int i = m; i <= n; i++)
{
    for (int div = 1; div <= i; div++)
    {
        if (i % div == 0)
            cnt++;
    }
    if (cnt == 2)
    {
        if (min == -1)
            min = i;
        sum += i;
    }
    cnt = 0;
}
if (min == -1)
    cout << -1 << "\n";
else
    cout << sum << "\n" << min << '\n';
--------------------------------
int N;
cin >> N;

if (N == 1) return 0;

for (int i = 2; i <= N; i++) {
    while (N % i == 0) {
        cout << i << endl;
        N /= i;
    }
}
--------------------------------
#include <iostream>
#include <cmath>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void cantor(int n) {
    int size = pow(3, n - 1);

    if(n == 0) {
        cout << "-";
        return;
    }

    cantor(n - 1);
    for (int i = 0; i < size; i++)
    {
        cout << " ";
    }
    cantor(n - 1);
}

int main() {
    int n;

    while (cin >> n)
    {
        cantor(n);
        cout << "\n";
    }

    return 0;
}
--------------------------------
#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void star(int i, int j, int n) {
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
        cout << ' ';
    }
    else
    {
        if (n / 3 == 0)
            cout << "*";
        else
            star(i, j, n / 3);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            star(i, j, n);
        cout << '\n';
    }

    return 0;
}
--------------------------------
*/
#pragma endregion

#pragma region .
/*
int a, b;
cin >> a >> b;

cout << a * b;
--------------------------------
int x, y, w, h;
int tmp1, tmp2;

cin >> x >> y >> w >> h;

tmp1 = min(x, y);
tmp2 = min(w - x, h - y);
cout << min(tmp1, tmp2);
--------------------------------
int x[3];
int y[3];
for (int i = 0; i < 3; i++)
    cin >> x[i] >> y[i];
if (x[0] == x[1])
    cout << x[2] << " ";
else if (x[0] == x[2])
    cout << x[1] << " ";
else
    cout << x[0] << " ";

if (y[0] == y[1])
    cout << y[2];
else if (y[0] == y[2])
    cout << y[1];
else
    cout << y[0];
--------------------------------
long n;
cin >> n;
cout << n * 4 << endl;
--------------------------------
int n;
cin >> n;

int* x = new int[n];
int* y = new int[n];

for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];

sort(x, x + n);
sort(y, y + n);

cout << (x[n - 1] - x[0]) * (y[n - 1] - y[0]);
--------------------------------
int a, b, c;
cin >> a >> b >> c;
if (a + b + c == 180)
{
    if (a == b && a == c && b == c)
        cout << "Equilateral";
    else if (a == b || a == c || b == c)
        cout << "Isosceles";
    else
        cout << "Scalene";
}
else
    cout << "Error";
--------------------------------
int triangle[3];

while (1)
{
    for (int i = 0; i < 3; i++)
    {
        cin >> triangle[i];
    }
    if (triangle[0] == 0 && triangle[0] == triangle[1] && triangle[0] == triangle[2])
    {
        break;
    }
    sort(triangle, triangle + 3);
    if (triangle[2] >= triangle[1] + triangle[0])
    {
        cout << "Invalid" << '\n';
    }
    else if (triangle[0] != triangle[1] && triangle[1] != triangle[2] && triangle[0] != triangle[2])
    {
        cout << "Scalene" << '\n';
    }
    else
    {
        if (triangle[0] == triangle[1] && triangle[1] == triangle[2])
        {
            cout << "Equilateral" << '\n';
        }
        else
            cout << "Isosceles" << '\n';
    }
}
--------------------------------
int a[3];

cin >> a[0] >> a[1] >> a[2];
sort(a, a + 3);
if (a[0] + a[1] > a[2]) cout << a[0] + a[1] + a[2];
else cout << (a[0] + a[1]) * 2 - 1;
*/
#pragma endregion

#pragma region Algorithm Run Time
/*
--------------------------------
int n;

cin >> n;
cout << n << "\n" << 1 << "\n";
--------------------------------
long n;

cin >> n;
cout << n * n << "\n" << 2;
--------------------------------
long n;
cin >> n;

cout << (n * (n - 1)) / 2 << "\n" << 2;
--------------------------------
long n;
cin >> n;

cout << n * n * n << "\n" << 3;
--------------------------------
long n;
cin >> n;

cout << (n * ((n - 1) * (n - 2))) / 6 << "\n" << 3;
-------------------------------- // Big O
int a, b, c, n;
cin >> a >> b;
cin >> c;
cin >> n;

if (a * n + b <= c * n && a <= c)
{
    cout << 1;
}
else
    cout << 0;
--------------------------------
*/
#pragma endregion

#pragma region BruteForce
/*
int n, m, result = 0;
    int arr[101] = {};
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] <= m && arr[i] + arr[j] + arr[k] > result)
                    result = arr[i] + arr[j] + arr[k];
            }
        }
    }
    cout << result;
--------------------------------
int n, result = 0;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int sum = 0;
        int num = i;
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        if (sum + i == n)
        {
            result = i;
            break;
        }
    }

    cout << result;
--------------------------------
int a, b, c, d, e, f;
    int x, y;

    cin >> a >> b >> c >> d >> e >> f;

    y = (c * d - a * f) / (b * d - a * e);
    x = (c * e - b * f) / (a * e - b * d);

    cout << x << " " << y;
--------------------------------
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string board[50];
int WB_cnt(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[x + i][y + j] != WB[i][j])
                cnt++;
        }
    }

    return cnt;
}
int BW_cnt(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[x + i][y + j] != BW[i][j])
                cnt++;
        }
    }

    return cnt;
}
int main() {
    int size[2];
    int cnt;
    int min_val = 12345;
    pair<int, int> p1;

    cin >> p1.first >> p1.second;
    for (int i = 0; i < p1.first; i++)
        cin >> board[i];

    for (int i = 0; i + 8 <= p1.first; i++)
    {
        for (int j = 0; j + 8 <= p1.second; j++)
        {
            int tmp;
            tmp = min(WB_cnt(i, j), BW_cnt(i, j));
            if (tmp < min_val) {
                min_val = tmp;
            }
        }
    }
    cout << min_val;

    return 0;
}
--------------------------------
#include <iostream>
#include <string>

using namespace std;

int FindSeries(int n) {
    int i = 666;
    int series = 0;
    string target;
    while (1)
    {
        target = to_string(i);
        for (int j = 0; j < target.length() - 2; j++)
        {
            if (target[j] == '6' && target[j+1] == '6' && target[j+2] == '6')
            {
                series++;
                if (series == n)
                    return i;
                break;
            }
        }
        i++;
    }
}

int main() {
    int n;
    cin >> n;
    cout << FindSeries(n);
}
--------------------------------
int n;
    int cnt = 0;
    cin >> n;
    while (n >= 0)
    {
        if (n % 5 == 0)
        {
            cnt += (n / 5);
            cout << cnt;
            return 0;
        }
        n -= 3;
        cnt++;
    }
    cout << -1;
--------------------------------
*/
#pragma endregion

#pragma region 정렬
/*
int t, tmp;
cin >> t;

int arr[1001];

for (int i = 0; i < t; i++)
{
    cin >> arr[i];
}

for (int j = 0; j < t - 1; j++)
{
    for (int k = j + 1; k < t; k++)
    {
        if (arr[j] > arr[k])
        {
            tmp = arr[k];
            arr[k] = arr[j];
            arr[j] = tmp;
        }
    }
}

for (int i = 0; i < t; i++)
{
    if (i + 1 < t && arr[i] == arr[i + 1])
        continue;
    cout << arr[i] << "\n";
}
--------------------------------
int sum = 0;
int arr[5];

for (int i = 0; i < 5; i++)
{
    cin >> arr[i];
    sum += arr[i];
}

for (int i = 0; i < 4; i++)
    for (int j = i+1; j < 5; j++)
        if (arr[i] > arr[j])
        {
            int p = arr[i];
            arr[i] = arr[j];
            arr[j] = p;
        }

cout << sum / 5 << "\n" << arr[2];
--------------------------------
#include <algorithm>

int n, k;
int arr[1001];

cin >> n >> k;
for (int i = 0; i < n; i++)
    cin >> arr[i];

sort(arr, arr + n);

cout << arr[n - k];
--------------------------------
ios::sync_with_stdio(false);

int n;
cin >> n;
int* arr = new int[n];

for (int i = 0; i < n; i++)
    cin >> arr[i];

sort(arr, arr + n);

for (int i = 0; i < n; i++)
{
    cout << arr[i] << "\n";
}
--------------------------------
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int N;
cin >> N;

int arr[10001] = { 0 };

for (int i = 0; i < N; i++) {
    int in;
    cin >> in;
    arr[in] += 1;
}

for (int i = 1; i < 10001; i++) {
    for (int j = 0; j < arr[i]; j++) {
        cout << i << '\n';
    }
}
--------------------------------
#include<algorithm>

string str;
cin >> str;
sort(str.begin(), str.end(), greater<char>());
cout << str;
--------------------------------
#include <iostream>
#include <algorithm>

using namespace std;

class coordinate {
public:
    int x;
    int y;
};

bool cmp(coordinate a, coordinate b) {
    if (a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}

coordinate* c = new coordinate[100000];

int main() {

    int n;
    int numx, numy;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> c[i].x >> c[i].y;

    stable_sort(c, c + n, cmp);

    for (int i = 0; i < n; i++)
        cout << c[i].x << " " << c[i].y << "\n";
 }
--------------------------------
class coordinate {
public:
    int x;
    int y;
};

bool cmp(coordinate a, coordinate b) {
    if (a.y == b.y)
        return a.x < b.x;
    else
        return a.y < b.y;
}

coordinate* c = new coordinate[100000];

int main() {

    int n;
    int numx, numy;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> c[i].x >> c[i].y;

    stable_sort(c, c + n, cmp);

    for (int i = 0; i < n; i++)
        cout << c[i].x << " " << c[i].y << "\n";
 }
--------------------------------
int cmp(string a, string b) {
    if (a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

string word[200000];

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> word[i];

    sort(word, word + n, cmp);

    for (int i = 0; i < n; i++)
    {
        if (word[i] == word[i-1])
            continue;
        cout << word[i] << "\n";
    }
 }
--------------------------------
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    pair<int, string>tmp;
    vector<pair<int, string>> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }
    stable_sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
 }
--------------------------------
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> cv(v);
    sort(cv.begin(), cv.end());

    cv.erase(unique(cv.begin(), cv.end()), cv.end());

    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(cv.begin(), cv.end(), v[i]);
        cout << it - cv.begin() << ' ';
    }
 }
*/
#pragma endregion

#pragma region 집합
/*
int len, temp;
vector<int> v;
cin >> len;

while (len--)
{
    cin >> temp;
    v.push_back(temp);
}

sort(v.begin(), v.end());
cin >> len;
while (len--)
{
    cin >> temp;
    cout << binary_search(v.begin(), v.end(), temp) << " ";
}
--------------------------------
int n, m;
cin >> n >> m;
vector<string>v1(n);
vector<string>result;
for (int i = 0; i < n; i++)
    cin >> v1[i];

sort(v1.begin(), v1.end());

string mm;
int count = 0;
for (int i = 0; i < m; i++)
{
    cin >> mm;
    if (binary_search(v1.begin(), v1.end(), mm))
        count++;
}

cout << count;
--------------------------------
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string>s;
    int n;
    cin >> n;

    while (n--)
    {
        string tmp1;
        string tmp2;

        cin >> tmp1 >> tmp2;

        if (tmp2 == "enter")
            s.insert(tmp1);
        else
            s.erase(tmp1);
    }

    for (auto it = s.rbegin(); it != s.rend(); it++)
        cout << *it << "\n";
 }
--------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int N, M;
string name[100001];

map<string, int>m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        name[i] = s;
        m.insert(make_pair(s, i));
    }

    for (int i = 1; i <= M; i++)
    {
        string s;
        int n;
        cin >> s;
        if (isdigit(s[0]) == true)
        {
            n = stoi(s);
            cout << name[n] << "\n";
        }
        else
        {
            auto it = m.find(s);
            cout << it->second << "\n";
        }
    }
}
--------------------------------
int N, M, x;
cin >> N;
map<int, int> arr;
for (int i = 0; i < N; i++) {
    cin >> x;
    arr[x]++;
}

cin >> M;
for (int i = 0; i < M; i++) {
    cin >> x;
    cout << arr[x] << " ";
}
--------------------------------
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    string str1 = "";
    unordered_map<string, int> umap;
    vector<string> ansVec;
    for (int i = 0; i < N; i++) {
        cin >> str1;
        umap[str1] = 0;
    }
    string str2 = "";
    for (int i = 0; i < M; i++) {
        cin >> str2;
        if (umap.find(str2) != umap.end()) {    //보도 못한 사람이 듣도 못한 사람 명단에도 있으면
            ansVec.push_back(str2);
        }
    }

    sort(ansVec.begin(), ansVec.end());
    cout << ansVec.size() << "\n";
    for (int i = 0; i < ansVec.size(); i++) {
        cout << ansVec[i] << "\n";
    }
}
--------------------------------
#include <iostream>
#include <map>

using namespace std;

map<int, bool> m;
int N, M;
int num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N + M; i++)
    {
        cin >> num;
        if (m[num] == true)
            m.erase(num);
        else
            m[num] = true;
    }
    cout << m.size();
}
--------------------------------
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    set<string> set;

    string str = "";
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            str += s[j];
            set.insert(str);
        }
        str = "";
    }

    cout << set.size();
}
*/
#pragma endregion

#pragma region 약수, 배수와 소수
/*
int Divide(int x, int y) {
    if (x % y == 0)
        return y;
    else
        return Divide(y, x % y);
}

int main() {

    int t;
    int a, b;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        if (a >= b)
            cout << a * b / Divide(a, b) << "\n";
        else
            cout << a * b / Divide(b, a) << "\n";
    }
}
---------------------------------
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

long long Gcd(int a, int b) {
    int temp;
    if (a < b)
        Swap(a, b);
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long Lcm(long long a, long long b) {
    return (a * b) / Gcd(a, b);
}

int main() {

    long long a, b;
    cin >> a >> b;
    cout << Lcm(a, b);
}
---------------------------------
long Gcd(long a, long b) {
    if (b > a)
        return Gcd(b, a);
    if (a % b == 0)
        return b;
    else
        return Gcd(b, a % b);
}

int main() {

    long up, down, up1, down1, n, m;

    cin >> up >> down >> up1 >> down1;
    n = down1 * up + up1 * down;
    m = down1 * down;

    cout << n / Gcd(n, m) << " " << m / Gcd(n, m);
}
---------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Gcd(int a, int b) {
    if (a % b == 0)
        return b;
    return Gcd(b, a % b);
}

int main() {

    ios_base::sync_with_stdio(false);

    long n;
    cin >> n;

    vector<long>vec;
    vec.resize(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    int temp = vec[1] - vec[0];
    for (int i = 1; i < n-1; i++)
    {
        int next = vec[i + 1] - vec[i];
        if (next > temp)
        {
            int swap_num = next;
            next = temp;
            temp = swap_num;
        }
        temp = Gcd(temp, next);
    }

    int answer = ((vec[n - 1] - vec[0]) / temp) - n + 1;
    cout << answer << "\n";

    return 0;
}
---------------------------------
bool isPrime(long long num)
{
    if (num <= 1)
        return false;

    if (num == 2 || num == 3)
        return true;

    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (long long i = 5; i * i <= num; ++i)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }

    return true;
}

int main() {

    ios_base::sync_with_stdio(false);

    long long N, n;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> n;
        while (!isPrime(n))
            n++;
        cout << n << endl;
    }

    return 0;
}
---------------------------------
#include <iostream>

using namespace std;

#define MAX 1000000

int arr[MAX + 1]{ 0, };

int main() {

    ios_base::sync_with_stdio(false);

    int m, n;
    cin >> m >> n;

    for (int i = 2; i <= n; i++)
        arr[i] = i;

    for (int i = 2; i*i <= n; i++)
    {
        if (arr[i] == 0)
            continue;
        for (int j = i * i; j <= n; j += i)
            arr[j] = 0;
    }

    for (int i = m; i <= n; i++)
    {
        if (arr[i] != 0)
            cout << arr[i] << '\n';
    }

    return 0;
}
---------------------------------
int n, m, cnt = 0;

while (1) {
    cin >> n;
    if (!n)	//0 입력시 종료
        break;

    for (int i = n + 1; i <= 2 * n; i++) {
        m = sqrt(i);
        if (m == 1 && i != 1) {	//2,3인 경우
            cnt++;
            continue;
        }
        if (i % 2) {	//홀수일 경우
            for (int j = 2; j <= m; j++) {
                if (!(i % j))
                    break;
                if (j == m) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
    cnt = 0;
}
---------------------------------
#define N 1000001

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    bool arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = true;
    }
    arr[0] = arr[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (arr[i]) {
            for (int j = i * 2; j <= N; j += i) {
                arr[j] = false;
            }
        }
    }

    while (t--) {
        int result = 0;
        int n;
        cin >> n;

        for (int i = 0; i <= n / 2; i++) {
            int a = i;
            int b = n - i;

            if (arr[a] && arr[b]) {
                result++;
            }
        }

        cout << result << '\n';
    }

    return 0;
}
---------------------------------
int n, i = 1;

cin >> n;
while (i * i <= n)
{
    i++;
}
cout << i - 1 << "\n";
---------------------------------
*/
#pragma endregion

#pragma region 스택, 큐, 덱
/*
int N;
cin >> N;

stack<int> S;

int order;
while (N--) {
    cin >> order;
    switch (order) {
    case 1:
        int num;
        cin >> num;
        S.push(num);
        break;
    case 2:
        if (!S.empty()) {
            cout << S.top() << '\n';
            S.pop();
        }
        else {
            cout << -1 << '\n';
        }
        break;
    case 3:
        cout << S.size() << '\n';
        break;
    case 4:
        if (!S.empty()) {
            cout << 0 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
        break;
    case 5:
        if (!S.empty()) {
            cout << S.top() << '\n';
        }
        else {
            cout << -1 << '\n';
        }
        break;
    }
}
----------------------------
stack<int> s;
int K;
int num;
int stack_size;
int sum = 0;

cin >> K;	// 입력받을 정수의 개수

for (int i = 0; i < K; i++) {
    cin >> num;
    if (num == 0) {
        s.pop();
    }
    else
        s.push(num);
}

stack_size = s.size();
for (int i = 0; i < stack_size; i++) {
    sum += s.top();
    s.pop();
}

cout << sum;
----------------------------
int k;
cin >> k;

while (k > 0) {
    k--;
    string input;
    cin >> input;

    stack<char> st;
    string answer = "YES";
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            st.push(input[i]);
        }
        else if (!st.empty() && input[i] == ')' && st.top() == '(') {
            st.pop();
        }
        else {
            answer = "NO";
            break;
        }
    }

    if (!st.empty())
        answer = "NO";

    cout << answer << endl;
}
----------------------------
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        string str;
        getline(cin, str);
        stack<char>s;
        bool ans = true;
        if (str.length() == 1 && str[0] == '.')
            break;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(' || str[i] == '[')
            {
                s.push(str[i]);
            }
            if (str[i] == ')')
            {
                if (s.empty() || s.top() == '[')
                    ans = false;
                else
                    s.pop();
            }
            if (str[i] == ']')
            {
                if (s.empty() || s.top() == '(')
                    ans = false;
                else
                    s.pop();
            }
        }
        if (s.empty() && ans)
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }

    return 0;
}
----------------------------
int n, num = 1, cnt = 0;
cin >> n;
for (int i = 0; i < n; i++) {
    cin >> arr[i];
}
stack<int> s;
for (int i = 0; i < n; i++) {
    if (s.empty() && cnt < n) {
        s.push(arr[cnt++]);
    }
    while (s.top() != num && cnt < n) {
        s.push(arr[cnt++]);
    }
    if (!s.empty() && s.top() == num) {
        s.pop();
        num++;
    }
    else {
        cout << "Sad" << "\n";
        return 0;
    }
}
cout << "Nice" << "\n";
----------------------------
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> Q;
    string command;
    int t, cnt;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> command;

        if (command == "push") {
            cin >> cnt;
            Q.push(cnt);
        }
        else if (command == "pop") {
            if (Q.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if (command == "front") {
            if (Q.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << Q.front() << '\n';
            }
        }
        else if (command == "back") {
            if (Q.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << Q.back() << '\n';
            }
        }
        else if (command == "size")
            cout << Q.size() << '\n';
        else if (command == "empty")
            cout << Q.empty() << '\n';
        else if (command == "top") {
            if (Q.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << Q.front() << '\n';
            }
        }
    }

    return 0;
}
----------------------------
queue<int> Q;
int N;

cin >> N;

for (int i = 1; i <= N; i++) {
    Q.push(i);
}


while (Q.size() > 1) {
    Q.pop();
    Q.push(Q.front());
    Q.pop();
}

cout << Q.front();
----------------------------
int N, K;
queue<int> q;

cin >> N >> K;
for (int i = 1; i <= N; i++) q.push(i);

cout << "<";

while (q.size() != 0)
{
    for (int i = 1; i < K; i++)
    {
        q.push(q.front()); // i번째 카드를 맨뒤로
        q.pop();
    }
    cout << q.front();
    if (q.size() != 1) cout << ", ";
    q.pop();
}
cout << ">";
----------------------------
deque<int> dq;
int N, cmd, x;

cin >> N;
while (N--)
{
    cin >> cmd;
    switch (cmd)
    {
    case 1:
        cin >> x;
        dq.push_front(x);
        break;
    case 2:
        cin >> x;
        dq.push_back(x);
        break;
    case 3:
        if (dq.empty())
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << dq.front() << "\n";
            dq.pop_front();
        }
        break;
    case 4:
        if (dq.empty())
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << dq.back() << "\n";
            dq.pop_back();
        }
        break;
    case 5:
        cout << dq.size() << "\n";
        break;
    case 6:
        (dq.empty()) ? cout << 1 << "\n" : cout << 0 << "\n";
        break;
    case 7:
        if (dq.empty())
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << dq.front() << "\n";
        }
        break;
    case 8:
        if (dq.empty())
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << dq.back() << "\n";
        }
        break;
    }
}
----------------------------
deque<pair<int, int>> dq;
int N;

cin >> N;
int num;
for (int i = 0; i < N; i++)
{
    cin >> num;
    dq.push_back(make_pair(num, i + 1));
}
while (!dq.empty())
{
    int cur = dq.front().first;
    cout << dq.front().second << " ";
    dq.pop_front();

    if (dq.empty())
        break;

    if (cur > 0)
    {
        for (int i = 0; i < cur - 1; i++)
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
    else
    {
        for (int i = 0; i < (-1) * cur; i++)
        {
            dq.push_front(dq.back());
            dq.pop_back();
        }
    }
}
----------------------------
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

stack <int> st;
queue <int> q;
bool flag[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, input, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> flag[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (flag[i] == 0)
        {
            st.push(input);
        }
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> input;
        q.push(input);
    }
    for (int i = 0; i < m; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
}
----------------------------
*/
#pragma endregion

#pragma region 조합론
/*
int n;
cin >> n;

cout << n*(n - 1);
--------------------------------
int n;
cin >> n;

cout << (1<<n);
--------------------------------
int factorial(int n) {
    if (n > 2)
        n *= factorial(n - 1);
    return n;
}

int main() {

int n, result = 1;
cin >> n;
if (n != 0)
{
    result = factorial(n);
}
cout << result;
--------------------------------
int Factorial(int n) {
    if (n == 0)
        return 1;

    int result = 1;

    for (int i = n; i >= 1; i--)
    {
        result *= i;
    }

    return result;
}

int main() {

int n, k;

cin >> n >> k;
cout << Factorial(n) / (Factorial(k) * Factorial(n - k));
--------------------------------
int t;
cin >> t;

while (t--)
{
    int n, m;
    cin >> n >> m;

    long long ans = 1;

    int r = 1;
    for (int i = m; i > m-n; i--)
    {
        ans *= i;
        ans /= r++;
    }
    cout << ans << "\n";
}
--------------------------------
*/
#pragma endregion

#pragma region Hard2
/*
int n;
cin >> n;
int* div = new int[n];

for (int i = 0; i < n; i++)
{
    cin >> div[i];
}

sort(div, div + n);

cout << div[0] * div[n - 1];
--------------------------------
#include <iostream>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, count = 0;
    cin >> n;
    set<string> m;
    string str;

    while (n--)
    {
        cin >> str;

        if (str == "ENTER")
        {
            count += m.size();
            m.clear();
            continue;
        }
        m.insert(str);
    }

    count += m.size();

    cout << count;
}
--------------------------------
#include <iostream>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, count = 0;

    cin >> n;
    map<string, bool> m;
    string str1, str2;

    while (n--)
    {
        cin >> str1 >> str2;

        if (str1 == "ChongChong")
        {
            m.insert({ str1, true });
        }
        else if (str2 == "ChongChong")
        {
            m.insert({ str2, true });
        }

        if (m[str1])
            m[str2] = true;
        if (m[str2])
            m[str1] = true;
    }
    for (auto& val : m) {
        if (val.second)
            count++;
    }
    cout << count;
}
--------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, tmp, range, middle = 0, most_val, mean = 0;
    int most = -9999;
    int number[8001] = {0,};
    bool not_first = false;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
        mean += tmp;
        number[tmp + 4000]++;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 8001; i++)
    {
        if (number[i] == 0)
            continue;
        if (number[i] == most)
        {
            if (not_first)
            {
                most_val = i - 4000;
                not_first = false;
            }
        }
        if (number[i] > most)
        {
            most = number[i];
            most_val = i - 4000;
            not_first = true;
        }
    }
    middle = arr[arr.size() / 2];
    mean = round((float)mean / n);
    range = arr.back() - arr.front();
    cout << mean << '\n' << middle << '\n' << most_val << '\n' << range;
}
--------------------------------
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

void fast_io(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    if (a.second == b.second)
    {
        if (a.first.length() == b.first.length())
            return a.first < b.first;
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}
int n, m;
unordered_map<string, int> v;

int main() {
    fast_io();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str.length() >= m)
            v[str]++;
    }
    vector<pair<string, int>> vec(v.begin(), v.end());
    sort(vec.begin(), vec.end(), cmp);
    for (auto p : vec)
        cout << p.first << '\n';

}
*/

#pragma endregion

#pragma region 재귀함수
/*
#include <iostream>

using namespace std;

void fast_io(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

long long int fac(int n) {
    if (n <= 1) return 1;
    return n * fac(n - 1);
}

int main() {
    fast_io();

    int n;
    cin >> n;
    cout << fac(n);

}
--------------------------------
#include <iostream>

using namespace std;

void fast_io(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int fibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibo(n - 2) + fibo(n - 1);
}

int main() {
    fast_io();

    int n;
    cin >> n;
    cout << fibo(n);

}
--------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int cnt;

int recursion(const char* s, int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else {
        return recursion(s, l + 1, r - 1);
    }
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int T, pal, i;
    scanf("%d", &T);
    char S[1001];
    for (i = 0; i < T; i++) {
        cnt = 0;
        scanf("%s", &S);
        pal = isPalindrome(S);
        printf("%d %d\n", pal, cnt);
    }
    return 0;
}
--------------------------------
#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int* A;
int* tmp;
int N, cnt = 0, K = 0, result = -1;

void merge(int A[], int p, int q, int r) {
    int i = p, j = q + 1, t = 1;

    while (i <= q && j <= r)
    {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }
    while (i <= q)
        tmp[t++] = A[i++];

    while (j <= r)
        tmp[t++] = A[j++];

    i = p, t = 1;
    while (i <= r)
    {
        A[i++] = tmp[t++];
        cnt++;
        if (cnt == K)
        {
            result = A[i - 1];
            break;
        }
    }
}

void merge_sort(int A[], int p, int r) {
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    cin >> N >> K;
    A = new int[N + 1];
    tmp = new int[N + 1];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    merge_sort(A, 0, N - 1);
    cout << result;
    delete[] A;
    delete[] tmp;
    return 0;
}
--------------------------------
#include <iostream>
#include <cmath>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void cantor(int n) {
    int size = pow(3, n - 1);

    if(n == 0) {
        cout << "-";
        return;
    }

    cantor(n - 1);
    for (int i = 0; i < size; i++)
    {
        cout << " ";
    }
    cantor(n - 1);
}

int main() {
    int n;

    while (cin >> n)
    {
        cantor(n);
        cout << "\n";
    }

    return 0;
}
--------------------------------
#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void star(int i, int j, int n) {
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
        cout << ' ';
    }
    else
    {
        if (n / 3 == 0)
            cout << "*";
        else
            star(i, j, n / 3);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            star(i, j, n);
        cout << '\n';
    }

    return 0;
}
--------------------------------
#include <iostream>
#include <cmath>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void hanoi(int start, int mid, int end, int n) {
    if (n == 1)
        cout << start << " " << end << "\n";
    else
    {
        hanoi(start, end, mid, n - 1);
        cout << start << " " << end << "\n";
        hanoi(mid, start, end, n - 1);
    }
}

int main() {
    int n;
    cin >> n;
    cout << (int)pow(2, n) - 1 << "\n";
    hanoi(1, 2, 3, n);

    return 0;
}
--------------------------------
*/
#pragma endregion

#pragma region BackTracking
/*
int n, m;
int arr[9] = { 0, };
bool visited[9] = { 0, };

void dfs(int c) {
    if (c == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }
    for (int i = 1; i < n + 1; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[c] = i;
            dfs(c + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(0);

    return 0;
}
-----------------------------------
int n, m;
int arr[9] = { 0, };
bool visited[9] = { 0, };

void dfs(int num, int cnt) {
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }
    for (int i = num; i < n + 1; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(1, 0);

    return 0;
}
-----------------------------------
int n, m;
int arr[9] = { 0, };
bool visited[9] = { 0, };

void dfs(int cnt) {
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }
    for (int i = 1; i < n + 1; i++)
    {
        visited[i] = true;
        arr[cnt] = i;
        dfs(cnt + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> n >> m;
    dfs(0);

    return 0;
}
-----------------------------------
int n, m;
int arr[9] = { 0, };
bool visited[9] = { 0, };

void dfs(int num, int cnt) {
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; i++)
    {
        visited[i] = true;
        arr[cnt] = i;
        dfs(i, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> n >> m;
    dfs(1, 0);

    return 0;
}
-----------------------------------
#define MAX 15

using namespace std;

int col[MAX];
int N, total = 0;

bool Check(int level) {
    for (int i = 0; i < level; i++)
    {
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    }

    return true;
}

void nqueen(int x) {
    if (x == N)
        total++;
    else {
        for (int i = 0; i < N; i++)
        {
            col[x] = i;
            if (Check(x))
                nqueen(x + 1);
        }
    }
}

int main() {
    cin >> N;
    nqueen(0);

    cout << total;

    return 0;
}
-----------------------------------
// 2580번은 다시 보고 이해한 후 풀기
-----------------------------------
int n;
int operands[11];
int operators[4];
int mymin = 10000000001;
int mymax = -10000000001;

void GetAnswer(int result, int idx) {
    if (idx == n)
    {
        if (result > mymax)
            mymax = result;
        if (result < mymin)
            mymin = result;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {
            operators[i]--;
            if (i == 0)
                GetAnswer(result + operands[idx], idx + 1);
            else if (i == 1)
                GetAnswer(result - operands[idx], idx + 1);
            else if (i == 2)
                GetAnswer(result * operands[idx], idx + 1);
            else
                GetAnswer(result / operands[idx], idx + 1);
            operators[i]++;
        }
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> operands[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> operators[i];
    }
    GetAnswer(operands[0], 1);
    cout << mymax << '\n';
    cout << mymin;

    return 0;
}
-----------------------------------
#include <iostream>
#include <vector>
#include <cmath>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

bool team[20] = {};
int score[20][20] = {};
int n, mymin = 99999999;

void TeamSet(int idx, int cnt) {
    vector<int> start;
    vector<int> link;
    int start_score = 0;
    int link_score = 0;
    if (cnt == (n / 2)) {
        for (int i = 0; i < n; i++)
        {
            if (team[i] == true)
                start.push_back(i);
            else
                link.push_back(i);
        }
        for (int i = 0; i < (n/2); i++)
            for (int j = 0; j < (n/2); j++)
            {
                start_score += score[start[i]][start[j]];
                link_score += score[link[i]][link[j]];
            }
        if (abs(start_score - link_score) < mymin)
            mymin = abs(start_score - link_score);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (team[i])
            continue;
        else
        {
            team[i] = true;
            TeamSet(i, cnt + 1);
            team[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> score[i][j];
    TeamSet(0, 0);
    cout << mymin;

    return 0;
}
-----------------------------------

*/
#pragma endregion

#pragma region 동적 계획법 1단계
/*
int arr[41] = { 0 };
int n, cnt1 = 0, cnt2 = 0;

int fib(int n) {
    if (n == 1 || n == 2)
    {
        cnt1++;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

int main() {

    cin >> n;
    fib(n);
    arr[1] = arr[2] == 1;
    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        cnt2++;
    }
    cout << cnt1 << ' ' << cnt2;

    return 0;
}
--------------------------------
int store[21][21][21];

int solve(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return solve(20, 20, 20);

    if (store[a][b][c])
        return store[a][b][c];

    if (a < b && b < c)
    {
        store[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
        return store[a][b][c];
    }

    store[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
    return store[a][b][c];
}

int main() {
    int a, b, c;
    while (true)
    {
        std::cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;

        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << '\n';
    }

    return 0;
}
--------------------------------
#include <vector>

int n;
vector<long long> answer = { 0, 1, 2 };

void FindAnswer() {
    long long tmp;
    for (int i = 3; i < n + 1; i++)
    {
        tmp = 0;
        tmp = answer[i - 1] + answer[i - 2];
        answer.push_back(tmp % 15746);
    }
}

int main() {
    cin >> n;
    FindAnswer();
    cout << answer[n] % 15746;

    return 0;
}
--------------------------------
long long parray[101] = { 0,1,1, };
long long p(int n) {
    if (n < 3)
        return parray[n];
    else if (parray[n] == 0)
        parray[n] = p(n - 2) + p(n - 3);
    return parray[n];
}


int main() {

    int t;
    int num;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> num;
        cout << p(num) << '\n';
    }

    return 0;
}
--------------------------------
#define MAX 100001

int series[MAX], dp[MAX] = { 0, };

int main() {
    int n, i;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> series[i];
        dp[i] = series[i];
    }

    int maxSum = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1] + series[i]);
        if (dp[i] > maxSum)
        {
            maxSum = dp[i];
        }
    }

    cout << maxSum << endl;

    return 0;
}
--------------------------------
#include <algorithm>

int house[1001][3];

int main() {

    int n;
    int cost[3];

    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;
    cin >> n;;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0];
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];
        house[i][2] = min(house[i - 1][1], house[i - 1][0]) + cost[2];
    }

    cout << min(house[n][2], min(house[n][0], house[n][1]));

    return 0;
}
--------------------------------
#include <algorithm>

int dp[500][500] = { 0, };

int main() {

    int n, maxNumber = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i + 1; j++)
            cin >> dp[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][0] + dp[i][j];
            else if (i == j)
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
            else
                dp[i][j] = max(dp[i - 1][j - 1] + dp[i][j], dp[i - 1][j] + dp[i][j]);

            maxNumber = max(maxNumber, dp[i][j]);
        }

    cout << maxNumber;

    return 0;
}
--------------------------------
#define MAX 301

int n;
int stairs[MAX];
int dp[MAX];

int main() {

    cin >> n;
    for (auto i = 0; i < n; i++)
        cin >> stairs[i];

    dp[0] = stairs[0];
    dp[1] = max(stairs[1], stairs[0] + stairs[1]);
    dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    for (int i = 3; i < n; i++)
    {
        dp[i] = max(stairs[i] + dp[i - 2], stairs[i] + stairs[i - 1] + dp[i - 3]);
    }

    cout << dp[n - 1];

    return 0;
}
--------------------------------
#include <vector>
#include <algorithm>

int main() {

    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[1] = 0;
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (!(i % 3))
            dp[i] = min(dp[i], dp[i / 3] + 1);
        if(!(i%2))
            dp[i] = min(dp[i], dp[i / 2] + 1);
    }

    cout << dp[n] << "\n";

    return 0;
}
--------------------------------
#define mod 10000000

int dp[101][10] = { 0, };

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                dp[i][0] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][9] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

            dp[i][j] %= mod;
        }
    }
    int result = 0;
    for (int i = 0; i < 10; i++)
    {
        result = (result + dp[n][i]) % mod;
    }

    cout << result << "\n";


    return 0;
}
--------------------------------
#define mod 1000000000

int dp[101][10] = { 0, };

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                dp[i][0] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][9] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

            dp[i][j] %= mod;
        }
    }
    int result = 0;
    for (int i = 0; i < 10; i++)
    {
        result = (result + dp[n][i]) % mod;
    }

    cout << result << "\n";


    return 0;
}
--------------------------------
// 2156번
#include <vector>

vector<int> wine;
vector<int> d;

int Max(int a, int b) {
    return a > b ? a : b;
}

int dynamic() {
    for (int i = 3; i < wine.size(); i++)
    {
        d.push_back(Max(Max(d[i - 3] + wine[i - 1] + wine[i], d[i - 2] + wine[i]), d[i - 1]));
    }
    return d[wine.size() - 1];
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < 3; i++)
    {
        wine.push_back(0);
        d.push_back(0);
    }

    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        wine.push_back(k);
    }

    cout << dynamic() << "\n";

    return 0;
}
--------------------------------
// 11053번
#include <algorithm>

int main() {

    int n;
    cin >> n;

    int arr[1001];
    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
    }

    int dp[1001];

    for (int i = 1; i <= n; i++)
        dp[i] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    sort(dp, dp + n + 1);
    cout << dp[n];

    return 0;
}
--------------------------------
// 1253번
#include <algorithm>

const int MAX = 1001;

int n;

int arr[MAX];
int dp[2][MAX];

int main() {
    cin >> n;

    fill(dp[0], dp[0] + MAX, 1);
    fill(dp[1], dp[1] + MAX, 1);

    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[0][i] = max(dp[0][i], dp[0][j] + 1);
        }
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j > i; j--)
        {
            if (arr[j] < arr[i])
                dp[1][i] = max(dp[1][i], dp[1][j] + 1);
        }
    }

    int ans = 0;
    for (int k = 0; k < n + 1; k++)
    {
        ans = max(ans, dp[0][k] + dp[1][k]);
    }

    cout << ans - 1;

    return 0;
}
--------------------------------
// 2565
#include <algorithm>
#include <vector>

int n, res = 0;
vector<pair<int, int>> v;
int dp[100];

void solution() {
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[j].second < v[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    cout << n - res;
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }
    solution();

    return 0;
}
--------------------------------
// 9251
#include <algorithm>
#include <string>

int dp[1001][1001];

int main() {

    string a, b;

    cin >> a >> b;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        }
    }

    cout << dp[a.length()][b.length()];

    return 0;
}
--------------------------------
// 12865
#include <algorithm>

int n, k;
int dp[101][100001];
int w[101];
int v[101];

int main() {

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            if (j - w[i] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }

    cout << dp[n][k];
    return 0;
}
*/
#pragma endregion

#pragma endregion