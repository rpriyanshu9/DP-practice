// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    const int MOD = 1e9 + 7;

    //Recursive
    // long long int nthFibonacci(long long int n){
    //     if(n<=2) return 1;
    //     return nthFibonacci(n-1)%MOD + nthFibonacci(n-2)%MOD;
    // }

    //Memoization
    // vector<long long> memo = vector<long long>(1001,-1);
    // long long int nthFibonacci(long long int n){
    //     if(n<=2) return 1;
    //     if(memo[n]!=-1) return memo[n];
    //     return memo[n] = (nthFibonacci(n-1)%MOD + nthFibonacci(n-2)%MOD)%MOD;
    // }

    //Iterative
    long long int nthFibonacci(long long int n)
    {
        int dp[n + 1];
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD;
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
// } Driver Code Ends