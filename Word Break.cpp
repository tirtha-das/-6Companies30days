

class Solution {
public:
    int solve(int idx,string& s, unordered_set<string>&present,vector<int>& dp){
        if(idx == s.size()){
            return 1;
        }
        if(dp[idx]!=-1) return dp[idx];
       
        string cur = "";
        for(int i=idx;i<s.size();i++){
            cur+=s[i];
            
            if(present.find(cur)!=present.end()){
               if(solve(i+1,s,present,dp)) return dp[idx] = 1;
            } 
        }

        return dp[idx] = 0;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
       unordered_set<string>present ; 
    
    for(auto it:wordDict){
        if(present.find(it)==present.end()){
            present.insert(it);
        }
    }

        vector<int>dp(s.size()+1,-1);
        dp[s.size()] = 1;
        
      for(int idx=s.size()-1;idx>=0;idx--){
       string cur = "";
        for(int i=idx;i<s.size();i++){
            cur+=s[i];
            
            if(present.find(cur)!=present.end()){
               if(dp[i+1]) {
                dp[idx] = 1;
                break;
               } 
            } 
        }

        dp[idx] = dp[idx]==-1?0:1;
      }

        return dp[0];
    }

};