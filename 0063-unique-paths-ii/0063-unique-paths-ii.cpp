class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        // Nếu ô bắt đầu là chướng ngại vật
        if (obstacleGrid[0][0] == 1)
            return 0;

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Nếu là chướng ngại vật
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                // Lấy từ ô phía trên
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];

                // Lấy từ ô bên trái
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};