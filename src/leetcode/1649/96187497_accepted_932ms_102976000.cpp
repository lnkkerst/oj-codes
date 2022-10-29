class Solution {
public:
  int maxNonOverlapping(vector<int> &nums, int target) {
    int sum = 0, ans = 0;
    unordered_map<int, int> b;
    unordered_map<int, bool> bk;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (sum == target && !bk.size()) {
        for (int j = 0; j <= i; ++j) {
          bk[j] = 1;
        }
        ++ans;
      }
      if (b.find(sum - target) != b.end()) {
        int pos = b[sum - target] + 1;
        cout << pos << ' ' << i << endl;
        bool fl = 1;
        for (int j = pos; j <= i; ++j) {
          if (bk.find(j) != bk.end()) {
            fl = 0;
            break;
          }
        }
        if (fl) {
          puts("ok");
          for (int j = pos; j <= i; ++j)
            bk[j] = 1;
          ++ans;
        }
      }
      b[sum] = i;
    }
    cout << endl;
    return ans;
  }
};