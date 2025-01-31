class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int solve(int x, int y, auto &grid, int &idx){
        if(max(x,y) == grid.size() || min(x,y) < 0 || grid[x][y]!=1) return 0;
        int ans = 1;
        grid[x][y]=idx;
        for(int k = 0; k < 4; k++){
            ans+=solve(x+dx[k],y+dy[k],grid,idx);
        }
        return ans;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> p(2);
        int idx = 2, ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]!=1) continue;
                p.push_back(solve(i,j,grid,idx));
                ans = max(ans,p[idx]);
                idx++;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) continue;
                set<int> s;
                int sum = 1;
                for(int k = 0; k < 4; k++){
                    int x = i+dx[k], y = j+dy[k];
                    if(max(x,y) == n || min(x,y) < 0) continue;
                    s.insert(grid[x][y]);
                }
                for(auto x : s) sum+=p[x];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
