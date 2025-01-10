/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){return "";}
        queue<TreeNode*> pn;
        pn.push(root);
        string serial = to_string(root->val);
        serial += ',';

        while(pn.size()>0){
            TreeNode* cur = pn.front();
            pn.pop();
            if(cur->left!=NULL){
              serial += to_string(cur->left->val);
              pn.push(cur->left);
            }
            else{
             serial += "#";
            }
            serial += ",";
            
             if(cur->right!=NULL){
              serial += to_string(cur->right->val);
              pn.push(cur->right);
            }
            else{
             serial += "#";
            }
            serial += ",";

        }

        cout<<serial<<endl;
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        queue<TreeNode*> pn;
        int i=0;
        string cur = "";
        while(data[i]!=','){
           cur+=data[i];
           i++;
        }
        i++;
        TreeNode* root= new TreeNode(stoi(cur));
        pn.push(root);
       
       while(pn.size()>0){
          TreeNode* cur = pn.front();
          pn.pop();
          string left = "";
          while(data[i]!=','){
            left+=data[i];
            i++;
          }
          i++;
          if(left!="#"){
            TreeNode* node = new TreeNode(stoi(left));
            cur->left = node;
            pn.push(node);
          }

          string right = "";
          while(data[i]!=','){
            right+=data[i];
            i++;
          }
          i++;
          if(right!="#"){
            TreeNode* node = new TreeNode(stoi(right));
            cur->right = node;
            pn.push(node);
          }
       }

       return root;


        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));