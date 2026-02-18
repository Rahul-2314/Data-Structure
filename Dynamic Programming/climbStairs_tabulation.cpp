// ========================== DP (tabulation - space optimisation =============================
class Solution {
public:
    int climbStairs(int n) {
        // step 1: base case
        if(n == 0 || n == 1) return 1;

        // step 2
        int prev1 = 1;
        int prev2 = 1;

        // step 3
        for(int i=2; i<n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1 + prev2;
    }
};
