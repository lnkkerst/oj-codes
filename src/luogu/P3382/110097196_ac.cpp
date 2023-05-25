#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

constexpr double eps = 1e-7;

double calc(vector<double> &a, double x) {
  double xbase = 1;
  double res = 0;
  for (int i = 0; i < a.size(); ++i) {
    res += a[i] * xbase;
    xbase *= x;
  }
  return res;
}

int main() {
  int n;
  double l, r;
  cin >> n >> l >> r;
  vector<double> a(n + 1);
  for (int i = n; i >= 0; --i) {
    cin >> a[i];
  }
  while (fabs(r - l) > eps * 10) {
    double mid = (l + r) / 2;
    double lmid = mid - eps;
    double rmid = mid + eps;
    double lans = calc(a, lmid);
    double rans = calc(a, rmid);
    if (lans < rans) {
      l = lmid;
    } else {
      r = rmid;
    }
  }
  cout << fixed << setprecision(10) << l << endl;
}
