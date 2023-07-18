class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int ans = 0;
        for(int i = 0;i<n;++i){
            for(int j = i-1;j>-1;--j){
                if(arr[j] < arr[i]){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }else if(dp[i] == dp[j]+1)
                        count[i] += count[j];
                }
            }
            if(dp[ans] < dp[i])
                ans = i;
        }
        int res = 0;
        for(int i =0;i<n;++i){
            if(dp[i] == dp[ans])
                res += count[i];
        }
        return res;
    }
};