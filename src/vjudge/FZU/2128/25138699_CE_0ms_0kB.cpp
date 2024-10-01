#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int l, r;
  bool operator<(const Node &b) const {
    if (this->l == b.l) {
      return this->r < b.r;
    }
    return this->l < b.l;
  }
};

string s, t;
int n;
vector<Node> d;

int main() {
  while (cin >> s >> n) {
    for (int i = 1; i <= n; ++i) {
      cin >> t;
      int pos = 0;
      while (1) {
        pos = s.find(t, pos);
        if (pos == string::npos) {
          break;
        }
        d.push_back({pos, pos + t.length() - 1});
        ++pos;
      }
    }
    sort(d.begin(), d.end());
    // for(auto i : d) cout << i.l << ' ' << i.r << endl;
    int ans = -1;
    for (int i = 1; i < (int)d.size(); ++i) {
      ans = max(ans, d[i].r - d[i - 1].l - 1);
    }
    if (ans == -1) {
      cout << s.length();
    } else {
      cout << ans;
    }
    cout << endl;
    d.clear();
  }
  return 0;
}
