class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for(auto i : nums) ret += !(to_string(i).size() & 1);
        return ret;
    }
};