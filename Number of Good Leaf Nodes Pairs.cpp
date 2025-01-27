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

   unordered_map<int,int>solve(TreeNode*root, int d, int&ans){
    unordered_map<int,int>parent;
    if(root==NULL){
        return parent;
    }
    if(root->left==NULL && root->right==NULL){
        parent[1] = 1;
        return parent;
    }

    unordered_map<int,int>left = solve(root->left,d,ans);
    unordered_map<int,int>right = solve(root->right,d,ans);
    for(auto[ld,lv]:left){
        for(auto[rd,rv]:right){
            if(ld+rd<=d) {
                ans += (lv*rv);
            }
        }
    }
    for(auto[ld,lv]:left){
        if(ld+1<d){
            parent[ld+1] += lv;
        }
    }
    for(auto[rd,rv]:right){
        if(rd+1<d){
            parent[rd+1] += rv;
        }
    }

    return parent;
   }

    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        solve(root,distance,ans);
        return ans;
    }
};