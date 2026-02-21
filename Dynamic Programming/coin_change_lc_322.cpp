================================================= normal recursion approach ============================================

class Solution {
private:
    int solveRec(vector<int> &coins, int amount){
        // base case
        if(amount == 0) return 0;

        if(amount < 0) return INT_MAX;

        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solveRec(coins, amount-coins[i]);

            if(ans != INT_MAX){
                mini = min(mini, ans+1);    //+1 considering current coin
            }
        }

        return mini;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = solveRec(coins, amount);
    
        if(ans == INT_MAX){
            return -1;
        }
        else return ans;
    }
};  


================================================= dp (memoization) approach ============================================

class Solution {
private:
    int solveMem(vector<int> &coins, int amount, vector<int> &dp){
        // base case
        if(amount == 0) return 0;

        if(amount < 0) return INT_MAX;
        
        // dp check
        if(dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solveMem(coins, amount-coins[i], dp);

            if(ans != INT_MAX){
                mini = min(mini, ans+1);    //+1 considering current coin
            }
        }
        // set dp
        dp[amount] = mini;

        return mini;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        // using memoization
        vector<int> dp(amount+1, -1);
        int ans = solveMem(coins, amount, dp);
    
        if(ans == INT_MAX){
            return -1;
        }
        else return ans;
    }
};


================================================= dp (tabulation) approach ============================================


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);

        // base case
        dp[0] = 0;

        for(int i=1; i<=amount; i++){
            // try to solve for all numbers from 0 to amount

            for(int j=0; j<coins.size(); j++){
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }

        if(dp[amount] == INT_MAX){
            return -1;
        }
        else return dp[amount];
    }
};

==================================== Why Tabulation + Space Optimization is NOT Possible ? =================================

In Coin Change… =>
dp[i] = min(dp[i - coin1], dp[i - coin2], dp[i - coin3], ...)

That means:
- dp[i] depends on multiple previous states
- Those states can be far apart (not fixed offsets like i-1, i-2)

Why space optimization fails :
- You don’t know which dp[i - coin] will be needed next
- Overwriting values will break future calculations
- Full dp[] array is required to maintain correctness

=> Hence, space optimization to O(1) is NOT possible.

🧠 One-Line Interview Explanation =>
- “Coin Change uses DP where each amount depends on multiple previous states, so unlike Fibonacci-style problems, space optimization isn’t possible.” 💡





