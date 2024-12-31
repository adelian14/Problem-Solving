class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> p(n + 1), sum(n + 1);
        vector<vector<int>> dp1(n + 1, vector<int>(2)), dp2;
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] + nums[i];
        }
        for (int i = 1; i + k - 1 <= n; i++) {
            dp1[i][0] = p[i + k - 1] - p[i - 1];
            dp1[i][1] = i;
            sum[i] = dp1[i][0];
        }
        dp2 = dp1;
        for (int i = 1; i <= n; i++) {
            if (dp1[i][0] <= dp1[i - 1][0]) {
                dp1[i][0] = dp1[i - 1][0];
                dp1[i][1] = dp1[i - 1][1];
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            if (dp2[i][0] < dp2[i + 1][0]) {
                dp2[i][0] = dp2[i + 1][0];
                dp2[i][1] = dp2[i + 1][1];
            }
        }
        int mx = 0, s = 0;
        vector<int> ans(3);
        for (int i = k + 1; i + k <= n - k + 1; i++) {
            int l = i - k, r = i + k;
            s = dp1[l][0] + sum[i] + dp2[r][0];
            vector<int> t = {dp1[l][1]-1, i-1, dp2[r][1] -1};
            if(s > mx){
                mx = s;
                ans = t;
            }
            else if(s==mx){
                if(t < ans) ans = t;
            }
        }
        return ans;
    }
};
