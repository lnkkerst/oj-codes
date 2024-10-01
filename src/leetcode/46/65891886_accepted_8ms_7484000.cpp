class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ret;
    vector<int> tmp;
    for (int i = 0; i < (int)nums.size(); ++i) {
      tmp.push_back(i);
    }
    do {
      vector<int> t;
      for (auto i : tmp) {
        t.push_back(nums[i]);
      }
      ret.push_back(t);
    } while (next_permutation(tmp.begin(), tmp.end()));
    return ret;
  }
};
