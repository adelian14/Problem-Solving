class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev_graph(n);
        vector<int> in(n), safe;
        queue<int> q;
        for(int i = 0; i < n; i++){
            in[i] = graph[i].size();
            if(!in[i]){
                q.push(i);
                safe.push_back(i);
            }
            for(auto x : graph[i]){
                rev_graph[x].push_back(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x : rev_graph[node]){
                in[x]--;
                if(in[x]==0){
                    q.push(x);
                    safe.push_back(x);
                }
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};
