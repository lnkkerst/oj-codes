#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

std::string trim(const std::string &str) {
  size_t first = str.find_first_not_of(" \t\n\r");
  size_t last = str.find_last_not_of(" \t\n\r");
  if (first == std::string::npos) {
    return "";
  }
  return str.substr(first, last - first + 1);
}

bool startsWith(const std::string &str, const std::string &prefix) {
  if (str.size() < prefix.size()) {
    return false;
  }
  for (size_t i = 0; i < prefix.size(); i++) {
    if (str[i] != prefix[i]) {
      return false;
    }
  }
  return true;
}

void solve() {
  int w;
  cin >> w;
  string s;
  vector<pair<string, int>> sections;
  bool inList = false;
  string cs = "";
  int ans = 0;
  bool lastEmpty = false;
  auto newLine = [&]() {
    if (cs.empty()) {
      return;
    }
    sections.emplace_back(trim(cs), inList);
    cs = "";
    inList = false;
  };
  while (getline(cin, s)) {
    if (startsWith(s, "* ")) {
      if (inList && !lastEmpty) {
        --ans;
      }
      newLine();
      inList = true;
      s = string{s.begin() + 2, s.end()};
      s = trim(s);
      cs = cs + s + " ";
      lastEmpty = false;
      continue;
    } else if (inList && !startsWith(s, "  ")) {
      newLine();
    }
    s = trim(s);
    if (s.length() == 0) {
      lastEmpty = true;
      newLine();
      continue;
    }
    lastEmpty = false;
    cs += s + " ";
  }
  newLine();
  bool last = false;
  for (auto s : sections) {
    int cw = w;
    if (s.second) {
      cw -= 3;
    }
    int cc = 0;
    int ch = 0;
    for (auto i : s.first) {
      if (cc == 0 && i == ' ') {
        continue;
      }
      ++cc;
      if (cc == cw) {
        ++ch;
        cc = 0;
      }
    }
    if (cc || !ch) {
      ++ch;
    }
    ans += ch;
    ++ans;
  }
  cout << ans - 1 << endl;
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
