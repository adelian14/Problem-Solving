class Solution {
public:
    void dfs(int node, auto &pre, auto &g, auto &in){
        in[node] = -1;
        pre[node][node] = 1;
        for(auto x : g[node]){
            for(int i = 0; i < pre[0].size(); i++){
                pre[i][x] = (pre[i][x] || pre[i][node]);
            }
            in[x]--;
            if(!in[x]) dfs(x, pre, g, in);
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> in(n);
        vector<bool> ans(m);
        vector<vector<int>> g(n);
        vector<vector<bool>> pre(n,vector<bool>(n));
        for(auto v : prerequisites){
            g[v[0]].push_back(v[1]);
            in[v[1]]++;
        }
        for(int i = 0; i < n; i++){
            if(in[i]) continue;
            dfs(i, pre, g, in);
        }
        for(int i = 0; i < m; i++){
            ans[i] = pre[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
};
