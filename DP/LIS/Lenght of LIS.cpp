//Recursive Solution
int solve(int i,int size,int prev,vector<int> & arr,vector<vector<int>> & dp){
    if(i == arr.size()){
        return size;
    }
    if(dp[i][size] == -1){
        if(arr[i] > prev)
            return max(solve(i+1,size+1,arr[i],arr,dp), solve(i+1,size,prev,arr,dp));
        else
            return solve(i+1,size,prev,arr,dp);
    }
    return dp[i][size];
}
int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return solve(0,0,INT_MIN,arr,dp);
}


// Memoaization
class Solution {
public:
    int solve(int i,int prev_ind,vector<int> & arr,vector<vector<int>> & dp){
        if(i == arr.size()){
            return 0;
        }
        if(dp[i][prev_ind+1] == -1){
            int notTake = solve(i+1, prev_ind,arr,dp);
            int take = 0;
            if(prev_ind == -1 || arr[i] > arr[prev_ind]){
                take = solve(i+1,i,arr,dp)+1;
            }
            dp[i][prev_ind+1]=max(take,notTake);
        }

        return dp[i][prev_ind+1];
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,-1,arr,dp);
    }
};



//Tabulation
int longestIncreasingSubsequence(int arr[], int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = n-1;i>-1;--i){
        for(int prev_ind = i-1; prev_ind >= -1;--prev_ind){
            int len = dp[i+1][prev_ind+1];
            if(prev_ind == -1 || arr[i] > arr[prev_ind])
                len = max(len,dp[i+1][i+1]+1);
            dp[i][prev_ind+1] = len;
        }
    }
    return dp[0][0];
}

//Tabulation with space optimization
int longestIncreasingSubsequence(int arr[], int n){

    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);
    for(int i = n-1;i>-1;--i){
        for(int prev_ind = i-1; prev_ind >= -1;--prev_ind){
            int len = next[prev_ind+1];
            if(prev_ind == -1 || arr[i] > arr[prev_ind])
                len = max(len,next[i+1]+1);
            curr[prev_ind+1] = len;
        }
        next = curr;
    }
    return next[0];
}


//Brute Force
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> dp(n,1);
    int ans = 0;
    for(int i = 0;i<n;++i){
        for(int j = i-1;j>-1;--j){
            if(arr[j] < arr[i])
                dp[i] = max(dp[i],dp[j]+1);
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}


//Greedy + Binary Search

#include<bits/stdc++.h>
int binarySearch(vector<int> & arr,int x){
    int n = arr.size();
    int lo = 0;
    int hi = n-1;
    while(lo < hi){
        int mid = (lo+hi)>>1;
        if(arr[mid] >= x)
            hi = mid;
        else
            lo = mid+1;
    }
    return hi;
}
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> lis;
    for(int i = 0;i<n;++i){
        if(lis.empty() || lis.back() < arr[i])
            lis.push_back(arr[i]);
        else {
            int ind = binarySearch(lis,arr[i]);
            lis[ind] = arr[i];
        }
    }
    return lis.size();
}
