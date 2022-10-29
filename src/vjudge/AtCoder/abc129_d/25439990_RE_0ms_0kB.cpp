#include <algorithm>
#include <iostream>
using namespace std;

char e[2001][2001];
int cnt[2001][2001];

int m, n;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> e[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    int ct = 0, now = 1, last = 1;
    while (1) {
      if (e[i][now] == '.')
        ++ct, ++now;
      else {
        for (int j = last; j <= now - 1; ++j)
          cnt[i][j] = ct;
        ct = 0;
        while (e[i][now] == '#')
          ++now;
        if (now >= m)
          break;
        else
          last = now;
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    int ct = 0, now = 1, last = 1;
    while (1) {
      if (e[now][i] == '.')
        ++ct, ++now;
      else {
        for (int j = last; j <= now - 1; ++j)
          cnt[j][i] += ct;
        ct = 0;
        while (e[now][i] == '#')
          ++now;
        if (now >= n)
          break;
        else
          last = now;
      }
    }
  }
  cout << *max_element(&cnt[1][1], &cnt[n][m + 1]) - 1;
  return 0;
}