#include <bits/stdc++.h>
using namespace std;

// Function to calculate factorial of a number n
// Returns the result as a vector of digits (to handle very large numbers)
vector<int> factorial_core(int n) {
    vector<int> res;
    
    // Initialize result with 1 because 0! = 1
    res.push_back(1);

    // Multiply numbers from 2 to n one by one
    for (int x = 2; x <= n; x++) {
        int carry = 0;

        // Multiply current number x with each digit in res
        for (int i = 0; i < res.size(); i++) {
            int val = res[i] * x + carry;
            res[i] = val % 10;   // Store last digit
            carry = val / 10;   // Carry forward remaining value
        }

        // Handle remaining carry
        while (carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Digits are stored in reverse order, so reverse them
    reverse(res.begin(), res.end());

    return res;
}

// Function to print the factorial of n
void factorial(int n) {
    // Get factorial digits
    vector<int> ans = factorial_core(n);

    // Print all digits
    for (int d : ans)
        cout << d;

    cout << endl;
}
