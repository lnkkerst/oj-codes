class Solution {
public:
    int minCount(vector<int>& coins) {
        int ret = 0;
        for(auto i : coins)
            ret += (i + 1) >> 1;
        return ret;
    }
};