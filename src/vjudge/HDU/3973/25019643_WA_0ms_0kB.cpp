#include <ext/hash_map>
#include <ext/hash_set>
#include <iostream>
#include <string>
using namespace std;
using namespace __gnu_cxx;

namespace __gnu_cxx {
template <> struct hash<const string> {
  size_t operator()(const string &s) const {
    return hash<const char *>()(s.c_str());
  }
};
template <> struct hash<string> {
  size_t operator()(const string &s) const {
    return hash<const char *>()(s.c_str());
  }
};
} // namespace __gnu_cxx

struct Qus {
  char opt;
  int l, r;
} q[100010];

int n, t, m;
hash_set<string> word;
hash_map<int, bool> len, lens;
string str;
string wd[10010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> t;
  for (int k = 1; k <= t; ++k) {
    printf("Case #%d:\n", k);
    cin >> n;
    for (int i = 1; i <= n; ++i)
      cin >> wd[i];
    cin >> str >> m;
    for (int i = 1; i <= m; ++i) {
      char opt;
      cin >> opt;
      if (opt == 'C') {
        int pos;
        char ch;
        cin >> pos >> ch;
        q[i] = (Qus){opt, pos, (int)ch};
      } else {
        int l, r;
        cin >> l >> r;
        len[r - l + 1] = 1;
        q[i] = (Qus){opt, l, r};
      }
    }
    for (int i = 1; i <= n; ++i)
      if (len[(int)wd[i].size()]) {
        word.insert(wd[i]);
        lens[(int)wd[i].size()] = 1;
      }
    for (int i = 1; i <= m; ++i) {
      if (q[i].opt == 'C')
        str[q[i].l] = q[i].r;
      else {
        if (!lens[q[i].r - q[i].l + 1])
          cout << "No\n";
        else
          cout << (word.find(str.substr(q[i].l, q[i].r - q[i].l + 1)) !=
                           word.end()
                       ? "Yes\n"
                       : "No\n");
      }
    }
    word.clear();
    len.clear();
    lens.clear();
  }
  return 0;
}