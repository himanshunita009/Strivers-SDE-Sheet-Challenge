void setZeros(vector<vector<int>> &matrix){
    unordered_set<int> rows,cols;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i =0;i<n;++i){
        for(int j =0;j<m;++j){
            if(matrix[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    for(auto it : rows){
        for(int i =0;i<m;++i){
            matrix[it][i] = 0;
        }
    }
    for(auto it : cols){
        for(int i =0;i<n;++i){
            matrix[i][it] = 0;
        }
    }
}
