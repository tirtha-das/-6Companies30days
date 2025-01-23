const int MOD = 1e9+7;

class Solution {
public:
    long long solve(int effect,int k,int startPos,int endPos,unordered_map<int,unordered_map<int,int>>&dp){
        if(k==0){
            if(startPos+effect==endPos) return 1;
            return 0;
        }

        if(dp.find(effect)!=dp.end()){
            if(dp[effect].find(k)!=dp[effect].end()){
               return dp[effect][k];
            }
           
        }

        long long left = solve(effect-1,k-1,startPos,endPos,dp);
        long long right = solve(effect+1,k-1,startPos,endPos,dp);

        return dp[effect][k]  = (left+right)%MOD;


    }
   
    int numberOfWays(int startPos, int endPos, int k) {
        if(abs(startPos-endPos)>k) return 0;
        unordered_map<int,unordered_map<int,int>>dp;
        return (int)solve(0,k,startPos,endPos,dp);
    }
};