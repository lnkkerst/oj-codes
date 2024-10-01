#include <bits/stdc++.h>
using namespace std;

char s[100861], t[100861];
int z[100861], ext[100861];
int n, m;

void calc_z(char *s) {
  int n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    z[i] = 0;
  }
  z[1] = n;
  int l, r;
  while (s[1 + z[2]] == s[2 + z[2]]) {
    ++z[2];
  }
  l = 2;
  r = 1 + z[2];
  for (int i = 3; i <= n; ++i) {
    if (i > r) {
      while (s[1 + z[i]] == s[i + z[i]]) {
        ++z[i];
      }
      l = i;
      r = i + z[i] - 1;
    } else if (z[i - l + 1] < r - i + 1) {
      z[i] = z[i - l + 1];
    } else {
      z[i] = r - i;
      while (s[1 + z[i]] == s[i + z[i]]) {
        ++z[i];
      }
      l = i;
      r = i + z[i] - 1;
    }
  }
}

void calc_extend(char *s, char *t) {
  calc_z(t);
  int l, r = 0;
  n = strlen(s + 1), m = strlen(t + 1);
  for (int i = 1; i <= n; ++i) {
    if (i > r) {
      while (i + ext[i] <= n && 1 + ext[i] <= m
             && s[i + ext[i]] == t[1 + ext[i]]) {
        ++ext[i];
      }
      l = i;
      r = i + ext[i] - 1;
    } else {
      if (i + z[i - l + 1] - 1 < r) {
        ext[i] = z[i - l + 1];
      } else {
        ext[i] = r - i + 1;
        while (i + ext[i] <= n && 1 + ext[i] <= m
               && s[i + ext[i]] == t[1 + ext[i]]) {
          ++ext[i];
        }
        l = i;
        r = i + ext[i] - 1;
      }
    }
  }
}

int main() {
  scanf("%s%s", s + 1, t + 1);
  calc_extend(s, t);
  for (int i = 1; i <= m; ++i) {
    cout << z[i] << ' ';
  }
  cout << endl;
  for (int i = 1; i <= n; ++i) {
    cout << ext[i] << ' ';
  }
  return 0;
}
