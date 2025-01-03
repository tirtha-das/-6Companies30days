class Solution {
public:
    
   
static bool comparator(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] > b[1]; 
    }
    return a[0] < b[0]; 
}


    int maxEnvelopes(vector<vector<int>>& envelopes) {

       
        sort(envelopes.begin(),envelopes.end(),comparator);
       
        vector<int>sorted;


        for(auto it:envelopes){
           
            int idx = lower_bound(sorted.begin(),sorted.end(),it[1])-sorted.begin();
            if(idx == sorted.size()) sorted.push_back(it[1]);
            else{
                sorted[idx] = it[1];
            }
        }
        
        
        return sorted.size();
    }
};