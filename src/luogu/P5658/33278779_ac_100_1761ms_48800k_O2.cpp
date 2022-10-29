#include <iostream>
#include <vector>
#define int long long
using namespace std;

struct Node {
  int cnt, last, fa;
  vector<int> son;
};

int n;
string s;
vector<Node> a;

void dfs(int u) {
  a[u].last = a[a[u].fa].last;
  if (s[u - 1] == '(')
    a[u].last = u;
  else if (a[u].last) {
    a[u].cnt = a[a[a[u].last].fa].cnt + 1;
    a[u].last = a[a[a[u].last].fa].last;
  }
  for (int i = 0; i < (int)a[u].son.size(); ++i)
    dfs(a[u].son[i]);
}

signed main() {
  cin >> n >> s;
  a = vector<Node>(n + 1);
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    a[i].fa = x;
    a[x].son.push_back(i);
  }
  dfs(1);
  int ans = a[1].cnt;
  for (int i = 2; i <= n; ++i)
    a[i].cnt += a[a[i].fa].cnt, ans ^= (i * a[i].cnt);
  cout << ans << endl;
  return 0;
}