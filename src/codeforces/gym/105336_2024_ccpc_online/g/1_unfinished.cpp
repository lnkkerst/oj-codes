#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define int long long

void add(int x, int y, int z) {
  cnt++;
  to[cnt] = y;
  val[cnt] = z;
  nex[cnt] = head[x];
  head[x] = cnt;
}

void chushi() {
  fill(to, to);
  fill(nex, nex);
  fill(head, head);
}

int bfs() {
  queue<int> q;
  cur[s] = head[s];
  fill(dis, dis);
  dis[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i != -1; i = nex[i]) {
      int to2 = to[i];
      if (val[i] == 0 || dis[to2]) {
        continue;
      }
      dis[to2] = dis[x] + 1;
      q.push(to2);
      cur[to2] = head[to2];
    }
  }
  if (dis[t] == 0) {
    return 0;
  } else {
    return 1;
  }
}

int dfs(int x, int z) {
  if (x == t) {
    return z;
  }
  int res = 0;
  for (int i = cur[x]; i; i = nex[i]) {
    cur[x] = i;
    int to2 = to[i];
    if (val[i] == 0 || dis[to2] != dis[x] + 1) {
      continue;
    }
    int k = dfs()
  }
}

void solve() {
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
