class Solution {
public:
    const int mod = 1e9+7;
    int add(long long a, long long b){
        long long ans = (a+b)%mod;
        return ans;
    }
    int mul(long long a, long long b){
        long long ans = (a*b)%mod;
        return ans;
    }
    int numWays(vector<string>& w, string t) {
        int n = w.size(), m = w[0].size(), k = t.size();
        vector<vector<int>> dp(m, vector<int> (k));
        for(int j = 0; j < m; j++){
            vector<int> f(26);
            for(int i = 0; i < n; i++){
                f[w[i][j]-'a']++;
            }
            for(int i = 0; i < min(k,j+1); i++){
                dp[j][i] = f[t[i]-'a'];
            }
        }
        for(int i = 1; i < m; i++) dp[i][0]=add(dp[i][0],dp[i-1][0]);
        for(int j = 1; j < k; j++){
            for(int i = 1; i < m; i++){
                dp[i][j] = add(dp[i-1][j],mul(dp[i][j],dp[i-1][j-1]));
            }
        }
        return dp[m-1][k-1];
    }
};
