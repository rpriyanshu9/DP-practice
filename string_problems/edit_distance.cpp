#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Recursive
    // int helper(int i, int j , int n1, int n2, string s1, string s2){
    //     if(j==n2){
    //         return n1-i;
    //     }
    //     if(i==n1){
    //         return n2-j;
    //     }
    //     if(s1[i]==s2[j]){
    //         return helper(i+1,j+1,n1,n2,s1,s2);
    //     }else{
    //         int insert_ = helper(i,j+1,n1,n2,s1,s2);
    //         int remove_ =helper(i+1,j,n1,n2,s1,s2);
    //         int replace_ =helper(i+1,j+1,n1,n2,s1,s2);
    //         return 1+min(insert_,min(remove_,replace_));
    //     }
    // }

    // Memoization
    // vector<vector<int>> memo = vector<vector<int>>(101,vector<int>(101,-1));

    // int helper(int i, int j , int n1, int n2, string s1, string s2){
    //     if(j==n2){
    //         return n1-i;
    //     }
    //     if(i==n1){
    //         return n2-j;
    //     }
    //     if(memo[i][j]!=-1) return memo[i][j];
    //     if(s1[i]==s2[j]){
    //         return memo[i][j] = helper(i+1,j+1,n1,n2,s1,s2);
    //     }else{
    //         int insert_ = helper(i,j+1,n1,n2,s1,s2);
    //         int remove_ =helper(i+1,j,n1,n2,s1,s2);
    //         int replace_ =helper(i+1,j+1,n1,n2,s1,s2);
    //         return memo[i][j]=  1+min(insert_,min(remove_,replace_));
    //     }
    // }

    // Iterative
    int editDistance(string s, string t)
    {
        int n1 = s.length(), n2 = t.length();
        int dp[n1 + 1][n2 + 1];
        for (int i = 0; i <= n2; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n1][n2];
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends