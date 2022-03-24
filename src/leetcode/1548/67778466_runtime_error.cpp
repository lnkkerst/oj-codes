class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> pos;
        for(size_t i = 0; i < nums.size(); ++i)
            if(nums[i]) pos.push_back(i);
        int last = pos[0];
        for(size_t i = 1; i < pos.size(); ++i) {
            if(pos[i] - last <= k) return 0;
            last = pos[i];
        }
        return 1;
    }
};