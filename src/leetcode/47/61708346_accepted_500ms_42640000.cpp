class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ret;
    vector<int> tmp;
    unordered_map<string, bool> b;
    for (int i = 0; i < (int)nums.size(); ++i) {
      tmp.push_back(i);
    }
    do {
      vector<int> t;
      string tt;
      for (auto i : tmp) {
        t.push_back(nums[i]), tt += nums[i] + ' ';
      }
      if (b[tt]) {
        continue;
      }
      ret.push_back(t);
      b[tt] = 1;
    } while (next_permutation(tmp.begin(), tmp.end()));
    return ret;
  }
};
