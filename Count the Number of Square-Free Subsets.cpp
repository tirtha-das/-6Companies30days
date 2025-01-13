#define ll long long
const int MOD = 1e9+7;

class Solution {
public:
    ll solve(int idx, int taken, int allowed,vector<int>&nums,vector<int>&primes,vector<vector<vector<ll>>>&dp){
        if(idx==nums.size()){
            return (taken>0)?1:0;
        }

        if(dp[idx][taken][allowed]!=-1)return dp[idx][taken][allowed];

        ll notTake = solve(idx+1,taken,allowed,nums,primes,dp);
        ll take = 0;
        if(nums[idx]==1){
            take = solve(idx+1,1,allowed,nums,primes,dp);
        }else{
            int newAllowed = allowed;
            int check = 1;
            for(int i=0;i<primes.size();i++){
                if(nums[idx]<primes[i]){
                    break;
                }else if(nums[idx]%primes[i]==0){
                     int fail1 = primes[i]*primes[i];
                     int fail2 = allowed & (1<<i);
                    if(nums[idx]%(fail1)==0 || !fail2){
                        check = 0;
                        break;
                    }else {
                        newAllowed = newAllowed ^ (1<<i);
                    }
                }
            }
            if(check) take  = solve(idx+1,1,newAllowed,nums,primes,dp);
        }

       return dp[idx][taken][allowed] = (notTake+take)%MOD;
    }

    int squareFreeSubsets(vector<int>& nums) {
        int allowed = (1<<10)-1;
       vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
       vector<vector<vector<ll>>>dp(nums.size()+1,vector<vector<ll>>(2,vector<ll>(allowed+1,-1)));
        
        return (int)solve(0,0,allowed,nums,primes,dp);
        
    }
};