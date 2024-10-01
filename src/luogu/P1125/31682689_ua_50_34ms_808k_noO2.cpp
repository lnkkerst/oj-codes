#include <algorithm>
#include <iostream>
using namespace std;

char ch;
int cnt[26];

bool pd(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (!(x % i)) {
      return 0;
    }
  }
  return 1;
}

int main() {
  while (cin >> ch) {
    ++cnt[ch - 'a'];
  }
  int maxn = -1, minn = (int)1e9;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] > maxn) {
      maxn = cnt[i];
    }
    if (cnt[i] && cnt[i] < minn) {
      minn = cnt[i];
    }
  }
  if (pd(maxn - minn)) {
    cout << "Lucky Word\n" << maxn - minn << endl;
  } else {
    cout << "No Answer\n0";
  }
  return 0;
}
