class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> intervals = {1,7,30};
        vector<vector<int>> dp(n,vector<int>(3,1e9));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                int idx = -1;
                for(int k = i; k >= 0; k--){
                    if(days[i]-days[k] >= intervals[j]){
                        idx = k;
                        break;
                    }
                }
                if(idx==-1){
                    dp[i][j] = costs[j];
                    continue;
                }
                for(int k = 0; k < 3; k++){
                    dp[i][j] = min(dp[i][j],dp[idx][k]+costs[j]);
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};
