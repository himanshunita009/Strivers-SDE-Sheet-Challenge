#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        fast;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        for(int i =1;i<n;++i)
            hash[i] = i;
        int ind = 0;
        for(int i =1;i<n;++i){
            for(int j = 0;j<i;++j){
                if(nums[i]%nums[j] == 0){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        hash[i] = j;
                    }
                }
            }
            if(dp[ind] < dp[i])
                ind = i;
        }
        vector<int> ans;
        while (hash[ind] != ind){
            ans.push_back(nums[ind]);
            ind = hash[ind];
        }
        ans.push_back(nums[ind]);
        return ans;

    }
};