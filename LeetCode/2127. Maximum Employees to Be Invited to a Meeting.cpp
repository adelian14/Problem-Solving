class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size(), ans = 0, ans2 = 0;
        vector<int> in(n),distance(n,1);
        for(int i = 0; i < n; i++) in[favorite[i]]++;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!in[i]) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            int dis = distance[node];
            q.pop();
            int next = favorite[node];
            distance[next]=max(distance[next],dis+1);
            in[next]--;
            if(in[next]==0){
                q.push(next);
            }
        }
        for(int i = 0; i < n; i++){
            int curr = i, sum = 0;
            while(in[curr]){
                in[curr] = 0;
                curr = favorite[curr];
                sum++;
            }
            if(sum==2){
                ans2 += distance[i] + distance[favorite[i]];
            }
            else{
                ans = max(ans,sum);
            }
        }
        return max(ans,ans2);
    }
};
