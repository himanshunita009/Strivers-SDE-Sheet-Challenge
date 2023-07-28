#include "bits/stdc++.h"
int matrixChainMultiplication(int* arr, int n) {
    ++n;
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    for(int i = 0;i<n;++i){
        dp[i][i] = 0;
    }
    for(int i = n-1;i>=1;--i){
        for(int j = i+1;j<n;++j){
            int ans = INT_MAX;
            for(int k = i;k<j;++k){
                int temp = dp[i][k]+dp[k+1][j]+ arr[i-1]*arr[k]*arr[j];
                ans = min(ans,temp);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][n-1];
}