#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20000;
int a[MAXN], b[MAXN], c[MAXN], ans[MAXN], la, lb, lans;
void Read(int *A) {
  string s1;
  cin >> s1;
  A[0] = s1.length();
  for (int i = 1; i <= A[0]; i++) {
    A[i] = s1[i - 1] - 48;
  }
  reverse(A + 1, A + 1 + A[0]);
}
bool Bijiao() {
  if (c[0] > b[0]) {
    return true;
  }
  if (c[0] < b[0]) {
    return false;
  }
  for (int i = c[0]; i >= 1; i--) {
    if (c[i] < b[i]) {
      return false;
    } else if (c[i] > b[i]) {
      return true;
    }
  }
  return true;
}
void Minus() {
  int x = 0;
  for (int i = 1; i <= c[0]; i++) {
    c[i] -= b[i] + x;
    if (c[i] < 0) {
      c[i] += 10;
      x = 1;
    } else {
      x = 0;
    }
  }
  while (c[0] > 1 && c[c[0]] == 0) {
    c[0]--;
  }
}
void Putout(int *A) {
  for (int j = A[0]; j >= 1; j--) {
    cout << A[j];
  }
}
int main() {
  Read(a);
  Read(b);
  c[0] = 0;
  for (int i = a[0]; i >= 1; i--) {
    for (int j = c[0]; j >= 1; j--) {
      c[j + 1] = c[j];
    }
    c[1] = a[i];
    c[0]++;
    while (Bijiao()) {
      Minus();
      ans[i]++;
    }
  }
  ans[0] = a[0];
  while (ans[0] > 1 && ans[ans[0]] == 0) {
    ans[0]--;
  }
  Putout(ans);
  return 0;
}
