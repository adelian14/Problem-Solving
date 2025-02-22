/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fill(TreeNode* root, vector<vector<int>> &vals){
        if(!root) return;
        root->val = vals[root->val][1];
        fill(root->left, vals);
        fill(root->right, vals);
    }
    int dfs(TreeNode* root, vector<vector<int>> &vals, int idx){
        if(idx==vals.size() || !root) return -1;
        if(vals[idx][0]==vals[root->val][0]+1){
            if(!root->left){
                root->left = new TreeNode(idx);
                int k = dfs(root->left, vals, idx+1);
                if(k!= -1 && vals[k][0]==vals[root->val][0]+1){
                    root->right = new TreeNode(k);
                    return dfs(root->right, vals, k+1);
                }
                else return k;
            }
            else{
                root->right = new TreeNode(idx);
                return dfs(root->right, vals, idx+1);
            }
            
        }
        else{
            return idx;
        }
    }
    TreeNode* recoverFromPreorder(string traversal) {
        vector<vector<int>> vals(1, vector<int>(2));
        int cnt = 0;
        for(auto x : traversal){
            if(x=='-'){
                if(vals.back()[1]) vals.push_back(vector<int>(2));
                vals.back()[0]++;
            }
            else{
                vals.back()[1] = vals.back()[1]*10+x-'0';
            }
        }
        TreeNode* root = new TreeNode(0);
        dfs(root, vals, 1);
        fill(root, vals);
        return root;
    }
};
