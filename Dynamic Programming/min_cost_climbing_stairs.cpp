// ===================================== normal recursion ======================================
class Solution {
private:
    int solve(vector<int> &cost, int n){
        // base case
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];

        int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }


public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // logic (when reached n)
        int ans = min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
};

// ======================================= DP approach (memoization) ===========================

class Solution {
private:
    int solve(vector<int> &cost, int n, vector<int> &dp){
        // base case
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];

        // step 3
        if(dp[n] != -1) return dp[n];

        // step 2
        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return dp[n];
    }


public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // step 1
        vector<int> dp(n+1, -1);

        // logic (when reached n)
        int ans = min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return ans;
    }
};


// =============================== DP approach (tabulation) ====================================

class Solution {
private:
    int solve(vector<int> &cost, int n){
        // step 1: dp array creation
        vector<int> dp(n+1);

        // step 2: base case
        dp[0] = cost[0];
        dp[1] = cost[1];

        // step 3
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }


public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        return solve(cost, n);
    }
};


// ============================ DP approach (tabulation + space optimization) ==================

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // step 1: base case
        // if(n == 0) return cost[0];
        // if(n == 1) return cost[1];

        // step 2
        int prev1 = cost[1];
        int prev2 = cost[0];

        // step 3
        for(int i=2; i<n; i++){
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};



