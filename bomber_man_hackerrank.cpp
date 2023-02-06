void blastBomb(vector<string> grid, vector<string> &ans){
    int r = grid.size();
    int c = grid[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(grid[i][j] == 'O'){
                ans[i][j] = '.';
                if(i<r-1) ans[i+1][j] = '.';
                if(j<c-1) ans[i][j+1] = '.';
                if(i>=1) ans[i-1][j] = '.';
                if(j>=1) ans[i][j-1] = '.';
            }
        }
    }
}

vector<string> bomberMan(int n, vector<string> grid) {
    int r = grid.size();
    int c = grid[0].size();
    vector<string> ans(r, string(c,'O'));
    
    if(n == 1) return grid;
    
    if(n%2 == 0) return ans;
    
    if((n%4 == 3) || (n%4 == 1)){
        blastBomb(grid, ans);
        if(n%4 == 3) return ans;
        vector<string> temp(r, string(c,'O'));
        grid = ans;
        ans = temp;
        blastBomb(grid, ans);
    }
    return ans;
}
