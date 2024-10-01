// #include <bits/stdc++.h>
// using namespace std;

// struct NumS {
//     string s;
//     bool isf;
// string sum(string a, string b) {
//     string ret;
//     vector<int > na, nb;
//     int la = a.size(), lb = b.size();
//     int lmax = max(la, lb);
//     for(int i = 0; i <= lmax; ++i) na.push_back(0), nb.push_back(0);
//     for(int i = 0; i < la; ++i) na[la - i - 1] = a[i] - '0';
//     for(int i = 0; i < lb; ++i) nb[lb - i - 1] = b[i] - '0';
//     for(int i = 0; i < lmax; ++i) na[i] += nb[i], na[i + 1] += na[i] / 10,
//     na[i] = na[i] % 10; if(na[lmax]) ++lmax; for(int i = lmax - 1; i >= 0;
//     --i) ret += na[i] + '0'; return ret;
// }
//     NumS operator +(NumS b) {
//         return (NumS){sum(s, b.s), 0};
//     }
//     string sub(string a, string b) {
//         string ret;
//         vector<int > na, nb;
//         int la = a.size(), lb = b.size();
//         int lmax = max(la, lb);
//         for(int i = 0; i <= lmax; ++i) na.push_back(0), nb.push_back(0);
//         for(int i = 0; i < la; ++i) na[la - i - 1] = a[i] - '0';
//         for(int i = 0; i < lb; ++i) nb[lb - i - 1] = b[i] - '0';
//         for(int i = 0; i < lmax; ++i) {na[i] -= nb[i]; if(na[i] < 0) na[i] +=
//         10, --na[i + 1];} while(!na[lmax] && lmax > 0) --lmax; ++lmax;
//         for(int i = lmax - 1; i >= 0; --i) ret += na[i] + '0';
//         return ret;
//     }
//     NumS operator -(NumS b) {
//         if((s.length() == b.s.length() && b.s > s) || s.length() <
//         b.s.length()) return (NumS){sub(b.s, s), 1}; return (NumS){sub(s,
//         b.s), 0};
//     }
//     string mul(string a, string b) {
//         string ret;
//         vector<int > na, nb, nc;
//         int la = a.size(), lb = b.size();
//         for(int i = 0; i <= (la + lb); ++i) nc.push_back(0);
//         for(int i = 0; i < la; ++i) na.push_back(a[la - i - 1] - '0');
//         for(int i = 0; i < lb; ++i) nb.push_back(b[lb - i - 1] - '0');
//         for(int i = 0; i < la; ++i) na[la - i - 1] = a[i] - '0';
//         for(int i = 0; i < lb; ++i) nb[lb - i - 1] = b[i] - '0';
//         for(int i = 0; i < la; ++i)
//             for(int j = 0; j < lb; ++j)
//                 nc[i + j] += na[i] * nb[j];
//         for(int i = 0; i < la + lb; ++i) nc[i + 1] += nc[i] / 10, nc[i] %=
//         10; int pos = la + lb - 1; while(!nc[pos]) pos--; for(int i = pos; i
//         >= 0; i--) ret += nc[i] + '0'; return ret;
//     }
//     string mullow(string a, int b) {
//         string ret;
//         int la = a.size();
//         vector<int > na;
//         for(int i = 0; i <= la + 11; ++i) na.push_back(0);
//         for(int i = 0; i < la; ++i) na[la - i - 1] = a[i];
//         int w = 0;
//         for(int i = 0; i < la; ++i) na[i] = na[i] * b + w, w = na[i] / 10,
//         na[i] %= 10; while(w) na[la++] = w % 10, w /= 10;
//         --la;
//         while(la >= 0) ret += na[la--] + '0';
//         s = ret;
//     }

//     NumS operator *(NumS b) {
//         if(isf == b.isf) return (NumS){mul(s, b.s), 0};
//         return (NumS){mul(s, b.s), 0};
//     }
//     void operator*=(int n) {
//         mullow(s, n);
//     }
//     void read() {
//         char ch;
//         while(!isdigit(ch = getchar()) && ch != '-');
//         if(ch == '-') isf = 1;
//         else s.push_back(ch), isf = 0;
//         while(isdigit(ch = getchar())) s.push_back(ch);
//     }
//     void print() {
//         ios::sync_with_stdio(0);
//         if(isf) cout << '-';
//         cout << s;
//     }
// } ;

// int main() {
//     ios::sync_with_stdio(0);
//     NumS ans;
//     ans.read();
//     ans *= 2;
//     ans.print();
//     ans.isf = 0;
//     ans.s.clear();
//     ans.s[1] = '1';
//     int n;
//     cin >> n;
//     for(int i = 1; i <= n; ++i)
//         ans *= i;
//     ans.print();
// }

#include <bits/stdc++.h>
using namespace std;

string mul(string a, int b) {
  string ret;
  vector<int> na;
  int la = a.size();
  for (int i = 0; i <= la + 110; ++i) {
    na.push_back(0);
  }
  for (int i = 0; i < la; ++i) {
    na[la - i - 1] = a[i] - '0';
  }
  int w = 0;
  for (int i = 0; i < la; ++i) {
    na[i] = na[i] * b + w, w = na[i] / 10, na[i] %= 10;
  }
  while (w) {
    na[++la] = w % 10, w /= 10;
  }
  la--;
  while (la >= 0) {
    ret += na[la--] + '0';
  }
  return ret;
}

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

// int na[100000];
// string mul(string a, int b) {
//     string ret;
//     int la = a.size();
//     memset(na, 0, sizeof(na));
//     for(int i = la - 1; i >= 0; --i) na[la - i - 1] = a[i] - '0';
//     int w = 0;
//     for(int i = 0; i < la; ++i) na[i] = na[i] * b + w, w = na[i] / 10, na[i]
//     = na[i] % 10; while(w) na[la++] = w % 10,  w /= 10; la--; while(la >= 0)
//     ret += na[la--] + '0'; return ret;
// }

int main() {
  int n;
  string a, ans;
  cin >> n;
  a.push_back('1');
  ans.push_back('0');
  for (int i = 1; i <= n; ++i) {
    a = mul(a, i), ans = sum(ans, a);
  }
  cout << ans;
  return 0;
}
