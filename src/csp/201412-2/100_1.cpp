#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n, 0));
  for (auto &i : a) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  int curX = 0, curY = 0;
  int status = 1;
  for (int i = 1; i <= n * n; ++i) {
    cout << a[curX][curY] << ' ';
    if (status == 1) {
      if (curX + 1 >= n) {
        status = 4;
      } else {
        status = 2;
      }
      ++curY;
      continue;
    }
    if (status == 3) {
      if (curY + 1 >= n) {
        status = 2;
      } else {
        status = 4;
      }
      ++curX;
      continue;
    }
    if (status == 2) {
      int nx = curX + 1;
      int ny = curY - 1;
      if (nx == n - 1 || nx == 0 || ny == n - 1 || ny == 0) {
        if (nx + 1 >= n) {
          status = 1;
        } else {
          status = 3;
        }
      }
      curX = nx;
      curY = ny;
      continue;
    }
    if (status == 4) {
      int nx = curX - 1;
      int ny = curY + 1;
      if (nx == n - 1 || nx == 0 || ny == n - 1 || ny == 0) {
        if (ny + 1 >= n) {
          status = 3;
        } else {
          status = 1;
        }
      }
      curX = nx;
      curY = ny;
      continue;
    }
  }
}
