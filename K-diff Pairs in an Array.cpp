class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>seen;

        for(auto it:nums){
           
                seen[it]++;
            
        }
        int ans = 0;
        for(auto it=seen.begin();it!=seen.end();it++){
            int cur = it->first;
            int cnt = it->second;
            if(k==0 && cnt>1) ans++;

            else if(k>0 && seen.find(cur+k)!=seen.end()) ans++;
        }

        return ans;
    }
};