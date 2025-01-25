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
  
class AllInfo{
    public:
    bool isBST;
    int leftMin;
    int rightMax;
    int sum;
   AllInfo(){
    isBST = true;
    leftMin = INT_MAX;
    rightMax = INT_MIN;
    sum = 0;
   }

};

class Solution {
public:

    AllInfo solve(TreeNode* root,int& ans){
         AllInfo res;
            
        if(root==NULL){
            return res;
        }

        AllInfo left = solve(root->left,ans);
        AllInfo right = solve(root->right,ans);
        if(left.isBST && right.isBST && left.rightMax < root->val && right.leftMin > root->val){
          res.sum = left.sum + right.sum + root->val;
          ans = max(ans,res.sum);
          res.leftMin = min(root->val,left.leftMin);
          res.rightMax = max(root->val,right.rightMax);

        }else{
            res.isBST = false;
        }

        return res;
    }
    
   
    int maxSumBST(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = 0 ;
        solve(root,ans);
        return ans;
    }
};