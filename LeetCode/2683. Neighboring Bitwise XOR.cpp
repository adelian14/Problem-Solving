class Solution {
public:
    bool solve(vector<int> &a, int x){
        int curr = x, n = a.size();
        for(int i = 0; i < n; i++){
            if(i < n-1) curr = curr^a[i];
            else if((curr^x) != a[i]) return 0;
        }
        return 1;
    }
    bool doesValidArrayExist(vector<int>& derived) {
        return solve(derived, 0) || solve(derived, 1);
    }
};
