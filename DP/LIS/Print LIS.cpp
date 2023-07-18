vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
    vector<int> dp(n,1);
    vector<int> hash(n);
    for(int i =0;i<n;++i)
        hash[i] = i;
    int ans = 0;
    for(int i = 0;i<n;++i){
        for(int j = i-1;j>-1;--j){
            if(arr[j] < arr[i]){
                if(dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
        }
        if(dp[ans] < dp[i])
            ans = i;
    }
    vector<int> res;
    while(hash[ans] != ans){
        res.push_back(arr[ans]);
        ans = hash[ans];
    }
    res.push_back(arr[ans]);
    reverse(res.begin(),res.end());
    return res;
}