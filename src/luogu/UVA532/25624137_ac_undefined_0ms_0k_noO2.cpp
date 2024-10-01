#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int k, x, y, step;
} a[31][31][31];

bool e[31][31][31];
bool b[31][31][31];
int k, n, m, sx, sy, ex, ey, sk, ek;
int ans;
bool found = 0;

void bfs() {
  Node now;
  now.k = sk, now.x = sx, now.y = sy, now.step = 0;
  queue<Node> q;
  q.push(now);
  while (!q.empty()) {
    now = q.front();
    q.pop();

    if (now.k == ek && now.x == ex && now.y == ey) {
      ans = now.step;
      break;
    }
    if (now.k < 1 || now.k > k || now.x < 1 || now.x > n || now.y < 1
        || now.y > m || e[now.k][now.x][now.y] || b[now.k][now.x][now.y]) {
      continue;
    }
    b[now.k][now.x][now.y] = 1;
    Node next = now;
    ++next.step;
    ++next.k, q.push(next);
    next.k -= 2, q.push(next), ++next.k;
    ++next.x, q.push(next);
    next.x -= 2, q.push(next), ++next.x;
    ++next.y, q.push(next);
    next.y -= 2, q.push(next), ++next.y;
  }
}

int main() {
  while (1) {
    scanf("%d%d%d", &k, &n, &m);
    if (!k && !n && !m) {
      return 0;
    }
    memset(e, 0, sizeof(e));
    memset(b, 0, sizeof(b));
    ans = -1, found = 0;
    for (int kk = 1; kk <= k; ++kk) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          char ch;
          cin >> ch;
          if (ch == 'S') {
            sx = i, sy = j, sk = kk;
          }
          if (ch == 'E') {
            ex = i, ey = j, ek = kk;
          }
          if (ch == '#') {
            e[kk][i][j] = 1;
          }
        }
      }
    }
    bfs();
    if (ans == -1) {
      puts("Trapped!");
    } else {
      printf("Escaped in %d minute(s).\n", ans);
    }
  }
}
