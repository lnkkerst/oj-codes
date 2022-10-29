#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct Que {
  int x, y;
};

int n, m, cnt = 'a' - 1;
char e[101][101];
bool vis[101][101];
vector<Que> q;
map<int, char> b;
const int dx[] = {1, 0, 0, -1, 1, 1, -1, -1};
const int dy[] = {0, 1, -1, 0, 1, -1, -1, 1};

void dfs(int x, int y) {
  if (e[x][y] != '1' || x > n || x < 1 || y > m || y < 1 || vis[x][y])
    return;
  q.push_back((Que){x, y});
  vis[x][y] = 1;
  for (int i = 0; i < 8; ++i)
    dfs(x + dx[i], y + dy[i]);
  // vis[x][y] = 0;
}

int calc_dis(Que a, Que b) { return abs(a.x - b.x) + abs(a.y - b.y); }

int calc_hash() {
  int ret = 1;
  for (int i = 0; i < (int)q.size(); ++i)
    for (int j = 0; j < (int)q.size(); ++j)
      if (i == j)
        continue;
      else
        ret += calc_dis(q[i], q[j]), ret %= 233333333;
  return ret;
}

void cover(int x, int y, char col) {
  if (e[x][y] != '1' || x > n || x < 1 || y > m || y < 1 || vis[x][y])
    return;
  vis[x][y] = 1;
  e[x][y] = col;
  for (int i = 0; i < 8; ++i)
    cover(x + dx[i], y + dy[i], col);
  vis[x][y] = 0;
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      char ch = getchar();
      while (ch != '0' && ch != '1')
        ch = getchar();
      e[i][j] = ch;
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (e[i][j] == '1') {
        dfs(i, j);
        int hash = calc_hash();
        q.clear();
        memset(vis, 0, sizeof(vis));
        if (b.find(hash) != b.end())
          cover(i, j, b[hash]);
        else
          b[hash] = ++cnt, cover(i, j, cnt);
      }
  for (int i = 1; i <= n; ++i, putchar('\n'))
    for (int j = 1; j <= m; ++j)
      putchar(e[i][j]);
  return 0;
}