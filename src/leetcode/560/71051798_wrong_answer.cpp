class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int l = 0, r = 1, tot = nums[0], ans = 0;
        while(l < r) {
            while(r < (int)nums.size() && tot < k)
                tot += nums[r++];
            if(tot == k) ++ans;
            tot -= nums[l++];
            if(tot == k) ++ans;
        }
        return ans;
    }
};