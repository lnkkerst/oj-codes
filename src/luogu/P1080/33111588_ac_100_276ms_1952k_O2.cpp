#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int cmp(const string &a, const string &b);
// string mul(const string &a, const string &b);
string mul(string a, string b);

struct Node {
  string l, r;
  bool operator<(const Node &b) const {
    return cmp(mul(this->l, this->r), mul(b.l, b.r)) == -1;
  }
};

struct NodeLite {
  int l, r;
  bool operator<(const NodeLite &b) const {
    return this->l * this->r < b.l * b.r;
  }
} a[10010];

struct bigInt {
  int dat[100010];
  bigInt(): dat{0} {
    dat[0] = 1;
  }
  bigInt(int x): dat{0} {
    dat[0] = 1;
    int i = 1;
    while (x) {
      dat[i++] = x % 10;
      x /= 10;
    }
    dat[0] = --i;
  }
  int &operator[](int x) {
    return dat[x];
  }
  bigInt operator*(const int &x) {
    bigInt a;
    int len;
    a[0] = dat[0];
    for (int i = 1; i <= dat[0]; ++i) {
      a[i] = dat[i] * x;
    }
    for (int i = 1; i <= a[0] || a[i]; len = ++i) {
      a[i + 1] += a[i] / 10;
      a[i] %= 10;
    }
    a[0] = len - !a[len];
    return a;
  }
  bigInt operator/(const int &x) {
    bigInt a;
    a[0] = dat[0];
    int res = 0;
    for (int i = dat[0]; i >= 1; --i) {
      res *= 10, res += dat[i];
      a[i] = res / x;
      res %= x;
    }
    while (!a[a[0]] && a[0] > 1) {
      --a[0];
    }
    return a;
  }
  bool operator<(const bigInt &x) const {
    if (dat[0] == x.dat[0]) {
      int i;
      for (i = dat[0]; dat[i] == x.dat[i] && i > 1; --i)
        ;
      if (i >= 1) {
        return dat[i] < x.dat[i];
      }
      return 0;
    }
    return dat[0] < x.dat[0];
  }
};

ostream &operator<<(ostream &out, const bigInt &x) {
  for (int i = 1; i <= x.dat[0]; ++i) {
    out << x.dat[x.dat[0] - i + 1];
  }
  return out;
}

int n;

string sum(const string &a, const string &b) {
  string na = string(a.rbegin(), a.rend());
  string nb = string(b.rbegin(), b.rend());
  int last = 0;
  string ret;
  if (na.size() < nb.size()) {
    swap(na, nb);
  }
  for (int i = 0; i < (int)nb.size(); ++i) {
    ret.push_back((na[i] + nb[i] - 96 + last) % 10 + 48),
      last = (na[i] + nb[i] - 96 + last) / 10;
  }
  for (int i = (int)nb.size(); i < (int)na.size(); ++i) {
    ret.push_back((na[i] - 48 + last) % 10 + 48),
      last = (na[i] - 48 + last) / 10;
  }
  if (last) {
    ret.push_back(last + 48);
  }
  return string(ret.rbegin(), ret.rend());
}

string sub(const string &a, const string &b) {
  string na = string(a.rbegin(), a.rend());
  string nb = string(b.rbegin(), b.rend());
  string ret;
  for (int i = 0; i < (int)nb.size(); ++i) {
    (na[i] < nb[i]) && (na[i] += 10, --na[i + 1]),
      ret.push_back(na[i] - nb[i] + 48);
  }
  for (int i = (int)nb.size(); i < (int)na.size(); ++i) {
    (na[i] < 0) && (na[i] += 10, --na[i + 1]), ret.push_back(na[i]);
  }
  while ((int)ret.size() > 1 && ret.back() == 48) {
    ret.pop_back();
  }
  return string(ret.rbegin(), ret.rend());
}

string mul1(const string &a, const string &b) {
  string na = string(a.rbegin(), a.rend());
  string nb = string(b.rbegin(), b.rend());
  string ret;
  ret.resize(na.size() + nb.size() + 1);
  for (int i = 0; i < (int)na.size(); ++i) {
    for (int j = 0; j < (int)nb.size(); ++j) {
      ret[i + j] += (na[i] - 48) * (nb[j] - 48);
    }
  }
  for (int i = 0; i < (int)ret.size() - 1; ++i) {
    ret[i + 1] += ret[i] / 10, ret[i] %= 10;
  }
  ret.back() %= 10;
  while (ret.size() > 1 && !ret.back()) {
    ret.pop_back();
  }
  for (int i = 0; i < (int)ret.size(); ++i) {
    ret[i] += 48;
  }
  return string(ret.rbegin(), ret.rend());
}

string mul(string a, string b) {
  string ret;
  vector<int> na, nb, nc;
  int la = a.size(), lb = b.size();
  for (int i = 0; i < (la + lb); ++i) {
    nc.push_back(0);
  }
  for (int i = 0; i < la; ++i) {
    na.push_back(a[la - i - 1] - '0');
  }
  for (int i = 0; i < lb; ++i) {
    nb.push_back(b[lb - i - 1] - '0');
  }
  for (int i = 0; i < la; ++i) {
    for (int j = 0; j < lb; ++j) {
      nc[i + j] += na[i] * nb[j];
    }
  }
  for (int i = 0; i < la + lb; ++i) {
    nc[i + 1] += nc[i] / 10, nc[i] %= 10;
  }
  int retlen = la + lb - 1;
  while (!nc[retlen]) {
    --retlen;
  }
  for (int i = retlen; i >= 0; i--) {
    ret += nc[i] + '0';
  }
  return ret;
}

int cmp(const string &a, const string &b) {
  if (a.size() > b.size()) {
    return 1;
  }
  if (a.size() < b.size()) {
    return -1;
  }
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i] > b[i]) {
      return 1;
    } else if (a[i] < b[i]) {
      return -1;
    }
  }
  return 0;
}

string div1(string a, string b) {
  string ret("0"), base(b), ab("1");
  while (cmp(a, base) >= 0) {
    base.push_back('0'), ab.push_back('0');
  }
  base.pop_back(), ab.pop_back();
  while (cmp(a, b) >= 0) {
    while (cmp(a, base) >= 0) {
      a = sub(a, base), ret = sum(ret, ab);
    }
    while (cmp(base, a) > 0) {
      base.pop_back(), ab.pop_back();
    }
  }
  return ret;
}

string div(string a, string b) {
  string ret = "0", base = b, ab = "1";
  while (cmp(a, mul(base, "10")) >= 0) {
    base = mul(base, "10"), ab = mul(ab, "10");
  }
  while (cmp(a, b) >= 0) {
    while (cmp(a, base) >= 0) {
      a = sub(a, base), ret = sum(ret, ab);
    }
    base = b, ab = "1";
    while (cmp(a, mul(base, "10")) >= 0) {
      base = mul(base, "10"), ab = mul(ab, "10");
    }
  }
  return ret;
}

int main() {
  cin >> n >> a[0].l >> a[0].r;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].l >> a[i].r;
  }
  sort(a + 1, a + n + 1);
  bigInt ans, sm(a[0].l);
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, sm / a[i].r);
    sm = sm * a[i].l;
  }
  cout << ans;
  return 0;
}
