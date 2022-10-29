//
// Created by lnkkerst on 2020/5/11.
//

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

constexpr double eps = 1e-7;

int main() {
  vector<double>::size_type n;
  cin >> n;
  vector<vector<double>> mat(n, vector<double>(n + 1, 0.0));
  for (auto &i : mat)
    for (auto &j : i)
      cin >> j;
  for (decltype(mat.size()) i = 0; i < n; ++i) {
    auto pos = i;
    for (auto j = i + 1; j < n; ++j)
      if (fabs(mat[j][i]) > fabs(mat[pos][i]))
        pos = j;
    for (auto j = i; j <= n; ++j)
      std::swap(mat[pos][j], mat[i][j]);
    if (fabs(mat[i][i]) < eps) {
      puts("No Solution!");
      return 0;
    }
    for (auto j = i + 1; j < n; ++j)
      if (fabs(mat[j][i]) > eps) {
        double p = mat[i][i] / mat[j][i];
        for (auto k = i; k <= n; ++k)
          mat[j][k] = mat[i][k] - mat[j][k] * p;
      }
  }
  vector<double> ans(n, 0.0);
  for (int i = n - 1; i >= 0; --i) {
    ans[i] = mat[i][n];
    for (auto j = i + 1; j < n; ++j)
      ans[i] -= ans[j] * mat[i][j];
    ans[i] /= mat[i][i];
  }
  for (const auto &i : ans)
    cout << std::fixed << std::setprecision(2) << i << endl;
  return 0;
}