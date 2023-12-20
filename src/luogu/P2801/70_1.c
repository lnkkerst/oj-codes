#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000005
#define MAXB 3200
#define int long long

int a[MAXN];
int plus[MAXB];
int sd[MAXB][MAXB];
int BSZ, BLK;

int get_blk(int x) { return x / BSZ; }

void sort_blk(int x) {
  int l = x * BSZ, r = fmin(MAXN - 1, (x + 1) * BSZ - 1);
  int sz = 0;
  for (int i = l; i <= r; ++i) {
    if (i < MAXN) {
      sd[x][sz++] = a[i];
    }
  }
  for (int i = 0; i < sz; ++i) {
    for (int j = i + 1; j < sz; ++j) {
      if (sd[x][i] > sd[x][j]) {
        int temp = sd[x][i];
        sd[x][i] = sd[x][j];
        sd[x][j] = temp;
      }
    }
  }
}

int query(int l, int r, int x) {
  int lk = get_blk(l), rk = get_blk(r);
  int res = 0;
  if (lk == rk) {
    for (int i = l; i <= r; ++i) {
      res += (a[i] + plus[get_blk(i)]) < x;
    }
    return res;
  }
  for (int i = l; i <= (lk + 1) * BSZ - 1; ++i) {
    res += (a[i] + plus[get_blk(i)]) < x;
  }
  for (int i = lk + 1; i <= rk - 1; ++i) {
    int left = 0, right = BSZ;
    while (left < right) {
      int mid = (left + right) / 2;
      if (sd[i][mid] < x - plus[i]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    res += left;
  }
  for (int i = rk * BSZ; i <= r; ++i) {
    res += (a[i] + plus[get_blk(i)]) < x;
  }
  return res;
}

void add(int l, int r, int x) {
  int lk = get_blk(l), rk = get_blk(r);
  if (lk == rk) {
    for (int i = l; i <= r; ++i) {
      a[i] += x;
    }
    sort_blk(lk);
    return;
  }
  for (int i = l; i <= (lk + 1) * BSZ - 1; ++i) {
    a[i] += x;
  }
  sort_blk(lk);
  for (int i = lk + 1; i <= rk - 1; ++i) {
    plus[i] += x;
  }
  for (int i = rk * BSZ; i <= r; ++i) {
    a[i] += x;
  }
  sort_blk(rk);
}

void solve() {
  int n, q;
  scanf("%lld %lld", &n, &q);
  BSZ = sqrt(n);
  BLK = (n + BSZ - 1) / BSZ;

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }

  for (int i = 0; i < n; ++i) {
    sd[get_blk(i)][i % BSZ] = a[i];
  }

  for (int i = 0; i < BLK; ++i) {
    sort_blk(i);
  }

  for (int i = 0; i < q; ++i) {
    char opt;
    int l, r, c;
    scanf(" %c %lld %lld %lld", &opt, &l, &r, &c);
    if (opt == 'M') {
      add(l - 1, r - 1, c);
    } else {
      printf("%lld\n", r - l + 1 - query(l - 1, r - 1, c));
    }
  }
}

signed main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
