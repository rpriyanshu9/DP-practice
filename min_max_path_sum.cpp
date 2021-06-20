// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Recursive
    // int helper(int i, int j,int cur, vector<vector<int>>& a){
    //     if(i<0||i>=a.size()||j<0||j>=a[0].size()) return 0;
    //     if(i==a.size()-1) return cur+a[i][j];
    //     return max(helper(i+1,j,cur+a[i][j],a),
    //     max(helper(i+1,j-1,cur+a[i][j],a),helper(i+1,j+1,cur+a[i][j],a)));
    // }

    // int maximumPath(int N, vector<vector<int>> Matrix)
    // {
    //     int res = -1;
    //     for(int i = 0;i<Matrix[0].size();i++){
    //         res=max(helper(0,i,0,Matrix),res);
    //     }
    //     return res;
    // }

    // Memoization

    // vector<vector<int>> memo = vector<vector<int>>(101,vector<int>(101,-1));

    //     int helper(int i, int j, vector<vector<int>>& a){
    //     if(i<0||i>=a.size()||j<0||j>=a[0].size()) return 0;
    //     if(i==a.size()-1) return a[i][j];
    //     if(memo[i][j]!=-1) return memo[i][j];
    //     memo[i][j] = max(helper(i+1,j,a),
    //     max(helper(i+1,j-1,a),helper(i+1,j+1,a))) + a[i][j];
    //     return memo[i][j];

    // }

    // int maximumPath(int N, vector<vector<int>> Matrix)
    // {
    //     int res = -1;
    //     for(int i = 0;i<Matrix[0].size();i++){
    //         res=max(helper(0,i,Matrix),res);
    //     }
    //     return res;
    // }

    // Iterative
    int maximumPath(int N, vector<vector<int>> grid)
    {
        int n = grid.size(), m = grid[0].size();
        int dp[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int way1 = 0, way2 = 0, way3 = 0;
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    way1 = dp[i - 1][j - 1];
                }
                if (i - 1 >= 0)
                {
                    way2 = dp[i - 1][j];
                }
                if (i - 1 >= 0 && j + 1 < m)
                {
                    way3 = dp[i - 1][j + 1];
                }
                dp[i][j] = max(way1, max(way2, way3)) + grid[i][j];
            }
        }
        int res = -1;
        for (int j = 0; j < m; j++)
        {
            res = max(res, dp[n - 1][j]);
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
} // } Driver Code Ends