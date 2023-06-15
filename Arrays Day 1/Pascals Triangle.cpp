#define ll long long
vector<ll> generateRow(int n){
    ll pro =1;
    int row = n-1;
    int col = 1;
    vector<ll> res;

    res.push_back(1);
    while (col < n){
        pro = (pro * row/col);
        ++col;
        --row;
        res.push_back(pro);
    }
    return res;
}
vector<vector<ll>> printPascal(int n) {
    vector<vector<ll>> ans;
    for(int i =1;i<=n;++i)
        ans.push_back(generateRow(i));
    return ans;
}