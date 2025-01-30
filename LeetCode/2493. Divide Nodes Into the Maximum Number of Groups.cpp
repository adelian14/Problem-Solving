class Solution {
public:
    bool valid(auto &g, int n){
        vector<int> color(n+1);
        for(int i = 1; i <= n; i++){
            if(color[i]) continue;
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto x : g[node]){
                    if(!color[x]){
                        color[x] = color[node]+1;
                        q.push(x);
                    }
                    else{
                        if(abs(color[x]-color[node])!=1) return 0;
                    }
                }
            }
        }
        return 1;
    }
    int solve(int root, int idx, auto& g, auto &comp, auto &vis){
        int ans = 0;
        queue<pair<int,int>> q;
        q.push({root, 1});
        vis[root]=1;
        while(!q.empty()){
            auto [node, dis] = q.front();
            q.pop();
            ans = max(ans,dis);
            for(auto x : g[node]){
                if(!vis[x]){
                    q.push({x,dis+1});
                    vis[x]=1;
                    comp[x]=idx;
                }
            }
        }
        return ans;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n+1);
        vector<int> maxGroup(n+1), comp(n+1);
        int componentIndex = 1;
        for(auto &v : edges){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        if(!valid(g, n)) return -1;
        for(int i = 1; i <= n; i++){
            if(comp[i]==0){
                comp[i] = componentIndex++;
            }
            vector<bool> vis(n+1);
            maxGroup[comp[i]] = max(maxGroup[comp[i]], solve(i, comp[i], g, comp, vis));
        }
        int ans = 0;
        for(auto x : maxGroup) ans+=x;
        return ans;
    }
};
