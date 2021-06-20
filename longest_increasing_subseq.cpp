/*
Problem link: https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find length of longest increasing subsequence.

    // Recursion
    // int LIS(int n , int a[], int i){
    //     if(i==0){
    //         return 1;
    //     }
    //     bool flag=0;
    //     int imax = INT_MIN;
    //     for(int j = 0 ; j<i;j++){
    //         if(a[j]<a[i]){
    //             flag=true;
    //             imax=max(imax,LIS(n,a,j));
    //         }
    //     }
    //     if(flag) return 1+imax;
    //     else return 1;
    // }

    // Memoization
    // vector<int> memo = vector<int>(100001,-1);

    // int LIS(int n , int a[], int i){
    //     if(i==0){
    //         return memo[0]= 1;
    //     }
    //     if(memo[i]!=-1){
    //         return memo[i];
    //     }
    //     bool flag=0;
    //     int imax = INT_MIN;
    //     for(int j = 0 ; j<i;j++){
    //         if(a[j]<a[i]){
    //             flag=true;
    //             imax=max(imax,LIS(n,a,j));
    //         }
    //     }
    //     if(flag) return memo[i]= 1+imax;
    //     else return  memo[i]=1;
    // }

    // Iterative
    // int longestSubsequence(int n, int a[])
    // {
    //     // Stores the LIS length ending at index i
    //     int dp[n],res=0;
    //     for(int i = 0; i<n;i++){
    //         // Minimum length is always 1
    //         dp[i]=1;
    //         // If we find a element that is less than current element
    //         // We check if we can include this and increase the length
    //         // of LIS by 1
    //         for(int j = 0 ; j< i;j++){
    //             if(a[j]<a[i]){
    //                 dp[i]=max(dp[i],dp[j]+1);
    //             }
    //         }
    //         // Updating max at every index
    //         res=max(res,dp[i]);
    //     }
    //     return res;
    // }

    // Optimized solution
    int longestSubsequence(int n, int a[])
    {
        // Intuition is whenever we obtain a new smallest element in a[]
        // It can be a potential candidate to a beginning of
        // new LIS
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(res.begin(), res.end(), a[i]);
            if (it == res.end())
                res.push_back(a[i]);
            else
                *it = a[i];
        }
        return res.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends