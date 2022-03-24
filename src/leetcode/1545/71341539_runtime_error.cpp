class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        string dp[5010] = {"0"};
        unordered_map<int, int> b;
        for(int i = 0; i < 9; ++i) b[cost[i]] = i + 1;
        for(int i = 1; i <= target; ++i) {
            for(auto j : b) {
                if(i >= j.first) {
                    if(dp[i - j.first].empty()) continue;
                    string nex = dp[i - j.first] + string(1, j.second + '0');
                    if(nex.length() > dp[i].length()) dp[i] = nex;
                    else if(nex.length() == dp[i].length()) {
                        if(nex > dp[i]) dp[i] = nex;
                    }
                }
            }
        }
        if(dp[target] == "0") return "0";
        return dp[target].substr(1);
    }
};