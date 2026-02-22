#include <bits/stdc++.h> 

// Approach:    DP(tabulation + space optimization)
// break the problem into two subproblems
// 1. include first element exclude last one
// 2. include last element exclude first one
// return the maximum of two subproblems

long long int robberyLogic(vector<int> &valueInHouse, int start, int end){
    long long int prev2 = 0, prev1 = 0;

    for(int i=start; i<=end; i++){
        long long int incl = prev2 + valueInHouse[i];
        long long int excl = prev1 + 0;

        prev2 = prev1;
        prev1 = max(incl, excl);
    }

    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();

    if(n == 0) return 0;
    if(n == 1) return valueInHouse[0];

    long long int ansInclStart = robberyLogic(valueInHouse, 0, n-2);
    long long int ansInclLast = robberyLogic(valueInHouse, 1, n-1);

    return max(ansInclStart, ansInclLast);
}

