class Solution {
public:
   bool checkValid(int& idx,vector<int>&v){
    if(idx==v.size()) return false;
    //cout<<idx<
    if(v[idx]==-1){
         idx++;
        return true;
    }
    idx++;
    return checkValid(idx,v)& checkValid(idx,v);
    
   }

    bool isValidSerialization(string preorder) {
        vector<int>v;
        string cur="";
        for(auto it:preorder){
           if(it==','){
              if(cur=="#" )v.push_back(-1);
              else v.push_back(stoi(cur));
              cur=""; 
           }else{
            cur+=it;
           }
        }
        if(cur=="#" )v.push_back(-1);
              else v.push_back(stoi(cur));
              int idx = 0;
             bool ans =  checkValid(idx,v);
             if(ans==true && v.size()==idx) return true;
             return false;
    }
};