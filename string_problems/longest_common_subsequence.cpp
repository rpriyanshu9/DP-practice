#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    // Recursive
    // int ok(int i,int j,int n1,int n2,string s1, string s2){
    //     if(i>=n1||j>=n2){
    //         return 0;
    //     }
    //     if(s1[i]==s2[j]){
    //         return 1+ok(i+1,j+1,n1,n2,s1,s2);
    //     }else{
    //         return max(ok(i+1,j,n1,n2,s1,s2),ok(i,j+1,n1,n2,s1,s2));
    //     }
    // }
    
    // Memoization
    // vector<vector<int>> memo= vector<vector<int>>(1001,vector<int>(1001,-1));
    
    // int ok(int i,int j,int n1,int n2,string s1, string s2){
    //     if(i>=n1||j>=n2){
    //         return 0;
    //     }
    //     if(memo[i][j]!=-1) return memo[i][j];
    //     if(s1[i]==s2[j]){
    //         return memo[i][j]= 1+ok(i+1,j+1,n1,n2,s1,s2);
    //     }else{
    //         return memo[i][j] = max(ok(i+1,j,n1,n2,s1,s2),ok(i,j+1,n1,n2,s1,s2));
    //     }
    // }
    
    // Iterative
    
    int lcs(int x, int y, string s1, string s2)
    {
        int dp[x+1][y+1];
        for(int i = 0;i<=x;i++){
            for(int j = 0;j<=y;j++){
                if(i==0||j==0) dp[i][j]=0;
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends