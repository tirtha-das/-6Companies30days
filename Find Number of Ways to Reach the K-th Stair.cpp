class Solution {
public:
   int findWays(long long start , int end, int jump, int isBackAllow,unordered_map<string,int>&dp){
     if(start >end+1) return 0;

     string curState = to_string(start)+","+to_string(jump)+","+to_string(isBackAllow);
     if(dp.find(curState)!=dp.end()) return dp[curState];

      int forward = findWays(start+(1<<jump),end,jump+1,1,dp);
      int backward = 0;

      if(isBackAllow && start>0) backward = findWays(start-1,end,jump,0,dp);

      int ans = forward+backward;

      if(start==end) ans++;
      return dp[curState] = ans;

   }
  
    int waysToReachStair(int k) {
        unordered_map<string,int>dp;
        return findWays(1,k,0,1,dp);
    }
};