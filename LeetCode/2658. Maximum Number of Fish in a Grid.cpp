class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int dfs(int x, int y, vector<vector<int>> &grid){
        if(x < 0 || y < 0 || x==grid.size() || y==grid[0].size() || grid[x][y]==0) return 0;
        int sum = grid[x][y];
        grid[x][y] = 0;
        for(int k = 0; k < 4; k++){
            sum+=dfs(x+dx[k],y+dy[k],grid);
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                ans = max(ans, dfs(i,j,grid));
            }
        }
        return ans;
    }
};
