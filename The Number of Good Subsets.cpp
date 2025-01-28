#define ll long long

const int MOD = 1e9+7;

class Solution {
public:
     ll solve(int idx,int allowed,vector<int>&nums,vector<int>&onPrimes,vector<vector<ll>>&dp){
        if(idx == nums.size()){
            int range = (1<<10)-1;
            if(allowed<range){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[idx][allowed]!=-1) return dp[idx][allowed];

        ll notTake = solve(idx+1,allowed,nums,onPrimes,dp);
        ll take = 0;
        if(nums[idx]==1){
            take = solve(idx+1,allowed,nums,onPrimes,dp);
        }else if(onPrimes[idx]>0 && (allowed&onPrimes[idx])==onPrimes[idx]){
            //cout<<nums[idx]<<" "<<allowed<<" "<<onPrimes[idx]<<" "<<(allowed&onPrimes[idx])<<endl;
          int newAllowed = allowed^onPrimes[idx];
        
        
          take = solve(idx+1,newAllowed,nums,onPrimes,dp); 
        }

        return dp[idx][allowed] = (notTake+take)%MOD;


     }


     long long getPower(int num, int p){
        if(p==0){
            return 1;
        }
        long long half = getPower(num,p/2);
        long long ans=1;
        if(p%2==1){
          ans = ((ans%MOD)*(num%MOD))%MOD;
        }

         ans = ((ans%MOD)*(half%MOD))%MOD;
          ans = ((ans%MOD)*(half%MOD))%MOD;
          return ans;
     }


    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int>primes = {2,3,5,7,11,13,17,19,23,29};

        unordered_map<int,int>mp;
        for(auto it:nums){
            if(it%4==0 || it%9==0 || it%25==0){
                continue;
            }else{
                mp[it]++;
            }
        }
        int range = (1<<10)-1;
        //vector<int>onPrimes;
        vector<pair<int,pair<int,int>>>filterd;
        for(auto[key,value]:mp){
            int cur = 0;
            if(key!=1){
            for(int j = 0;j<10;j++){
                if(key%primes[j]==0){
                    cur |= (1<<j);
                }
            }
            
          
            }
          
            filterd.push_back({key,{value,cur}});
           
        }
        sort(filterd.begin(),filterd.end());
       vector<ll>next(range+1,1),present(range+1);

        next[range] = 0;

         for(int idx = filterd.size()-1;idx>=0;idx--){
            for(int allowed = 0;allowed<=range;allowed++){
                ll notTake = next[allowed];
                ll take = 0;
               
                 if(filterd[idx].second.second>0 
                 && (allowed&filterd[idx].second.second)==filterd[idx].second.second){
                  int newAllowed = allowed^filterd[idx].second.second;
                  take = next[newAllowed]; 
                 // cour<<
                  take= take*(ll)filterd[idx].second.first;
                  take%=MOD;
                }

               present[allowed] = (notTake+take)%MOD;
            }
            next = present;
         }
         long long power = getPower(2,mp[1]);
         long long res = ((next[range]%MOD)*(power%MOD))%MOD;
 
        return (int)res;
    }
};