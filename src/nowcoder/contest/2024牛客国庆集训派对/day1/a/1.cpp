#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
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

#define int long long

namespace GenHelper {
unsigned z1, z2, z3, z4, b, u;
unsigned get() {
  b = ((z1 << 6) ^ z1) >> 13;
  z1 = ((z1 & 4294967294U) << 18) ^ b;
  b = ((z2 << 2) ^ z2) >> 27;
  z2 = ((z2 & 4294967288U) << 2) ^ b;
  b = ((z3 << 13) ^ z3) >> 21;
  z3 = ((z3 & 4294967280U) << 7) ^ b;
  b = ((z4 << 3) ^ z4) >> 12;
  z4 = ((z4 & 4294967168U) << 13) ^ b;
  return (z1 ^ z2 ^ z3 ^ z4);
}
bool read() {
  while (!u) {
    u = get();
  }
  bool res = u & 1;
  u >>= 1;
  return res;
}
void srand(int x) {
  z1 = x;
  z2 = (~x) ^ 0x233333333U;
  z3 = x ^ 0x1234598766U;
  z4 = (~x) + 51;
  u = 0;
}
} // namespace GenHelper
using namespace GenHelper;
bool edge[8005][8005];
signed main() {
  int n, seed;
  cin >> n >> seed;
  srand(seed);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      edge[j][i] = edge[i][j] = read();
    }
  }
  vector<int> b1(n + 1), w1(n + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        continue;
      }
      if (edge[i][j]) {
        ++b1[i];
      } else {
        ++w1[i];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += b1[i] * w1[i];
  }
  ans /= 2;
  cout << (n * (n - 1) * (n - 2)) / 6 - ans << endl;

  return 0;
}
