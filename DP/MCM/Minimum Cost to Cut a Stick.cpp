class Solution {
public:
    int solve(int start,int end,vector<int> & nums,vector<vector<int>> & dp){
        if(start > end)
            return 0;
        if(dp[start][end] == -1){
            int ans = INT_MAX;
            for(int k = start;k<=end;++k){
                int tempCost = nums[end+1] - nums[start-1] + solve(start,k-1,nums,dp) + solve(k+1,end,nums,dp);
                ans = min(ans,tempCost);
            }
            dp[start][end] = ans;
        }

        return dp[start][end];
    }
    int minCost(int n, vector<int>& nums) {
        int c = nums.size();
        nums.insert(nums.begin(),0);
        nums.push_back(n);
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        for(int i = c;i>=1;--i){
            for(int j = 1;j<=c;++j){
                if(i > j) continue;
                int ans = INT_MAX;
                for(int k = i;k<=j;++k){
                    int tempCost = nums[j+1] - nums[i-1] + dp[i][k-1]+dp[k+1][j];
                    ans = min(ans,tempCost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][c];
    }
};