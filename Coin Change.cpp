class Solution {
public:
    const int INF = 1e8;

    int countCoins(vector<int>& coins, int amount, int sum, int i,vector<vector<int>>& dp) {
        if (sum == amount) return 0;
        if (sum > amount || i >= coins.size()) return INF;

        if (dp[i][sum] != -1) return dp[i][sum];

        int take = INF;
        if (coins[i] <= amount - sum) {
            int sub = countCoins(coins, amount, sum + coins[i], i, dp);
            if (sub != INF) take = 1 + sub;
        }

        int nottake = countCoins(coins, amount, sum, i + 1, dp);

        return dp[i][sum] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = countCoins(coins, amount, 0, 0, dp);
        return (ans >= INF) ? -1 : ans;
    }
};
