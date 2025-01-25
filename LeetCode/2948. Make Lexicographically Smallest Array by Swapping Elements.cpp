class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<vector<int>> p(n,vector<int>(2));
        vector<bool> added(n);
        for(int i = 0; i < n; i++){
            p[i][0] = nums[i];
            p[i][1] = i;
        }
        sort(p.begin(), p.end());
        for(int i = 0; i < n; i++){
            if(added[i]) continue;
            int left = 1e9, right = -1e9;
            queue<pair<int,int>> q;
            q.push({nums[i],0});
            while(!q.empty()){
                int val = q.front().first;
                int op = q.front().second;
                q.pop();
                int upper = val + limit, lower = val - limit, nl = val, np = val;
                int n_left = left, n_right = right;
                int l = 0, r = n-1;
                if(op <= 0){
                    while(l <= r){
                        int mid = (l+r)/2;
                        if(p[mid][0] > upper){
                            r = mid - 1; 
                        }
                        else if(p[mid][0] < lower){
                            l = mid + 1;
                        }
                        else{
                            r = mid - 1;
                            nl = p[mid][0];
                            n_left = min(n_left, mid);
                        }
                    }
                }
                if(op >= 0){
                    l = 0, r = n-1;
                    while(l <= r){
                        int mid = (l+r)/2;
                        if(p[mid][0] > upper){
                            r = mid - 1; 
                        }
                        else if(p[mid][0] < lower){
                            l = mid + 1;
                        }
                        else{
                            l = mid + 1;
                            np = p[mid][0];
                            n_right = max(n_right, mid);
                        }
                    }
                }
                if(n_left < left || n_right > right){
                    left = n_left;
                    right = n_right;
                    q.push({nl,-1});
                    q.push({np,1});
                }
            }
            vector<int> idx;
            for(int j = left; j <= right; j++){
                idx.push_back(p[j][1]);
            }
            sort(idx.begin(),idx.end());
            for(int j = left, k = 0; j <= right; j++, k++){
                nums[idx[k]] = p[j][0];
                added[idx[k]] = 1;
            }
        }
        return nums;
    }
};
