class Solution {
public:
  vector<int> singleNumbers(vector<int> &nums) {
    unordered_set<int> a;
    for (auto &i : nums) {
      auto t = a.find(i);
      if (t == a.end())
        a.insert(i);
      else
        a.erase(t);
    }
    return vector<int>(a.begin(), a.end());
  }
};