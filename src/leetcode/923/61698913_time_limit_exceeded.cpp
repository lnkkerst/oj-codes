class Solution {
public:
    int superEggDrop(int K, int N) {
		vector<vector<int> > dp;
		dp.resize(N + 1);
		for(auto i = dp.begin(); i != dp.end(); ++i)
			i->resize(K + 1);
		for(int i = 0; i <= K; ++i)
			dp[1][i] = 1;
		for(int i = 0; i <= N; ++i)
			dp[i][1] = i;
		for(int i = 1; i <= N; ++i) {
			for(int j = 2; j <= K; ++j) {
				dp[i][j] = max(dp[0][j - 1], dp[i - 1][j]) + 1;
				for(int k = 2; k <= i; ++k)
					dp[i][j] = min(dp[i][j], max(dp[k - 1][j - 1], dp[i - k][j]) + 1);
			}
		}
		return dp[N][K];
    }
};