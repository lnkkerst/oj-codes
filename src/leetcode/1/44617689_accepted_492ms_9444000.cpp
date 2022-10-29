class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ret;
    int len = (int)nums.size();
    bool fl = 0;
    for (int i = 0; i < len; ++i)
      if (fl)
        break;
      else
        for (int j = 0; j < len; ++j)
          if (i == j)
            continue;
          else if (nums[i] + nums[j] == target) {
            ret.push_back(i), ret.push_back(j);
            fl = 1;
            break;
          }
    return ret;
  }
};
