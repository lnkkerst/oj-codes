#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int n, m, al[100050], ar[100050], bl[100050], br[100050], c[400050];
int ca, cb;
long long tota, totb, cna[800050], cnb[800050];
double sa[800050], sb[800050];
pair<int, int> a[800050], b[800050];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> al[i] >> ar[i];
    tota += ar[i] - al[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> bl[i] >> br[i];
    totb += br[i] - bl[i];
  }
  for (int i = 1; i <= n; ++i) {
    c[++c[0]] = al[i];
    c[++c[0]] = ar[i];
  }
  for (int i = 1; i <= m; ++i) {
    c[++c[0]] = bl[i];
    c[++c[0]] = br[i];
  }
  c[++c[0]] = 1e9 + 7;
  sort(c + 1, c + c[0] + 1);
  c[0] = unique(c + 1, c + c[0] + 1) - c - 1;
  for (int i = 1; i <= n; ++i) {
    int l = upper_bound(c + 1, c + c[0] + 1, al[i]) - c;
    int ls = al[i];
    if (tota && al[i] == ar[i]) {
      continue;
    }
    if (!tota) {
      a[++ca] = {al[i], ar[i]};
      continue;
    }
    while (c[l] <= ar[i]) {
      a[++ca] = {ls, c[l]};
      ls = c[l];
      ++l;
    }
  }
  for (int i = 1; i <= m; ++i) {
    int l = upper_bound(c + 1, c + c[0] + 1, bl[i]) - c;
    int ls = bl[i];
    if (totb && bl[i] == br[i]) {
      continue;
    }
    if (!totb) {
      b[++cb] = {bl[i], br[i]};
      continue;
    }
    while (c[l] <= br[i]) {
      b[++cb] = {ls, c[l]};
      ls = c[l];
      ++l;
    }
  }
  sort(a + 1, a + ca + 1);
  sort(b + 1, b + cb + 1);
  for (int i = 1; i <= ca; ++i) {
    if (tota) {
      sa[i] = sa[i - 1] +
              (a[i].second - a[i].first) / 2.0 * (a[i].first + a[i].second);
    } else {
      sa[i] = sa[i - 1] + a[i].first;
    }
    if (tota) {
      cna[i] = cna[i - 1] + (a[i].second - a[i].first);
    } else {
      cna[i] = cna[i - 1] + 1;
    }
  }
  for (int i = 1; i <= cb; ++i) {
    if (totb) {
      sb[i] = sb[i - 1] +
              (b[i].second - b[i].first) / 2.0 * (b[i].first + b[i].second);
    } else {
      sb[i] = sb[i - 1] + b[i].first;
    }
    if (totb) {
      cnb[i] = cnb[i - 1] + (b[i].second - b[i].first);
    } else {
      cnb[i] = cnb[i - 1] + 1;
    }
  }
  double ans = 0;
  for (int i = 1; i <= ca; ++i) {
    int lf = lower_bound(b + 1, b + cb + 1, a[i]) - b - 1;
    int rt = upper_bound(b + 1, b + cb + 1, a[i]) - b;
    if (lf > 0) {
      ans += (cna[i] - cna[i - 1]) *
             ((a[i].first + a[i].second) / 2.0 * cnb[lf] - sb[lf]);
    }
    if (rt <= cb) {
      ans += (cna[i] - cna[i - 1]) *
             (sb[cb] - sb[rt - 1] -
              (a[i].first + a[i].second) / 2.0 * (cnb[cb] - cnb[rt - 1]));
    }
    if (lf + 1 != rt) {
      if (tota) {
        ans += (cna[i] - cna[i - 1]) * (cna[i] - cna[i - 1]) / 3.0 *
               (cna[i] - cna[i - 1]);
      }
    }
  }
  cout << fixed << setprecision(14) << (ans / cna[ca] / cnb[cb]) << endl;
}
