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


// 문제별 순서대로
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
