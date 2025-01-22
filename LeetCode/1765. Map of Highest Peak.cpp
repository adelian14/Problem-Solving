class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        queue<pair<int, int>> points;
        vector<vector<int>> height(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j]) 
                    points.push({i, j});
            }
        }
        while (!points.empty()) {
            int x = points.front().first;
            int y = points.front().second;
            points.pop();
            for (int k = 0; k < 4; k++) {
                int i = x + dx[k];
                int j = y + dy[k];
                if (i >= 0 && i < n && j >= 0 && j < m && !isWater[i][j] && !height[i][j]) {
                    height[i][j] = height[x][y] + 1;
                    points.push({i, j});
                }
            }
        }
        return height;
    }
};
