// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
//     int l, r;
// } a[1001];

// struct BigNum {
//     int data[100];
//     int len;
//     BigNum() {
//         len = 0;
//     }
//     void read() {
//         char ch;
//         while(!isdigit(ch = getchar));
//         for(data[++len] = ch - '0'; )
//     }
//     void print() {
//         for(int i = 1; i <= len; ++i) putchar()
//     }
//     BigNum operator-(const BigNum &b) {
//         BigNum ret;

//     }
// }

// int n;

// bool cmp(Node a, Node b) {
//     if(a.l == b.l) return a.r < b.r;
//     return a.l < b.l;
// }

// int main() {
//     cin >> n >> a[0].l >> a[0].r;
//     for(int i = 1; i <= n; ++i) cin >> a[i].l >> a[i].r;
//     sort(a + 1, a + n + 1, cmp);
//     int ans = -1, sum = a[0].l;
//     for(int i = 1; i <= n; ++i) {
//         ans = max(ans, sum / a[i].r);
//         sum *= a[i].l;
//     }
//     printf("%d", ans);
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
  int l, r;
} a[1001];

int n;

bool cmp(Node a, Node b) {
  return a.l * a.r < b.l * b.r;
}

#undef int
int main() {
#define int long long
  cin >> n >> a[0].l >> a[0].r;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].l >> a[i].r;
  }
  sort(a + 1, a + n + 1, cmp);
  int ans = -1, sum = a[0].l;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, sum / a[i].r);
    sum *= a[i].l;
  }
  cout << ans;
  return 0;
}
