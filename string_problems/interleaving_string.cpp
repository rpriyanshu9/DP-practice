#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    /*You are required to complete this method */

    // Recursive
    // bool ok(int i, int j ,int k, string s1,string s2, string s3){
    //     if(i>=s1.length()&&j>=s2.length()) return true;
    //     if(i>=s1.length()){
    //         if(s2[j]!=s3[k]) return false;
    //         else return ok(i,j+1,k+1,s1,s2,s3);
    //     }
    //     if(j>=s2.length()){
    //         if(s1[i]!=s3[k]) return false;
    //         else return ok(i+1,j,k+1,s1,s2,s3);
    //     }
    //     if(k>s3.length()){
    //         return false;
    //     }
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
    vector<vector<vector<int>>> memo = vector<vector<vector<int>>>(101, vector<vector<int>>(101, vector<int>(101, -1)));

    bool ok(int i, int j, int k, string s1, string s2, string s3)
    {
        if (i >= s1.length() && j >= s2.length())
            return true;
        if (memo[i][j][k] != -1)
            return memo[i][j][k];
        if (i >= s1.length())
        {
            if (s2[j] != s3[k])
                return memo[i][j][k] = false;
            else
                return memo[i][j][k] = ok(i, j + 1, k + 1, s1, s2, s3);
        }
        if (j >= s2.length())
        {
            if (s1[i] != s3[k])
                return memo[i][j][k] = false;
            else
                return memo[i][j][k] = ok(i + 1, j, k + 1, s1, s2, s3);
        }
        if (k > s3.length())
        {
            return memo[i][j][k] = false;
        }
        if (s1[i] == s3[k] && s2[j] != s3[k])
        {
            return memo[i][j][k] = ok(i + 1, j, k + 1, s1, s2, s3);
        }
        else if (s1[i] != s3[k] && s2[j] == s3[k])
        {
            return memo[i][j][k] = ok(i, j + 1, k + 1, s1, s2, s3);
        }
        else if (s1[i] == s3[k] && s2[j] == s3[k])
        {
            return memo[i][j][k] = ok(i + 1, j, k + 1, s1, s2, s3) || ok(i, j + 1, k + 1, s1, s2, s3);
        }
        else
        {
            return memo[i][j][k] = false;
        }
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;
        int i = 0, j = 0, k = 0;
        return ok(i, j, k, s1, s2, s3);
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