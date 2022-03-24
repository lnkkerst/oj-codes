class Solution {
public:
    
    int numberWays(vector<vector<int> >& hats) {
        #define int long long
        int dp[2][1 << 10 | 1] = {0};
        bool b[41][11] = {0};
        int n = hats.size(), now = 0;
        dp[0][0] = dp[1][0] = 1;
        for(int i = 0; i < n; ++i) {
            for(auto j : hats[i])
                b[j][i] = 1;
        }
        for(int i = 1; i <= 40; ++i) {
            
            memcpy(dp[now], dp[now ^ 1], sizeof(int) * (1 << 10 | 1));
            for(int st = (1 << n) - 1; st >= 0; --st) {
                for(int j = 0; j < 10; ++j) {
                    if(b[i][j]) {
                        if(st & (1 << j)) continue;
                        int t = st + (1 << j);
                        dp[now][t] += dp[now ^ 1][st];
                        dp[now][t] %= (int)1e9 + 7;
                    }
                }
            }
            now ^= 1;
        }
        return dp[now ^ 1][(1 << n) - 1];
        #undef int
    }
    
};