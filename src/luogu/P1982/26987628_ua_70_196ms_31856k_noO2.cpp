#include <bits/stdc++.h>
#define int long long
using namespace std;

struct NumS {
  string s;
  bool isf;
  string sum(string a, string b) {
    string ret;
    vector<int> na, nb;
    int la = a.size(), lb = b.size();
    int lmax = max(la, lb);
    for (int i = 0; i <= lmax; ++i) {
      na.push_back(0), nb.push_back(0);
    }
    for (int i = 0; i < la; ++i) {
      na[la - i - 1] = a[i] - '0';
    }
    for (int i = 0; i < lb; ++i) {
      nb[lb - i - 1] = b[i] - '0';
    }
    for (int i = 0; i < lmax; ++i) {
      na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] = na[i] % 10;
    }
    if (na[lmax]) {
      ++lmax;
    }
    for (int i = lmax - 1; i >= 0; --i) {
      ret += na[i] + '0';
    }
    return ret;
  }
  NumS operator+(NumS b) {
    if (isf == b.isf) {
      return (NumS){sum(s, b.s), isf};
    } else if (isf && !b.isf) {
      if (s.length() > b.s.length()) {
        return (NumS){sub(s, b.s), 1};
      } else {
        return (NumS){sub(b.s, s), 0};
      }
    } else {
      if (s.length() > b.s.length()) {
        return (NumS){sub(s, b.s), 0};
      } else {
        return (NumS){sub(b.s, s), 1};
      }
    }
  }
  string sub(string a, string b) {
    string ret;
    vector<int> na, nb;
    int la = a.size(), lb = b.size();
    int lmax = max(la, lb);
    for (int i = 0; i <= lmax; ++i) {
      na.push_back(0), nb.push_back(0);
    }
    for (int i = 0; i < la; ++i) {
      na[la - i - 1] = a[i] - '0';
    }
    for (int i = 0; i < lb; ++i) {
      nb[lb - i - 1] = b[i] - '0';
    }
    for (int i = 0; i < lmax; ++i) {
      na[i] -= nb[i];
      if (na[i] < 0) {
        na[i] += 10, --na[i + 1];
      }
    }
    while (!na[lmax] && lmax > 0) {
      --lmax;
    }
    ++lmax;
    for (int i = lmax - 1; i >= 0; --i) {
      ret += na[i] + '0';
    }
    return ret;
  }
  NumS operator-(NumS b) {
    if ((s.length() == b.s.length() && b.s > s) || s.length() < b.s.length()) {
      return (NumS){sub(b.s, s), 1};
    }
    return (NumS){sub(s, b.s), 0};
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
  NumS operator*(NumS b) {
    if (isf ^ b.isf) {
      return (NumS){mul(s, b.s), 1};
    }
    return (NumS){mul(s, b.s), 0};
  }
  //	string faild_div(string a, string b) {
  //		int la = a.length(), lb = b.length();
  //		vector<int > na, nb, nc;
  //		NumS ret = (NumS){"0", 0};
  //		for(int i = 0; i < la; ++i) na.push_back(a[i] - '0');
  //	}
  bool cmp(string a, string b) {
    int la = a.length(), lb = b.length();
    if (la != lb) {
      return la > lb;
    }
    for (int i = 0; i <= la; ++i) {
      if (a[i] < b[i]) {
        return false;
      }
    }
    return true;
  }
  bool operator==(NumS b) {
    if (isf != b.isf) {
      return false;
    }
    return s == b.s;
  }
  bool operator==(int ib) {
    NumS b;
    b = ib;
    if (isf != b.isf) {
      return false;
    }
    return s == b.s;
  }
  bool operator>(NumS b) {
    if ((NumS){s, isf} == b) {
      return false;
    }
    if (isf && !b.isf) {
      return true;
    }
    if (!isf && b.isf) {
      return false;
    }
    if (!isf && !b.isf) {
      return cmp(b.s, s);
    }
    return cmp(s, b.s);
  }
  bool operator<(NumS b) {
    if ((NumS){s, isf} == b) {
      return false;
    }
    if (isf && !b.isf) {
      return false;
    }
    if (!isf && b.isf) {
      return true;
    }
    if (!isf && !b.isf) {
      return cmp(s, b.s);
    }
    return cmp(b.s, s);
  }
  bool operator<=(NumS b) {
    if ((NumS){s, isf} == b) {
      return true;
    }
    return (NumS){s, isf} < b;
  }
  bool operator>=(NumS b) {
    if ((NumS){s, isf} == b) {
      return true;
    }
    return (NumS){s, isf} > b;
  }
  string div(string a, string b) {
    NumS ret = (NumS){"0", 0}, na = (NumS){a, 0}, nb = (NumS){b, 0};
    while (na > nb) {
      na = na - nb, ret += (NumS){"1", 0};
    }
    return ret.s;
  }
  void operator=(int x) {
    s.clear();
    if (x < 0) {
      isf = 1, x = -x;
    } else {
      isf = 0;
    }
    int nx[20], cnt = 0;
    while (x) {
      nx[++cnt] = x % 10;
      x /= 10;
    }
    for (int i = 1; i <= cnt; ++i) {
      s.push_back(nx[cnt - i + 1] + '0');
    }
  }
  NumS operator/(NumS b) {
    NumS ret = (NumS){"", 0}, a = (NumS){s, isf};
    while (a < b) {
      a = a - b, ret = ret + (NumS){"1", 0};
    }
    // return (NumS){div(s, b.s), isf ^ b.isf};
    ret.isf = isf ^ b.isf;
    return ret;
  }
  void operator+=(NumS b) {
    NumS tmp = (NumS){s, isf} + b;
    s = tmp.s;
    isf = tmp.isf;
  }
  void operator+=(int ib) {
    NumS b;
    b = ib;
    NumS tmp = (NumS){s, isf} + b;
    s = tmp.s;
    isf = tmp.isf;
  }
  void operator-=(NumS b) {
    NumS tmp = (NumS){s, isf} - b;
    s = tmp.s;
    isf = tmp.isf;
  }
  void operator-=(int ib) {
    NumS b;
    b = ib;
    NumS tmp = (NumS){s, isf} - b;
    s = tmp.s;
    isf = tmp.isf;
  }
  void operator*=(NumS b) {
    NumS tmp = (NumS){s, isf} * b;
    s = tmp.s;
    isf = tmp.isf;
  }
  void operator*=(int ib) {
    NumS b;
    b = ib;
    NumS tmp = (NumS){s, isf} * b;
    s = tmp.s;
    isf = tmp.isf;
  }
  void read() {
    char ch;
    while (!isdigit(ch = getchar()) && ch != '-')
      ;
    if (ch == '-') {
      isf = 1;
    } else {
      s.push_back(ch), isf = 0;
    }
    while (isdigit(ch = getchar())) {
      s.push_back(ch);
    }
  }
  void print() {
    if (!s.length()) {
      cout << '0';
    }
    if (isf) {
      cout << '-';
    }
    cout << s;
  }
};

int n, m;
int a[1000010], b[1000010];
int f[1000010], t[1000010];
int mod;

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int min(int x, int y) {
  return x < y ? x : y;
}

int max(int x, int y) {
  return x > y ? x : y;
}

signed main() {
  n = read(), mod = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  int maxn = -1;
  for (int i = 1; i <= n; ++i) {
    b[i] = max(a[i], a[i] + b[i - 1]);
    maxn = max(maxn, b[i]);
    t[i] = maxn;
  }
  f[1] = t[1], f[2] = f[1] + t[1];
  maxn = max(f[1], f[2]);
  bool fl = 0;
  for (int i = 3; i <= n; ++i) {
    if (f[i - 1] + t[i - 1] < 0 && f[i - 1] > 0) {
      fl = 1;
    }
    if (fl) {
      f[i] = f[i - 1] % mod + t[i - 1] % mod;
    } else {
      f[i] = max(f[i - 1], f[i - 1] + t[i - 1]);
    }
    maxn = max(maxn, f[i]) % mod;
  }
  print(maxn % mod);
  return 0;
}
