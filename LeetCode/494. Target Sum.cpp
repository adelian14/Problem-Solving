class Solution {
public:
    int solve(vector<int>& a, int i, int sum, int& target){
        if(i==a.size()) return sum==target;
        return solve(a, i + 1, sum + a[i], target) + solve(a, i + 1, sum - a[i], target); 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,0,0,target);
    }
};
