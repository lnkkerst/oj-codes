class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ret;
        for(auto i : nums) {
            int t = 0;
            for(auto j : nums)
                t += i > j;
            ret.push_back(t);
        }
        return ret;
    }
};