class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size(), ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m));
        priority_queue<vector<int>> q;
        for(int i = 0; i < n; i++){
            q.push({-heightMap[i][0],i,0});
            q.push({-heightMap[i][m-1],i,m-1});
            vis[i][0]=vis[i][m-1]=1;
        }
        for(int i = 0; i < m; i++){
            q.push({-heightMap[0][i],0,i});
            q.push({-heightMap[n-1][i],n-1,i});
            vis[0][i]=vis[n-1][i]=1;
        }
        while(!q.empty()){
            auto v = q.top();
            q.pop();
            int x = v[1], y = v[2];
            for(int k = 0; k < 4; k++){
                int i = x+dx[k], j = y+dy[k];
                if(i < 0 || i==n || j < 0 || j==m || vis[i][j]) continue;
                if(heightMap[i][j] < heightMap[x][y]){
                    ans+=(heightMap[x][y]-heightMap[i][j]);
                    heightMap[i][j]=heightMap[x][y];
                }
                vis[i][j]=1;
                q.push({-heightMap[i][j], i, j});
            }
        }
        return ans;
    }
};
