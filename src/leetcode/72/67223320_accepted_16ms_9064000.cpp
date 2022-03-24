class Solution {
public:
    int minDistance(string a1, string a2) {
        vector<vector<int> > dp(a1.size() + 1, vector<int>(a2.size() + 1, 0));
        for(decltype(a1.size())i = 1; i <= a1.size(); ++i) dp[i][0] = dp[i - 1][0] + 1;
        for(decltype(a2.size())i = 1; i <= a2.size(); ++i) dp[0][i] = dp[0][i - 1] + 1;
        for(decltype(a1.size())i = 1; i <= a1.size(); ++i) {
            for(decltype(a2.size())j = 1; j <= a2.size(); ++j) {
                if(a1[i - 1] == a2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
        return dp[a1.size()][a2.size()];
    }
};