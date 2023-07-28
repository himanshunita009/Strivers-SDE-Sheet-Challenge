class Solution {
public:
    bool isPlaindrom(int start,int end,string & str){
        while (start < end){
            if(str[start] != str[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }

    int solve(int start,int n,string & str,vector<int> & dp){
        if(start == n )
            return 0;
        if(dp[start] != -1)
            return dp[start];
        int ans = INT_MAX;
        for(int k = start;k<n;++k){
            if(isPlaindrom(start,k,str)){
                int temp = 1 + solve(k+1,n,str,dp);
                ans = min(ans,temp);
            }
        }
        return dp[start] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(0,n,s,dp)-1;
    }
};