class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < m; j++){
                sum+=grid[i][j];
            }
            if(sum > 1){
                ans+=sum;
                for(int j = 0; j < m; j++){
                    grid[i][j]*=2;
                }
            }
        }
        for(int i = 0; i < m; i++){
            int sum = 0, cnt = 0;
            for(int j = 0; j < n; j++){
                if(grid[j][i]==2) cnt++;
                else if(grid[j][i]==1) cnt++,sum++;
            }
            if(cnt > 1) ans+=sum;
        }
        return ans;
    }
};
