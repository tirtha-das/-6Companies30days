class Solution {
public:
   int solve(int idx, int transaction,vector<int>&prices,vector<vector<int>>&dp){
    if(transaction == 0  || idx==prices.size()){
        return 0;
    }
    if(dp[idx][transaction]!=-1) return dp[idx][transaction];
    int notTake = solve(idx+1,transaction,prices,dp);
    int take = solve(idx+1,transaction-1,prices,dp);
    if(transaction%2==0){
        take -= prices[idx];
    }else {
         take += prices[idx];
    }

    return dp[idx][transaction] = max(notTake,take);
   }

    int maxProfit(int k, vector<int>& prices) {
        int count = k*2;
        int n = prices.size();
        vector<int>cur(count+1,0),next(count+1,0);

        for(int idx=n-1;idx>=0;idx--){
            for(int transaction =1;transaction<=k*2;transaction++){
                int notTake = next[transaction];
                int take = next[transaction-1];
                 if(transaction%2==0){
                     take -= prices[idx];
                 }else {
                      take += prices[idx];
                 }

                  cur[transaction] = max(notTake,take);
            }
            next = cur;
        }

        return next[count];
    }
};