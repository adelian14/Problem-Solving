class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n),p(n+1);
        for(int i = 0; i < n; i++){
            p[A[i]]++;
            p[B[i]]++;
            if(A[i]==B[i]){
                C[i]++;
            }
            else{
                if(p[A[i]]==2) C[i]++;
                if(p[B[i]]==2) C[i]++;
            }
            if(i) C[i]+=C[i-1];
        }
        return C;
    }
};
