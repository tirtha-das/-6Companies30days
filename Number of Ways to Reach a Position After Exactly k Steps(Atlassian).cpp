const int MOD = 1e9+7;

class Solution {
public:
    long long solve(int effect,int k,int startPos,int endPos,vector<unordered_map<int,int>>&dp){
        if(k==0){
            if(startPos+effect==endPos) return 1;
            return 0;
        }

        if(dp[k].find(effect)!=dp[k].end()){
           
               return dp[k][effect];
            
           
        }

        long long left = solve(effect-1,k-1,startPos,endPos,dp);
        long long right = solve(effect+1,k-1,startPos,endPos,dp);

        return dp[k][effect]  = (left+right)%MOD;


    }
   
    int numberOfWays(int startPos, int endPos, int k) {
        if(abs(startPos-endPos)>k) return 0;
        vector<unordered_map<int,int>>dp(k+1);
        return (int)solve(0,k,startPos,endPos,dp);
    }
};