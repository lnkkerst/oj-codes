#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define int long long

map<char, string> mp = {
  {'0', "0"   },
  {'1', "1"   },
  {'2', "10"  },
  {'3', "11"  },
  {'4', "100" },
  {'5', "101" },
  {'6', "110" },
  {'7', "111" },
  {'8', "1000"},
  {'9', "1001"},
  {'A', "1010"},
  {'B', "1011"},
  {'C', "1100"},
  {'D', "1101"},
  {'E', "1110"},
  {'F', "1111"},
};

void print(string s) {
  for (auto i : s) {
    cout << (char)(i + '0');
  }
  cout << endl;
}

void solve() {
  string k;
  cin >> k;
  string s;
  cin >> s;
  string x;
  for (auto c : s) {
    x += mp[c];
  }
  for (auto &c : k) {
    c -= '0';
  }
  for (auto &c : x) {
    c -= '0';
  }
  // print(x);
  // print(k);
  int n = x.length();
  int m = k.length() - 1;
  int of = 0;
  string up = x.substr(0, min((int)x.length(), m + 1));
  string down = k;
  while (true) {
    print(up);
    print(down);
    if (of >= n) {
      break;
    }
    while (up.size() < m + 1) {
      if (up.size() + of < x.size()) {
        up += x[up.size() + of];
      } else {
        up += (char)0;
      }
    }
    cout << "after: " << endl;
    print(up);
    print(down);

    for (int i = 0; i < m + 1; ++i) {
      up[i] = up[i] ^ down[i];
    }
    if (of + m + 2 >= n + m) {
      up += (char)0;
      break;
    }
    reverse(up.begin(), up.end());
    while (!up.empty() && up.back() == 0 && of <= n) {
      ++of;
      up.pop_back();
    }
    reverse(up.begin(), up.end());
  }
  while (up.size() < m) {
    up += (char)0;
  }
  for (auto i : up) {
    cout << (int)i;
  }
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
