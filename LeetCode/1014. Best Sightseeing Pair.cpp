class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int n = a.size(), ans = -1e5;
        vector<int> b = a;
        for(int i = 1; i < n; i++){
            a[i] = max(a[i-1],a[i]+i);
        }
        b[n-1]-=(n-1);
        for(int i = n-2; i >= 0; i--){
            b[i] = max(b[i]-i,b[i+1]);
        }
        for(int i = 0; i < n-1; i++){
            ans = max(ans,a[i]+b[i+1]);
        }
        return ans;
    }
};
