#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    // calculate the maximum sum with out adjacent

    // Recursive
    // 	int findSum(int arr[],int n, int index){
    // 	    if(index<0) return 0;
    // 	    return max(arr[index]+findSum(arr,n,index-2),findSum(arr,n,index-1));
    // 	}

    // 	int findMaxSum(int *arr, int n) {
    // 	    int res=INT_MIN;
    // 	    for(int i= 0 ; i<n;i++){
    // 	        res=max(res,findSum(arr,n,i));
    // 	    }
    // 	    return res;
    // 	}

    // Memoization

    // vector<int> memo= vector<int>(1000001,-1);

    // 	int findSum(int arr[],int n, int index){
    // 	    if(index<0) return 0;
    // 	    if(memo[index]!=-1) return memo[index];
    // 	    return memo[index]= max(arr[index]+findSum(arr,n,index-2),findSum(arr,n,index-1));
    // 	}

    // int findMaxSum(int *arr, int n) {
    // 	    int res=INT_MIN;
    // 	    for(int i= 0 ; i<n;i++){
    // 	        res=max(res,findSum(arr,n,i));
    // 	    }
    // 	    return res;
    // 	}

    // Iterative
    int findMaxSum(int *arr, int n)
    {
        int dp[n];
        dp[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (i - 2 >= 0)
            {
                dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
            }
            else
            {
                dp[i] = max(arr[i], dp[i - 1]);
            }
        }
        return dp[n - 1];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends