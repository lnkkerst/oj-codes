class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int l = 0, r = 1, tot = nums[0], ans = 0;
    while (l < r) {
      if (tot == k) {
        ++ans;
      }
      bool fl = 0;
      while (r < (int)nums.size() && tot < k) {
        tot += nums[r++], fl = 1;
      }
      // cout << tot << endl;
      if (tot == k && fl) {
        ++ans;
      }
      tot -= nums[l++];
      // cout << tot << endl;
    }
    return ans;
  }
};
