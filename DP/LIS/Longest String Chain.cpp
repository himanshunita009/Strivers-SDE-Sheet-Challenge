#include <bits/stdc++.h>
bool cmp(string & str1,string & str2){
    return str1.size() < str2.size();
}
bool isValid(string & str1,string & str2){
    int n = str1.size();
    int m = str2.size();
    if(m-n != 1)
        return false;
    bool flag = true;
    int i = 0,j=0;
    while(j < m){
        if(str1[i] == str2[j]){
            ++i;
        }
        ++j;
    }
    return i == n && j == m;
}
int longestStrChain(vector<string>& words) {
    sort(words.begin(),words.end(),cmp);
    int n = words.size();
    vector<int> dp(n,1);
    int ans = 1;
    for(int i =1;i<n;++i){
        for(int j = 0;j<i;++j){
            if(isValid(words[j],words[i]) && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
            }
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}