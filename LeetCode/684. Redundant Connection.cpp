class Solution {
public:
    void dfs(int node, auto &g, auto &vis){
        if(vis[node]) return;
        vis[node] = 1;
        for(auto x : g[node]){
            dfs(x,g,vis);
        }
    }
    bool solve(vector<vector<int>> &edges, int k, int n){
        vector<vector<int>> g(n+1);
        vector<bool> vis(n+1);
        for(int i = 0; i < n; i++){
            if(i!=k){
                g[edges[i][0]].push_back(edges[i][1]);
                g[edges[i][1]].push_back(edges[i][0]);
            }
        }
        dfs(1,g,vis);
        for(int i = 1; i <= n; i++) if(!vis[i]) return 0;
        return 1;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = n-1; i >= 0; i--){
            if(solve(edges, i, n)) return edges[i];
        }
        return {};
    }
};
