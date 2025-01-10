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
    int cal(TreeNode* root,unordered_map<int,TreeNode*>& parent){
      unordered_set<int>vis;
            queue<TreeNode*>pn;
            pn.push(root);

            vis.insert(root->val);
            int time = 0;

            while(pn.size()>0){
                int sz = pn.size();
                for(int i=0;i<sz;i++){
                 TreeNode* cur = pn.front();
                 pn.pop();
                 if(cur->left){
                    int val = cur->left->val;
                    if(vis.find(val)==vis.end()){
                        pn.push(cur->left);
                        vis.insert(val);
                    }
                 }
                 if(cur->right){
                    int val = cur->right->val;
                    if(vis.find(val)==vis.end()){
                        pn.push(cur->right);
                        vis.insert(val);
                    }
                 }

                 if(parent.find(cur->val)!=parent.end()){
                    TreeNode* p = parent[cur->val];
                    if(vis.find(p->val)==vis.end()){
                        pn.push(p);
                        vis.insert(p->val);
                    }
                 }
                }
                if(pn.size()>0) {time++;}
                
            }
            
          
       return time;
    }
    
    int helper(TreeNode* root, int start, unordered_map<int,TreeNode*>& parent){
        if(root==NULL){
            return INT_MAX;
        }

        if(root->val==start){
           return cal(root,parent);

        }else{
            int ans = INT_MAX;
            if(root->left){
                parent[root->left->val] = root;
                ans = min(ans,helper(root->left,start,parent));
            }
             if(root->right){
                parent[root->right->val] = root;
                ans = min(ans,helper(root->right,start,parent));
            }

            return ans;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,TreeNode*> parent;

        return helper(root,start,parent);
    }
};