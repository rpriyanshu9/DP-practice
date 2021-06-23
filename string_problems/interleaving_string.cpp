#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    /*You are required to complete this method */

    // Recursive
    // bool helper(int i, int j ,int k, string s1,string s2, string s3){
    //     if(i>=s1.length()&&j>=s2.length()) return true;
    //     if(s1[i]==s3[k]&&s2[j]!=s3[k]){
    //         return ok(i+1,j,k+1,s1,s2,s3);
    //     }else if(s1[i]!=s3[k]&&s2[j]==s3[k]){
    //         return ok(i,j+1,k+1,s1,s2,s3);
    //     }else if(s1[i]==s3[k]&&s2[j]==s3[k]){
    //         return ok(i+1,j,k+1,s1,s2,s3)||ok(i,j+1,k+1,s1,s2,s3);
    //     }else{
    //         return false;
    //     }
    // }

    // Memoization
    // vector<vector<int>> memo = vector<vector<int>>(101, vector<int>(101, -1));

    // bool helper(int i, int j, int k, string s1, string s2, string s3)
    // {
    //     if (i >= s1.length() && j >= s2.length())
    //         return true;
    //     if (memo[i][j] != -1)
    //         return memo[i][j];
    //     if (s1[i] == s3[k] && s2[j] != s3[k])
    //     {
    //         return memo[i][j] = helper(i + 1, j, k + 1, s1, s2, s3);
    //     }
    //     else if (s1[i] != s3[k] && s2[j] == s3[k])
    //     {
    //         return memo[i][j] = helper(i, j + 1, k + 1, s1, s2, s3);
    //     }
    //     else if (s1[i] == s3[k] && s2[j] == s3[k])
    //     {
    //         return memo[i][j] = helper(i + 1, j, k + 1, s1, s2, s3) || helper(i, j + 1, k + 1, s1, s2, s3);
    //     }
    //     else
    //     {
    //         return memo[i][j] = false;
    //     }
    // }

    // Iterative
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        bool dp[n1 + 1][n2 + 1];
        for (int i = 0; i <= n1; i++)
        {
            for (int j = 0; j <= n2; j++)
            {
                // both s1 and s2 are empty
                // so we consider s3 of length 0
                // which is true always
                if (i == 0 && j == 0)
                    dp[i][j] = 1;

                // if s1 is empty, we check for chars in s2 and s3
                // upto length of s3,
                // if current char of s2 is equal to current char of s3
                // and the remaining chars of s2 also obey the same property
                // only then it is true
                else if (i == 0)
                {
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }

                // Similiarly for when s2 is empty
                else if (j == 0)
                {

                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }

                // we check if the string s3 of length (i+j) can be made from any of the
                // two strings s1 and s2
                else
                {
                    dp[i][j] = ((dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]));
                }
            }
        }

        // Represents if the string s3 is an interleaved string
        // made from s1 and s2 of lengths n1 and n2 respectively
        return dp[n1][n2];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        cout << obj.isInterleave(a, b, c) << endl;
    }
    // your code goes here
    return 0;
} // } Driver Code Ends