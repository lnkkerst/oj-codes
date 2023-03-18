#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const double PI = acos(-1);

double alpha(int u) {
  if (u == 0) {
    return sqrt(0.5);
  }
  return 1;
}

struct Matrix {
  array<array<double, 8>, 8> data = {};

  array<double, 8> &operator[](int x) { return this->data[x]; }

  Matrix operator*(Matrix &b) {
    Matrix res;
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        res[i][j] = data[i][j] * b[i][j];
      }
    }
    return res;
  }

  void fill(vector<int> &a) {
    int curX = 0, curY = 0;
    vector<int> dx, dy;
    for (int i = 2; i <= 6; i += 2) {
      dx.emplace_back(0);
      for (int j = 1; j <= i; ++j) {
        dx.emplace_back(1);
      }
      for (int j = 1; j <= i; ++j) {
        dx.emplace_back(-1);
      }
    }
    dx.emplace_back(0);
    for (int i = 1; i <= 7; ++i) {
      dx.emplace_back(1);
    }
    dx.emplace_back(0);
    for (int i = 6; i >= 2; i -= 2) {
      for (int j = 1; j <= i; ++j) {
        dx.emplace_back(-1);
      }
      for (int j = 1; j <= i; ++j) {
        dx.emplace_back(1);
      }
      dx.emplace_back(0);
    }
    for (int i = 1; i <= 7; i += 2) {
      for (int j = 1; j <= i; ++j) {
        dy.emplace_back(1);
      }
      for (int j = 1; j <= i; ++j) {
        dy.emplace_back(-1);
      }
      dy.emplace_back(0);
    }
    dy.back() = 1;
    for (int i = 6; i >= 2; i -= 2) {
      for (int j = 1; j <= i; ++j) {
        dy.emplace_back(1);
      }
      dy.emplace_back(0);
      for (int j = 1; j <= i - 1; ++j) {
        dy.emplace_back(-1);
      }
      dy.emplace_back(1);
    }
    data[curX][curY] = a[0];
    for (int i = 0; i < 8 * 8 - 1 && i + 1 < a.size(); ++i) {
      curX += dx[i];
      curY += dy[i];
      data[curX][curY] = a[i + 1];
    }
  }

  void print() {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        cout << data[i][j] << ' ';
      }
      cout << endl;
    }
  }

  void read() {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        cin >> data[i][j];
      }
    }
  }

  double getIJ(int i, int j) const {
    double res = 0;
    for (int u = 0; u < 8; ++u) {
      for (int v = 0; v < 8; ++v) {
        res += alpha(u) * alpha(v) * data[u][v] *
               cos((PI / 8) * (i + 1.0 / 2) * u) *
               cos((PI / 8) * (j + 1.0 / 2) * v);
      }
    }
    res /= 4;
    return res;
  }

  Matrix cvt() const {
    Matrix res;
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        res[i][j] = max(0., min(255., floor(getIJ(i, j) + 128.5)));
        // res[i][j] = getIJ(i, j);
      }
    }
    return res;
  }
};

void solve() {
  Matrix q;
  q.read();
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  Matrix m;
  m.fill(a);
  if (t == 0) {
    m.print();
    return;
  }
  m = q * m;
  if (t == 1) {
    m.print();
    return;
  }
  m.cvt().print();
}

int main() {
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
