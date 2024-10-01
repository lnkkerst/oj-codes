#include <bits/stdc++.h>
using namespace std;

int n, m;
int e[31][31];

void bfs(int x, int y) {
  queue<pair<int, int>> q;
  pair<int, int> now = make_pair(x, y);
  q.push(now);
  while (!q.empty()) {
    now = q.front();
    q.pop();
    if (now.first < 1 || now.second < 1 || now.first > n || now.second > m
        || e[now.first][now.second] != 0) {
      continue;
    }
    e[now.first][now.second] = 2;
    q.push(make_pair(now.first + 1, now.second));
    q.push(make_pair(now.first - 1, now.second));
    q.push(make_pair(now.first, now.second + 1));
    q.push(make_pair(now.first, now.second - 1));
  }
}

int main() {
  cin >> n;
  m = n;
  bool f = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> e[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (e[i][j]) {
        bfs(i + 1, j + 1);
        f = 1;
        break;
      }
    }
    if (f) {
      break;
    }
  }
  for (int i = 1; i <= n; ++i, cout << endl) {
    for (int j = 1; j <= m; ++j) {
      cout << e[i][j] << ' ';
    }
  }
  return 0;
}
