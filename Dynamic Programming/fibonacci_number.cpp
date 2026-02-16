// ================== DP (memoization approach) ============================

class Solution
{
private:
    int fib_core(int n, vector<int> &dp)
    {
        // base case
        if (n == 0 || n == 1)
            return n;

        // dp check if already present -> just return
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // if not present -> calculate
        dp[n] = fib_core(n - 1, dp) + fib_core(n - 2, dp);
        return dp[n];
    }

public:
    int fib(int n)
    {
        // initialize dp
        vector<int> dp(n + 1, -1); // dp[i] stores the value of fib(i). so, (0,1,... n) -> n+1

        return fib_core(n, dp);
    }
};

// ================== DP (tabulation approach) ============================

class Solution
{
public:
    int fib(int n)
    {
        // base case
        if (n == 0)
            return {0};
        if (n == 1)
            return {1};

        // create a vector
        vector<int> arr(n + 1);

        // step 1
        arr[0] = 0;
        arr[1] = 1;

        // step 2
        for (int i = 2; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }

        return arr[n];
    }
};

// ================== DP (tabulation + space optimization approach) ============================

class Solution
{
public:
    int fib(int n)
    {
        // base case
        if (n == 0)
            return 0;
        // if(n == 1) return 1;

        // step 1
        int prev2 = 0;
        int prev1 = 1;

        // step 2
        for (int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};