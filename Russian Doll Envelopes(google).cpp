class Solution {
public:
   static bool compare(vector<int>&a,vector<int>&b){
       if(a[0]==b[0]){
        return a[1]>b[1];
       }
       return a[0]<b[0];
   }
   
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),compare);
        vector<int>ans;
        for(auto it:envelopes){
            int idx = lower_bound(ans.begin(),ans.end(),it[1])-ans.begin();
             if(idx<ans.size()){
                ans[idx] = it[1];
             }
             else {
                ans.push_back(it[1]);
             }
        }
        return ans.size();
    }
};