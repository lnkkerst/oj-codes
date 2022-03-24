class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ret;
        for(int i = 0; i < (int)nums.size(); i += 2)
            for(int j = 1; j <= nums[i]; ++j)
                ret.push_back(nums[i + 1]);
        return ret;
    }
};