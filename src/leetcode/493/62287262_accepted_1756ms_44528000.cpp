class Solution {
public:
  void msort(int l, int r, vector<int> &a, vector<int> &b) {
    if (l == r) {
      return;
    }
    int mid = (l + r) >> 1;
    msort(l, mid, a, b);
    msort(mid + 1, r, a, b);
    int i = l, j = mid + 1, t = l;
    while (i <= mid && j <= r) {
      if (a[i] <= a[j]) {
        b[t++] = a[i++];
      } else {
        b[t++] = a[j++];
      }
    }
    while (i <= mid) {
      b[t++] = a[i++];
    }
    while (j <= r) {
      b[t++] = a[j++];
    }
    for (int i = l; i <= r; ++i) {
      a[i] = b[i];
    }
  }
  int solve(int l, int r, vector<int> &a, vector<int> &b) {
    if (l >= r) {
      return 0;
    }
    int mid = (l + r) >> 1;
    int ret = solve(l, mid, a, b) + solve(mid + 1, r, a, b);
    int j = mid + 1;
    for (int i = l; i <= mid; ++i) {
      while (j <= r && a[i] > a[j] * 2ll) {
        ++j;
      }
      ret += j - (mid + 1);
    }
    msort(l, r, a, b);
    return ret;
  }
  int reversePairs(vector<int> &nums) {
    vector<int> b(nums.size() + 10);
    return solve(0, nums.size() - 1, nums, b);
  }
};
