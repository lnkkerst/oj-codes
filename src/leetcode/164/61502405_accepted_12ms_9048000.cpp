class Solution {
public:
  int maximumGap(vector<int> &nums) {
    if (nums.size() < 2) {
      return 0;
    }
    int ma = *max_element(nums.begin(), nums.end());
    int mi = *min_element(nums.begin(), nums.end());
    int blk = max(1, (ma - mi) / (int)(nums.size() - 1));
    vector<pair<int, int>> b((ma - mi) / blk + 1);
    for (auto i : nums) {
      int pos = (i - mi) / blk;
      if (!b[pos].first) {
        b[pos].first = b[pos].second = i;
      } else {
        b[pos].first = max(b[pos].first, i);
        b[pos].second = min(b[pos].second, i);
      }
    }
    int ans = INT_MIN, last = INT_MAX;
    for (auto i : b) {
      if (!i.first) {
        continue;
      }
      if (last != INT_MAX) {
        ans = max(ans, i.second - last);
      }
      last = i.first;
      ans = max(ans, i.first - i.second);
    }
    return ans;
  }
};
