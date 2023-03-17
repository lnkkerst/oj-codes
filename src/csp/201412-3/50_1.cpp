#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#define int long long

using namespace std;

constexpr double EPS = 1e-8;

void solve() {
  vector<string> input;
  string str;
  while (getline(cin, str)) {
    input.emplace_back(str);
  }
  for (auto &i : input) {
    if (i[0] == 'c') {
      stringstream ss(i);
      int line;
      ss >> str >> line;
      input[line - 1] = "";
    }
  }
  vector<pair<double, int>> a1, a2;
  for (auto &i : input) {
    if (i.length() == 0) {
      continue;
    }
    stringstream ss(i);
    double p;
    int s;
    ss >> str >> p >> s;
    if (i[0] == 'b') {
      a1.emplace_back(p, s);
    } else if (i[0] == 's') {
      a2.emplace_back(p, s);
    }
  }
  sort(a1.begin(), a1.end(), greater<>());
  sort(a2.begin(), a2.end(), greater<>());
  double ans1 = 0;
  int ans2 = 0;
  int sum = 0;
  for (auto &i : a1) {
    double p = i.first;
    sum += i.second;
    int sum2 = 0;
    for (auto &j : a2) {
      if (j.first < p || fabs(j.first - p) < EPS) {
        sum2 += j.second;
      }
    }
    int tmp = min(sum, sum2);
    if (tmp > ans2) {
      ans1 = p;
      ans2 = tmp;
    }
  }
  cout << fixed << setprecision(2) << ans1 << ' ' << ans2 << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
