#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define M_PI 3.14159265358979323846

void solve() {
  int n;
  cin >> n;
  cout << fixed << setprecision(8) << cos(M_PI / 4 / n) / sin(M_PI / 2 / n)
       << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
