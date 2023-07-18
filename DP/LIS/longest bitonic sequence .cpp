int longestBitonicSequence(vector<int>& arr, int n) {
    int ans = 0;
    vector<int> dp1(n,1);
    vector<int> dp2(n,1);
    for(int i = 0;i<n;++i){
        for(int j = i-1;j>-1;--j){
            if(arr[j] < arr[i])
                dp1[i] = max(dp1[i],dp1[j]+1);
        }
    }
    for(int i = n-2;i>-1;--i){
        for(int j = i+1;j<n;++j){
            if(arr[i] > arr[j])
                dp2[i] = max(dp2[i],dp2[j]+1);
        }
    }
    for(int i =0;i<n;++i){
        ans = max(ans,dp1[i]+dp2[i]-1);
    }
    return ans;
}
