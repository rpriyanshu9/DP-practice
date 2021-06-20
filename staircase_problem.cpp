#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to count number of ways to reach the nth stair.

    const int MOD = 1e9 + 7;

    //Recursive
    // int countWays(int n)
    // {
    //     if(n<=3) return n;
    //     return countWays(n-1)+countWays(n-2);
    // }

    //Memoization
    // vector<int> memo = vector<int>(100001,-1);

    // int countWays(int n)
    // {
    //     if(n<=3) return n;
    //     if(memo[n]!=-1) return memo[n];
    //     return memo[n]=((countWays(n-1)%MOD)+(countWays(n-2)%MOD))%MOD;
    // }

    //Iterative
    int countWays(int n)
    {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = ((dp[i - 1] % MOD) + (dp[i - 2] % MOD)) % MOD;
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends