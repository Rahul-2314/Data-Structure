class Solution {
private:
    int getSum(vector<int> &nums, int n){
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        return sum;
    }

public:
    bool canPartition(vector<int>& nums) {
        // dp + tabulation + space optimization approach

        int n = nums.size();
        int total = getSum(nums, n);

        // is sum is odd -> partition impossible.
        if(total % 2 != 0){
            return false;
        }

        // vector<vector<int>> dp(n+1, vector<int>(total+1, 0));
        vector<int> curr(total+1, 0);
        vector<int> next(total+1, 0);

        // base case handling
        curr[0] = 1;
        next[0] = 1;

        for(int index=n-1; index>=0; index--){
            for(int target=0; target<=total/2; target++){

                bool include = false;

                if(target-nums[index] >= 0)
                    include = next[target-nums[index]];
                
                bool exclude = next[target-0];

                // set dp
                curr[target] = include || exclude;
            }

            next = curr;
        }

        return next[total/2];
    }
};
