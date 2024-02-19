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

double calculateMean(const std::vector<double> &data) {
  double sum = 0.0;
  for (const double &value : data) {
    sum += value;
  }
  return sum / data.size();
}

double calculateVariance(const std::vector<double> &data) {
  // 计算平均值
  double mean = calculateMean(data);

  // 计算平方差的和
  double sumSquaredDifferences = 0.0;
  for (const double &value : data) {
    double difference = value - mean;
    sumSquaredDifferences += difference * difference;
  }

  // 计算方差
  double variance = sumSquaredDifferences / data.size();
  return variance;
}

void solve() {
  int n;
  cin >> n;
  map<int, map<int, int>> b;
  for (int i = 1; i <= n; ++i) {
    int x, y, r;
    cin >> x >> y >> r;
    ++b[x][y];
  }
  vector<double> a;
  for (int i = -99; i <= 99; ++i) {
    for (int j = -99; j <= 99; ++j) {
      a.emplace_back(b[i][j]);
    }
  }
  cout << calculateVariance(a) << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
