class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // dp + tabulation approach

        int n = days.size();

        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;


        for(int k=n-1; k>=0; k--){
            // 1 day pass
            int option1 = costs[0] + dp[k+1];

            int i;
            // 7 day pass
            for(i=k; i<n && days[i] < days[k]+7; i++);

            int option2 = costs[1] + dp[i];

            // 30 day pass
            for(i=k; i<n && days[i] < days[k]+30; i++);

            int option3 = costs[2] + dp[i];

            // set dp
            dp[k] = min({option1, option2, option3});
        }

        return dp[0];
    }
};
