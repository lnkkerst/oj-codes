#include <iostream>
using namespace std;

int heap[1000010], cnt = 0;

void pushup(int i) {
  if (i == 1) {
    return;
  }
  if (heap[i] < heap[i >> 1]) {
    swap(heap[i], heap[i >> 1]);
    pushup(i >> 1);
  }
}

void pushdown(int i) {
  if ((i << 1) > cnt) {
    return;
  }
  int t = i << 1;
  if ((t | 1) <= cnt && heap[t | 1] < heap[t]) {
    t |= 1;
  }
  if (heap[t] < heap[i]) {
    swap(heap[t], heap[i]);
    pushdown(t);
  }
}

void add(int x) {
  heap[++cnt] = x;
  pushup(cnt);
}

void del() {
  heap[1] = heap[cnt--];
  pushdown(1);
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int q;
    cin >> q;
    if (q == 1) {
      int x;
      cin >> x;
      add(x);
    }
    if (q == 2) {
      cout << heap[1] << endl;
    }

    if (q == 3) {
      del();
    }
  }
  return 0;
}