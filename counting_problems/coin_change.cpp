#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Iterative with O(mn) space
    // long long int count( int S[], int m, int n )
    // {
    //    vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
    //    for(int i = 0 ; i<=m;i++){
    //        dp[i][0]=1;
    //    }
    //    for(int i = 1; i<=m;i++){
    //        for(int j = 1; j<=n;j++){
    //            if(j-S[i-1]>=0){
    //                dp[i][j]=dp[i-1][j]+dp[i][j-S[i-1]];
    //            }else{
    //                dp[i][j]=dp[i-1][j];
    //            }
    //        }
    //    }
    //    return dp[m][n];
    // }

    // Iterative with O(n) space
    long long int count(int S[], int m, int n)
    {
        long long dp[n + 1] = {0};
        dp[0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j - S[i] >= 0)
                {
                    dp[j] += dp[j - S[i]];
                }
            }
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
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
} // } Driver Code Ends