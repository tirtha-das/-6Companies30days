class Solution {
public:
    int solve(int idx,string& s, unordered_set<string>&present,vector<int>& dp){
        if(idx == s.size()){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int ans = INT_MAX;
        string cur = "";
        for(int i=idx;i<s.size();i++){
            cur+=s[i];
            int res = solve(i+1,s,present,dp);
            if(present.find(cur)==present.end()) res += cur.size();
            ans = min(ans,res); 
        }

        return dp[idx] = ans;

    }

    int minExtraChar(string s, vector<string>& dict) {
       unordered_set<string>present ; 
    
    for(auto it:dict){
        if(present.find(it)==present.end()){
            present.insert(it);
        }
    }

        vector<int>dp(s.size()+1,0);

        for(int idx = s.size()-1;idx>=0;idx--){
            int ans = INT_MAX;
            string cur = "";
            for(int i=idx;i<s.size();i++){
                cur+=s[i];
                int res = dp[i+1];
                if(present.find(cur)==present.end()) res += cur.size();
                ans = min(ans,res); 
            }

         dp[idx] = ans;     
        }

        return dp[0];
    }
};