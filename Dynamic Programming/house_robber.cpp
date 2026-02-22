// House Robber problem (max_sum_of_non_adjacent_elements)


// ======================================== normal recursion approach ======================================

class Solution {
private:
    int solve(vector<int> &nums, int n){
        // base case
        if(n < 0) return 0;
        if(n == 0) return nums[0];
        
        // right to left traversal
        int incl = solve(nums, n-2) + nums[n];
        int excl = solve(nums, n-1) + 0;
        
        return max(incl, excl);
    }

public:
    int rob(vector<int>& nums) {
        // there are two possibilities for every elements - include/exclude
        // if include, i -> i+2 and sum = sum + current element
        // if exclude, i -> i+1 and sum = sum + 0
        
        int n = nums.size();
        int ans = solve(nums, n-1);
        
        return ans;
    }
};

// ======================================== DP + memoization approach ======================================

class Solution {
private:
    int solveMem(vector<int> &nums, int n, vector<int> &dp){
        // base case
        if(n < 0) return 0;
        if(n == 0) return nums[0];

        // check dp
        if(dp[n] != -1) return dp[n];
        
        // right to left traversal
        int incl = solveMem(nums, n-2, dp) + nums[n];
        int excl = solveMem(nums, n-1, dp) + 0;

        // set dp
        dp[n] = max(incl, excl);
        
        return dp[n];
    }

public:
    int rob(vector<int>& nums) {
        // there are two possibilities for every elements - include/exclude
        // if include, i -> i+2 and sum = sum + current element
        // if exclude, i -> i+1 and sum = sum + 0
        // using dp (memoization approach)
        
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = solveMem(nums, n-1, dp);
        
        return ans;
    }
};


// ======================================== DP + tabulation approach ======================================

class Solution {
public:
    int rob(vector<int>& nums) {
        // there are two possibilities for every elements - include/exclude
        // if include, i -> i+2 and sum = sum + current element
        // if exclude, i -> i+1 and sum = sum + 0
        // using dp (tabulation approach)
        
        int n = nums.size();
        vector<int> dp(n, 0);


        // base case
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++){
            int incl = dp[i-2] + nums[i];
            int excl = dp[i-1] + 0;

            dp[i] = max(incl, excl);
        }

        return dp[n-1];
    }
};

// ======================================== normal recursion approach ======================================

class Solution {
public:
    int rob(vector<int>& nums) {
        // there are two possibilities for every elements - include/exclude
        // if include, i -> i+2 and sum = sum + current element
        // if exclude, i -> i+1 and sum = sum + 0
        // using dp (tabulation + space optimization approach)
        
        int n = nums.size();

        // base case
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        
        for(int i=2; i<n; i++){
            int incl = prev2 + nums[i];
            int excl = prev1 + 0;

            prev2 = prev1;
            prev1 = max(incl, excl);
        }

        return prev1;
    }
};



