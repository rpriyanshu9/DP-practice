#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    // Recursive
    // void jump(int index, int curr, int arr[], int n, int& res){
    //     if(index>=n){
    //         return;
    //     }
    //     if(index==n-1){
    //         res=min(res,curr);
    //         return;
    //     }
    //     for(int i = 1; i<=arr[index];i++){
    //         jump(index+i,curr+1,arr,n,res);
    //     }
    // }

    // Iterative
    int minJumps(int arr[], int n)
    {
        vector<int> dp(n, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= arr[i]; j++)
            {
                if (i + j < n)
                {
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
                }
            }
        }
        return dp[n - 1] == INT_MAX - 1 ? -1 : dp[n - 1];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends