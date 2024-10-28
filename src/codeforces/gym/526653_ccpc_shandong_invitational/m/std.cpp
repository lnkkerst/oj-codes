#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;

struct point {
  ll x, y;
  point(ll x = 0, ll y = 0): x(x), y(y) {}
};
struct arrow {
  ll x, y;
  arrow(ll x = 0, ll y = 0): x(x), y(y) {}
  arrow(point A, point B): x(B.x - A.x), y(B.y - A.y) {}
};
ll dot(arrow A, arrow B) {
  return A.x * B.x + A.y * B.y;
}
ll cross(arrow A, arrow B) {
  return A.x * B.y - A.y * B.x;
}

const int N = 1010;
ll f[N], dp[N][N], ans;
int L[N][N], R[N][N];
point p[1010];

void solve() {
  int n;
  cin >> n;
  ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
    f[i + n] = f[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
    p[i + n] = p[i];
  }
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = i, t = i; j <= 2 * n; j++) {
      if (f[j] == f[i]) {
        t = j;
      }
      L[i][j] = t;
    }
  }
  for (int i = 2 * n; i >= 1; i--) {
    for (int j = i, t = i; j >= 1; j--) {
      if (f[j] == f[i]) {
        t = j;
      }
      R[i][j] = t;
    }
  }

  for (int i = 1; i <= 2 * n; i++) {
    for (int j = i; j <= 2 * n; j++) {
      dp[i][j] = 0;
    }
  }

  for (int len = 2; len < n; len++) {
    for (int l = 1, r = 1 + len; r <= 2 * n; l++, r++) {
      if (f[l] != f[r]) {
        continue;
      }
      for (int i = l + 1; i < r; i++) {
        int t = L[i][r - 1];
        dp[l][r]
          = max(dp[l][r], dp[i][t] + abs(cross({p[l], p[r]}, {p[l], p[t]}))
                            + abs(cross({p[l], p[i]}, {p[l], p[t]})));
        ans = max(ans, dp[l][r]);
      }
      for (int t = r - 1; t > l; t--) {
        int i = R[t][l + 1];
        dp[l][r]
          = max(dp[l][r], dp[i][t] + abs(cross({p[l], p[r]}, {p[l], p[t]}))
                            + abs(cross({p[l], p[i]}, {p[l], p[t]})));
        ans = max(ans, dp[l][r]);
      }
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
