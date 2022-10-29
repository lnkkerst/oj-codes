#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
#define int long long
using namespace std;

struct Node {
  int h, dis, cnt;
  bool vis;
} a[10001];

struct Edge {
  int to, nex, w;
} e[200001];

int c[101][101];
int n, m, cnt;
const int MOD = (int)1e9 + 7;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void addedge(int u, int v, int w) {
  // cout << u << ' ' << v << ' ' << w << endl;
  e[++cnt] = {v, a[u].h, w};
  a[u].h = cnt;
}

void spfa(int st) {
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    a[i].dis = (int)1e9;
  a[st].dis = 0, a[st].vis = 1, a[st].cnt = 1;
  q.push(st);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = a[u].h; i; i = e[i].nex) {
      int v = e[i].to;
      if (a[v].dis > a[u].dis + e[i].w) {
        a[v].dis = a[u].dis + e[i].w;
        a[v].cnt = a[u].cnt;
        if (!a[v].vis) {
          a[v].vis = 1;
          q.push(v);
        }
      } else if (a[v].dis == a[u].dis + e[i].w)
        a[v].cnt += a[u].cnt, a[v].cnt %= MOD;
    }
    a[u].vis = 0;
  }
}

int cno(int x, int y) {
  if (y > m - x + 1)
    return -1;
  if (x < 1 || y < 1)
    return -2;
  --x;
  n = max(n, (m * x - (x * x - x) / 2) + y);
  return (m * x - (x * x - x) / 2) + y;
}

void add(int x, int y) {
  // cout << x << ' ' << y << endl;
  int u = cno(x, y);
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    // cout << "a " << nx << ' ' << ny << ' ';
    int v = cno(nx, ny);
    // cout << v << endl;
    if (v < 0)
      continue;
    addedge(u, v, c[nx][ny] + c[m - y + 1][m - x + 1]);
  }
}

signed main() {
  while (cin >> m) {
    if (!m)
      return 0;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= m; ++j)
        cin >> c[i][j];
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= m - i + 1; ++j)
        add(i, j);
    spfa(1);
    unordered_map<int, int> ans;
    for (int i = 1; i <= m; ++i) {
      int tmp = cno(i, m - i + 1);
      // cout << a[tmp].dis << ' ' << a[tmp].cnt << endl;
      ans[a[tmp].dis] += a[tmp].cnt;
      ans[a[tmp].dis] %= MOD;
    }
    int ansn = -1;
    for (auto i : ans)
      ansn = max(ansn, i.second);
    cout << ansn << endl;
    memset(a, 0, sizeof a);
    memset(e, 0, sizeof e);
    n = m = cnt = 0;
  }
  return 0;
}