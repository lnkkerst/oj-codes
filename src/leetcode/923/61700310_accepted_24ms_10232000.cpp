class Solution {
public:
    int superEggDrop(int K, int N) {
        int dp[10001][101] = {0};
		// for(auto i = dp.begin(); i != dp.end(); ++i)
		// 	i->resize(K + 1);
		// for(int i = 0; i <= K; ++i)
		// 	dp[1][i] = 1;
		for(int i = 0; i <= N; ++i)
			dp[i][1] = i;
		for(int i = 1; i <= N; ++i) {
			for(int j = 2; j <= K; ++j) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + 1;
			}
			if(dp[i][K] >= N) return i;
		}
		return dp[N][K];
    }
};