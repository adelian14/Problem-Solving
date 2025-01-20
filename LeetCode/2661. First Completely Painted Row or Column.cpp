class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> a(n,m), b(m,n);
        vector<vector<int>> idx(n*m, vector<int>(2));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                idx[mat[i][j]-1][0] = i;
                idx[mat[i][j]-1][1] = j;
            }
        }
        for(int i = 0; i < n*m; i++){
            int x = idx[arr[i]-1][0];
            int y = idx[arr[i]-1][1];
            a[x]--, b[y]--;
            if(!a[x] || !b[y]) return i;
        }
        return NULL;
    }
};
