#include <iostream>
using namespace std;

#define int long long

const int K = 19, MOD = 1e9 + 7, MOD2 = 1e7 + 7;

string s1, s2;
int h1[100010], h2[100010];
bool b1[MOD2 + 10], b2[MOD2 + 10];
int powK[100010] = {1};

int getHash(int ha[], int l, int r) {
  return (ha[r] - (ha[l - 1] % MOD * powK[r - l + 1]) % MOD + MOD) % MOD;
}

signed main() {
  for (int i = 1; i <= 100009; ++i) {
    powK[i] = (powK[i - 1] * K) % MOD;
  }
  cin >> s1 >> s2;
  s1 = " " + s1;
  s2 = " " + s2;
  for (int i = 1; i <= s1.size() - 1; ++i) {
    h1[i] = (s1[i] + h1[i - 1] * K) % MOD;
  }
  for (int i = 1; i <= s2.size() - 1; ++i) {
    h2[i] = (s2[i] + h2[i - 1] * K) % MOD;
  }
  int l = 1, r = min(s1.size(), s2.size()) - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    for (int i = 1; i + mid - 1 < s1.size(); ++i) {
      b1[getHash(h1, i, i + mid - 1) % MOD2] = true;
    }

    bool fl = false;
    for (int i = 1; i + mid - 1 < s2.size(); ++i) {
      if (b1[getHash(h2, i, i + mid - 1) % MOD2]) {
        fl = true;
        break;
      }
    }
    if (fl) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << r << endl;
}
